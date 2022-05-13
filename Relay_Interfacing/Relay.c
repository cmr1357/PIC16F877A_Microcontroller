/*
 * File:   RELAY.c
 * Author: Chithra
 *
 * Created on 18 January, 2022, 11:57 AM
 */


#include <xc.h>
#define _XTAL_FREQ 20000000

void main(void) 
{
    TRISB0=1;
    TRISB1=0;
    
    
        if(RB0 == 1)
        {
            RB1=1;
            __delay_ms(1000);
        }
        else
        {
            RB1=0;
            __delay_ms(1000);
        }
    
    return;
}
