/*
 * File:   SWITCHHARD1.c
 * Author: Chithra
 *
 * Created on 17 December, 2021, 11:47 AM
 */
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>

#define _XTAL_FREQ 20000000
void main(void) {
   TRISB=0X01;
    for(;;)
    { 
            if (RB0 == 1)
            {
                RB1 = 1;
                __delay_ms(100);
               
            }
            else
            {
                 RB1=0;
                __delay_ms(100);
            }
    }  
    return;
}
