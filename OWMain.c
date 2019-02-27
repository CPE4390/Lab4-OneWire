#include <xc.h>
#include <stdio.h>
#include "LCD.h"
#include "OneWire.h"
#include "DS18x20.h"

#if defined __18F8722
	#pragma config OSC=HSPLL
	#pragma config WDT=OFF
	#pragma config LVP=OFF
	#pragma config XINST=OFF
#elif defined __18F87J11
	#pragma config FOSC=HSPLL
	#pragma config WDTEN=OFF
	#pragma config XINST=OFF
#else
	#error Invalid processor selection
#endif

char str[17];

void main(void) {
    double t = 0;
    TRISD = 0;
    OSCTUNEbits.PLLEN = 1;
    LCDInit();
    LCDClear();
    OWInit();
    
    while (1) {
        t = ReadDS18S20(NULL);
        LATDbits.LATD0 ^= 1;
        sprintf(str, "T=%.2f C", t);
        LCDWriteLine(str, 0);
    }
}


