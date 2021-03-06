// Macro for accessing a hardware register (32 bit)
#define HWREG(x) (*((volatile unsigned int *)(x)))
#define GPIO0 0x44e07000
#define GPIO1 0x4804c000
#define DELAY 10000

#define block_size 128
#define channels 2

#define SYSCFG 0x26004

#define GPIO0_DATAOUT 0x44e0713c
#define GPIO0_OE 0x44e07134
#define GPIO0_CTRL 0x44e07130

#define GPIO1_DATAOUT 0x4804c13c
#define GPIO1_OE 0x4804c134
#define GPIO1_CTRL 0x4804c130

#define GPIO2_DATAOUT 0x481ac13c
#define GPIO2_OE 0x481ac134
#define GPIO2_CTRL 0x481ac130

#define GPIO3_DATAOUT 0x481ae13c
#define GPIO3_OE 0x481ae134
#define GPIO3_CTRL 0x481ae130

#define P9_12 0x4804c878 //GPIO1_28
#define P9_14 0x4804c874 //GPIO1_18

#define P8_33 0x44e078d4 //GPIO0_9
#define P8_35 0x44e078d0 //GPIO0_8

#define P8_24 0x44e10804 //GPIO1_1
#define P8_25 0x44e10800 //GPIO1_0

#define P8_15 0x4804c83c //GPIO1_15
#define P8_16 0x4804c838 //GPIO1_14

/*
#define HORIZONTAL_PIN P9_12
#define VERTICAL_PIN P9_14
#define HORIZONTAL_OUT 28
#define VERTICAL_OUT 18
#define GPIO_DATAOUT GPIO1_DATAOUT
*/

/*
#define HORIZONTAL_PIN P8_33
#define VERTICAL_PIN P8_35
#define HORIZONTAL_OUT 9
#define VERTICAL_OUT 8
#define GPIO_DATAOUT GPIO0_DATAOUT
*/

#define HORIZONTAL_PIN P8_15
#define VERTICAL_PIN P8_16
#define HORIZONTAL_OUT 15
#define VERTICAL_OUT 14
#define GPIO_DATAOUT GPIO1_DATAOUT

#define FIFO0_COUNT 0x44e0d0e4
#define FIFO0_DATAOUT 0x44e0d100
#define FIFO1_COUNT 0x44e0d0f0
#define FIFO1_DATAOUT 0x44e0d200

volatile register unsigned int __R31;
volatile unsigned int* shared_ram;
volatile unsigned int* buffer;

void init_digital();
void init_adc();

int main(int argc, const char *argv[]){

	shared_ram = (volatile unsigned int *)0x10000;
	buffer = &(shared_ram[100]); 	// We'll start putting samples in shared ram 
					// address 100 and use up to 6KB = 4 bytes 
					// (size of unsigned int) * block_size * 
					// num_channels * 2 buffers; 
	unsigned int finish = 0;
	unsigned int i;
	unsigned int fifo0_count;
	unsigned int fifo1_count;
	unsigned int data;
	unsigned int buffer_count = 0;
	unsigned int sample; 
	unsigned int which_buffer = 0; 	// We'll alternate the memory positions 
					// where we put samples in so that the 
					// arm cpu can read one of them while we 
					// fill the other one.

	init_digital();
	init_adc();


	while(!finish){
		HWREG(GPIO_DATAOUT) |= (1 << HORIZONTAL_OUT);
		HWREG(GPIO_DATAOUT) &= ~(1 << VERTICAL_OUT);
		for(i=0;i<DELAY;i++);

		__R31 = 0;

		// FIFO0 : adc0
		fifo0_count = HWREG(FIFO0_COUNT);
		for(i=0; i<fifo0_count; i++){
			data = HWREG(FIFO0_DATAOUT);
			sample = data & 0xfff; 
			buffer[(which_buffer*block_size*channels) + buffer_count] = sample;
			buffer_count ++;
		} 

		if(buffer_count >= block_size*channels){
			// put number of available samples (block size) in position 0,
			// address of buffer in position 1 and IRQ
			shared_ram[0] = 100+(which_buffer * block_size * channels);
			shared_ram[1] = buffer_count;
			shared_ram[2] = which_buffer;
			shared_ram[3] = fifo0_count;
			__R31 = 35;
			buffer_count = 0;
			which_buffer = !which_buffer;
		}

		HWREG(GPIO_DATAOUT) &= ~(1<<HORIZONTAL_OUT);
		HWREG(GPIO_DATAOUT) |= (1<<VERTICAL_OUT);
		for(i=0;i<DELAY;i++);

		// FIFO1 : adc1
		fifo1_count = HWREG(FIFO1_COUNT);
		for(i=0; i<fifo1_count; i++){
			 data = HWREG(FIFO1_DATAOUT);
			 sample = data & 0xfff; 
			 buffer[(which_buffer*block_size*channels) + buffer_count] = sample;
			 buffer_count ++;
		} 

		if(buffer_count >= block_size*channels){
			// put number of available samples (block size) in position 0,
			// address of buffer in position 1 and IRQ
			shared_ram[0] = 100+(which_buffer * block_size * channels);
			shared_ram[2] = which_buffer;
			shared_ram[1] = buffer_count;
			shared_ram[3] = fifo1_count;
			__R31 = 35;
			buffer_count = 0;
			which_buffer = !which_buffer;
		}
	}

	// stop pru processing
	__halt();

	return 0;
}

void init_digital(){
	// Enable OCP so we can access the whole memory map for the
	// device from the PRU. Clear bit 4 of SYSCFG register
	HWREG(SYSCFG) &= 0xFFFFFFEF;

	// Enable GPIO0 Module.
	HWREG(GPIO0_OE) = 0x00;
	HWREG(GPIO0_CTRL) = 0x00;

	// Enable GPIO1 Module.
	HWREG(GPIO1_OE) = 0x00;
	HWREG(GPIO1_CTRL) = 0x00;

	// Enable GPIO2 Module.
	HWREG(GPIO2_OE) = 0x00;
	HWREG(GPIO2_CTRL) = 0x00;

	// pin as an output, with no pullup/pulldown
	HWREG(HORIZONTAL_PIN) = 0x0f;
	HWREG(VERTICAL_PIN) = 0x0f;

	// GPIO1[21] (User led 0) as an output
	HWREG(0x44e10854) = 0x0f;
}



void init_adc(){
	// Enable OCP so we can access the whole memory map for the
	// device from the PRU. Clear bit 4 of SYSCFG register
	HWREG(0x26004) &= 0xFFFFFFEF;

	// Enable clock for adc module. CM_WKUP_ADC_TSK_CLKCTL register
	HWREG(0x44e004bc) = 0x02;

	// Disable ADC module temporarily. ADC_CTRL register
	HWREG(0x44e0d040) &= ~(0x01);

	// To calculate sample rate:
	// fs = 24MHz / (CLK_DIV*2*Channels*(OpenDly+Average*(14+SampleDly)))
	// We want 48KHz. (Compromising to 50KHz)
	unsigned int clock_divider = 4;
	unsigned int open_delay = 4;
	unsigned int average = 1;	// can be 0 (no average), 1 (2 samples), 
					// 2 (4 samples),	3 (8 samples) 
					// or 4 (16 samples)
	unsigned int sample_delay = 4;

	// Set clock divider (set register to desired value minus one). 
	// ADC_CLKDIV register
	HWREG(0x44e0d04c) = clock_divider - 1;

	// Set values range from 0 to FFF. ADCRANGE register
	HWREG(0x44e0d048) = (0xfff << 16) & (0x000);

	// Disable all steps. STEPENABLE register
	HWREG(0x44e0d054) &= ~(0xff);

	// Unlock step config register. ACD_CTRL register
	HWREG(0x44e0d040) |= (0x01 << 2);

	// Set config for step 1. sw mode, one-shot mode, 
	// use fifo0, use channel 0. STEPCONFIG1 register
	HWREG(0x44e0d064) = 0x0000 | (0x0<<26) | (0x00<<19) | (0x00<<15) | (average<<2) | (0x01);

	// Set delays for step 1. STEPDELAY1 register
	HWREG(0x44e0d068) = 0x0000 | (sample_delay - 1)<<24 | open_delay;

	// Set config for step 2. sw mode, one-shot mode, 
	// use fifo1, use channel 1. STEPCONFIG2 register
	HWREG(0x44e0d06c) = 0x0000 | (0x1<<26) | (0x01<<19) | (0x01<<15) | (average<<2) | (0x01);

	// Set delays for step 2. STEPDELAY2 register
	HWREG(0x44e0d070) = 0x0000 | (sample_delay - 1)<<24 | open_delay;

	// Set config for step 3. sw mode, continuous mode, 
	// use fifo0, use channel 2. STEPCONFIG3 register
	// HWREG(0x44e0d074) = 0x0000 | (0x0<<26) | (0x02<<19) | (0x02<<15) | (average<<2) | (0x01);

	// Set delays for step 3. STEPDELAY3 register
	// HWREG(0x44e0d078) = 0x0000 | ((sample_delay - 1)<<24) | open_delay;

	// Set config for step 4. sw mode, continuous mode, 
	// use fifo1, use channel 3. STEPCONFIG4 register
	/* HWREG(0x44e0d07c) = 0x0000 | (0x0<<26) | (0x03<<19) | (0x03<<15) | (average<<2) | (0x01); */

	// Set delays for step 4. STEPDELAY4 register
	/* HWREG(0x44e0d080) = 0x0000 | ((sample_delay - 1)<<24) | open_delay; */


	// Set config for step 5. sw mode, continuous mode, 
	// use fifo1, use channel 4. STEPCONFIG5 register
	/* HWREG(0x44e0d084) = 0x0000	| (0x0<<26) | (0x04<<19) | (0x04<<15) | (average<<2) | (0x01); */

	// Set delays for step 5. STEPDELAY5 register
	/* HWREG(0x44e0d088) = 0x0000 | ((sample_delay - 1)<<24) | open_delay; */

	// Set config for step 6. sw mode, continuous mode, 
	// use fifo1, use channel 5. STEPCONFIG6 register
	/* HWREG(0x44e0d08c) = 0x0000 | (0x0<<26) | (0x05<<19) | (0x05<<15) | (average<<2) | (0x01); */

	// Set delays for step 6. STEPDELAY6 register
	/* HWREG(0x44e0d090) = 0x0000 | ((sample_delay - 1)<<24) | open_delay; */

	/* // Set config for step 7. Average 16, sw mode, continuous mode,	*/
	/* // use fifo0, use channel 6. STEPCONFIG7 register */
	/* HWREG(0x44e0d094) |= ((0x0<<26) | (0x06<<19) | (0x06<<15) | (0x04<<2) | (0x01)); */

	/* // Set delays for step 7. STEPDELAY7 register */
	/* HWREG(0x44e0d098) = 0x0000 | ((sample_delay - 1)<<24) | open_delay; */

	// Lock step config register. ADC_CTRL register
	HWREG(0x44e0d040) &= ~(0x01 << 2);
	
	// Clear FIFO0 by reading from it. FIFO0COUNT, FIFO0DATA registers
	unsigned int count = HWREG(0x44e0d0e4);
	unsigned int data, i;
	for(i=0; i<count; i++){
		data = HWREG(0x44e0d100);
	}

	// Clear FIFO1 by reading from it. FIFO1COUNT, FIFO1DATA registers
	count = HWREG(0x44e0d0f0);
	for (i=0; i<count; i++){
		data = HWREG(0x44e0d200);
	}
	shared_ram[500] = data; // just remove unused value warning;

	// Enable tag channel id. ADC_CTRL register
	HWREG(0x44e0d040) |= 0x02;

	// Enable steps 1-4. STEPENABLE register
	/* HWREG(0x44e0d054) = 0x1e; */
	// Enable steps 1-6. STEPENABLE register
	// HWREG(0x44e0d054) = 0x7e;
	// Enable steps 1-3. STEPENABLE register
	// HWREG(0x44e0d054) = 0xe;
	// Enable steps 1-2. STEPENABLE register
	HWREG(0x44e0d054) = 0x6;
	// Enable all steps. STEPENABLE register
	/* HWREG(0x44e0d054) |= 0xfe; */

	// Enable Module (start sampling). ADC_CTRL register
	HWREG(0x44e0d040) |= 0x01;
}
