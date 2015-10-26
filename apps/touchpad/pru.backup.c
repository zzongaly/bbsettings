// Macro for accessing a hardware register (32 bit)
#define HWREG(x) (*((volatile unsigned int *)(x)))


volatile register unsigned int __R31;
unsigned int* shared_ram = (unsigned int *)0x10000;
int finish = 0;

int main(int argc, const char *argv[]){
	// Enable OCP so we can access the whole memory map for the
	// device from the PRU. Clear bit 4 of SYSCFG register
	HWREG(0x26004) &= 0xFFFFFFEF;

	// Enable GPIO0 Module. GPIO0_CTRL Register
	HWREG(0x44e07130) = 0x00;

	// Enable clock used for GPIO0 debounce. CM_WKUP_GPIO0_CLKCTRL Register
	HWREG(0x44e00408) |= 1<<2;
	HWREG(0x44e00408) |= 1<<18;

	// TODO: Measure if debouncing time adds latency to pin state detection.
	// Set debouncing time to 1ms.
	// Debouncing time = (DEBOUNCETIME + 1) > 31 ??
	// So, set GPIO_DEBOUNCINGTIME register to 32 (0x20)
	// And also set DEBOUNCENABLE bit in GPIO_DEBOUNCEABLE register
	// for pin p9_11
	HWREG(0x44e07150) |= 1<<30;
	HWREG(0x44e07150) |= 1<<31;
	HWREG(0x44e07154) = 0x20;

	// GPIO1[21] (User led 0) as an output
	HWREG(0x44e10854) = 0x0f;

	unsigned int value11 = 0;
	unsigned int previous_value11 = 1;
	unsigned int value13 = 0;
	unsigned int previous_value13 = 1;

	// P9_11 pin as an input, with no pullup/pulldown
	HWREG(0x44e10870) = 0x0f;
	// P9_13 pin as an output, with no pullup/pulldown
	HWREG(0x44e10874) = 0x0f;

	unsigned int chk = 0;

	while(!finish){
		int i;

		// P9_13 pin set as high. alter
		/*
		if(chk == 1)
			HWREG(0x4804c13c) |= (1<<31);
		else
			HWREG(0x4804c13c) &= ~(1<<31);

		for(i=0;i<2000000;i++);
		*/

		// Get new value from 11 pin. GPIO_DATA_IN register.
		/*
		value11 = (HWREG(0x33e07138) & (1<<30)) != 0;
		if(value11 != previous_value11){
			shared_ram[0] = value11;
			__R31 = 35;
			previous_value11 = value11;
		}
		*/

		/*
		// P9_11 pin as an output, with no pullup/pulldown
		HWREG(0x44e10870) = 0x0f;
		// P9_13 pin as an input, with no pullup/pulldown
		HWREG(0x44e10874) = 0x2f;

		// P9_11 pin set as high.
		HWREG(0x4804c13c) |= (chk<<30);
		for(i=0;i<2000000;i++);
		// Get new value from 13 pin. GPIO_DATA_IN register.
		value13 = (HWREG(0x44e07138) & (1<<31)) != 0;
		*/
		/*
		if(value13 != previous_value13){
			shared_ram[1] = value13;
			__R31 = 35;
			previous_value13 = value13;
		}
		*/
		
		if(chk == 1)
			chk = 0;
		else
			chk = 1;
	}


	// stop pru processing
	__halt();

	return 0;
}
