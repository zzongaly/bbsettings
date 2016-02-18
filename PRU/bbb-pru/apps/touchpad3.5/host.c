#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sndfile.h>

#include <prussdrv.h>
#include <pruss_intc_mapping.h>

#define PRU_NUM 0

#ifndef START_ADDR
#error "START_ADDR must be defined"
#endif

/////////////////////////////////////////////////////////////////////
// Globals
//

unsigned int* shared_ram = NULL;
pthread_t thread;
int finish = 0;
SNDFILE* sound_file;
unsigned int buffer[0xFFFFFF]; // 16MB
unsigned int buffer_count=0;


/////////////////////////////////////////////////////////////////////

void load_device_tree_overlay(){
	// Check if device tree overlay is loaded, load if needed.
	int device_tree_overlay_loaded = 0; 
	FILE* f;
	f = fopen("/sys/devices/bone_capemgr.9/slots","rt");
	if(f==NULL){
		printf("Initialisation failed (fopen rt)");
		exit(1);
	}
	char line[256];
	while(fgets(line, 256, f) != NULL){
		if(strstr(line, "PRU-DTO") != NULL){
			device_tree_overlay_loaded = 1; 
		}
	}
	fclose(f);

	if(!device_tree_overlay_loaded){
		f = fopen("/sys/devices/bone_capemgr.9/slots","w");
		if(f==NULL){
			printf("Initialisation failed (fopen)");
			exit(1);
		}
		fprintf(f, "PRU-DTO");
		fclose(f);
		usleep(100000);
	}
}

void init_pru_program(){
	tpruss_intc_initdata pruss_intc_initdata = PRUSS_INTC_INITDATA;
	prussdrv_init();
	prussdrv_open(PRU_EVTOUT_0);
	prussdrv_pruintc_init(&pruss_intc_initdata);

	// Get pointer to shared ram
	void* p;
	prussdrv_map_prumem(PRUSS0_SHARED_DATARAM, &p);
	shared_ram = (unsigned int*)p;

	prussdrv_load_datafile(PRU_NUM, "./data.bin");
	prussdrv_exec_program_at(PRU_NUM, "./text.bin", START_ADDR);
}

void signal_handler(int signal){
	finish = 1;
}

void* threaded_function(void* param){
	printf("Started thread\n");
	int i = 0;
	int print_id = -1;
	int channel_id = -1;
	int sample = 0;

	unsigned int data[10];

	while(1){
		// Wait for interrupt from PRU
		prussdrv_pru_wait_event(PRU_EVTOUT_0);
		prussdrv_pru_clear_event(PRU_EVTOUT_0, PRU0_ARM_INTERRUPT);

		print_id = shared_ram[0];
		channel_id = shared_ram[100 + print_id * 10];
		sample = shared_ram[200 + print_id * 10];

		data[channel_id] = sample;

		printf("\n");
		for(i = 0; i < 6; i++)
			printf("%d:%u\t", i, data[i]);
	}
	return NULL;
}

void start_thread(){
	// TODO: set real time priority to this thread
	pthread_attr_t attr;
	if(pthread_attr_init(&attr)){
		printf("Cannot start a new thread.\n");
		exit(1);
	}
	if(pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED)){
		printf("Cannot start a new thread.");
		exit(1);
	}
	if(pthread_create(&thread, &attr, &threaded_function, NULL)){
		printf("Cannot start a new thread.");
		exit(1);
	}
}

void stop_thread(){
	while(pthread_cancel(thread)){
		printf("Stopping thread\n");
	}
	printf("Stopped thread\n");
}

void open_sound_file(){
	SF_INFO info;
	info.samplerate = 50000;
	info.channels = 6;
	info.format = SF_FORMAT_WAV | SF_FORMAT_FLOAT;
	if(!sf_format_check(&info)){
		printf("Invalid soundfile format\n");
		exit(1);
	}

	if(! (sound_file = sf_open("./out.wav", SFM_WRITE, &info)) ){
		printf("Could not open soundfile\n");
		exit(1);
	}
}

void close_sound_file(){
	unsigned int i;
	float samples[6];
	printf("Final buffer_count: %u \n", buffer_count);
	for(i=0; i<buffer_count; i=i+6){
		samples[0] = ( (float)buffer[i]/(float)0x7ff ) - 1;
		samples[1] = ( (float)buffer[i+1]/(float)0x7ff ) - 1;
		samples[2] = ( (float)buffer[i+2]/(float)0x7ff ) - 1;
		samples[3] = ( (float)buffer[i+3]/(float)0x7ff ) - 1;
		samples[4] = ( (float)buffer[i+4]/(float)0x7ff ) - 1;
		samples[5] = ( (float)buffer[i+5]/(float)0x7ff ) - 1;
		if(6!=sf_write_float(sound_file, samples, 6)){
			printf("%s \n", sf_strerror(sound_file));
			break;
		}
	}
	sf_close(sound_file);
}

int main(int argc, const char *argv[]){
	printf("\n\n");

	// Listen to SIGINT signals (program termination)
	signal(SIGINT, signal_handler);


	// Load device tree overlay to enable PRU hardware.
	load_device_tree_overlay();

	// Load and run binary into pru0
	init_pru_program();

	open_sound_file();

	/* sleep(1); */
	start_thread();

	while(!finish){}
	//sleep(500);

	prussdrv_pru_disable(PRU_NUM);
	prussdrv_exit ();
	stop_thread();

	close_sound_file();

	// Calculate sample rate
	/* int i; */
	/* unsigned long sum = 0; */
	/* for(i=0; i<times_count; i++){ */
	/*	 sum += times[i]; */
	/* } */
	/* float avg = (float)sum / (float)times_count; */
	/* printf("Freq: %f \n", 128.0*1000000.0/avg); */

	return 0;
}
