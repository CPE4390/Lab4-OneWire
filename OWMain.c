#include <xc.h>
#include <stdio.h>
#include "LCD.h"
#include "OneWire.h"
#include "DS18x20.h"

	#pragma config FOSC=HSPLL
	#pragma config WDTEN=OFF
	#pragma config XINST=OFF

//RJ0 = DQ

void main(void) {
    double t = 0;
    TRISD = 0;
    OSCTUNEbits.PLLEN = 1;
    LCDInit();
    LCDClear();
    OWInit();
    
    while (1) {
        //Change the lines below depending on the sensor you are using.
        //Only uncomment one of the lines
        t = ReadDS18S20(NULL);
        //t = ReadDS18B20(NULL);
        //t = ReadDS18S20PAR(NULL);
        //t = ReadDS18B20PAR(NULL);
        
        LATDbits.LATD0 ^= 1;
        lprintf(0, "T=%.2f C", t);
    }
}


