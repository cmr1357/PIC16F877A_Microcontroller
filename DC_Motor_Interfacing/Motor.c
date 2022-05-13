/*
 * File:   MOTORINTERFACE.c
 * Author: Chithra
 *
 * Created on 15 January, 2022, 7:14 PM
 */


#include <xc.h>
#define _XTAL_FREQ 20000000
void main(void) {
    
    TRISB=0X00;
    while(1)
    {
        RB0=1;
        RB1=0;
        __delay_ms(5000);
        RB0=0;
        RB1=1;
        __delay_ms(5000);
    }
    return;
}
