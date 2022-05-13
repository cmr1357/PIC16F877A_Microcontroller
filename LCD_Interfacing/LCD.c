/*
 * File:   LCDHARD1.c
 * Author: Chithra
 *
 * Created on 17 December, 2021, 12:07 PM
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
#define RS RB0
#define RW RB1
#define E  RB2

void lcd_data(char *s)
{
    RS = 1;
    RW = 0;
    
    E=0;
    
    while (*s !='\0')
    {
    
    PORTD=*s;
    E=1;
    __delay_ms(100);
    E=0;
     __delay_ms(100);
     s++;
    }
}
void lcd_cmd(int x)
{
    RS = 0;
    RW = 0;
    
    E=0;
    
    PORTD=x;
    E=1;
    __delay_ms(100);
    E=0;
     __delay_ms(100);
}

void main(void) {
    TRISD=0X00;
    TRISB=0X00;
    
    char str[7]="HELLO";
    char *s;
    
    lcd_cmd(0X38);//enable 5x7 mode for character
    lcd_cmd(0X0E);//Display OFF, Cursor ON
    lcd_cmd(0X01);//Clear Display
    lcd_cmd(0X80);//Move the cursor to beginning of the first line
    
    s=str;
    
    lcd_data(s);
    
    return;
}
