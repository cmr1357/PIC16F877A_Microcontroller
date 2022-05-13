/*
 * File:   SEVENSEGHARD1.c
 * Author: Chithra
 *
 * Created on 17 December, 2021, 12:27 PM
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
int arr[6]={0X3f,0X06,0X5B,0X4F,0X64,0X6D};
int i;
//char 7seg[6]=
void main(void) {
    TRISB=0X00;
    while(1)
    {
  
      //  PORTB=0X40;//common anode print0
        for(i=0;i<=5;i++)
        {
            //PORTB =arr[i];
            PORTB =0X40;
            __delay_ms(1000);
        }
    
   
    
    }
    
   
    return;
}