/*
 * File:   adc.c
 * Author: Chithra
 *
 * Created on 29 December, 2021, 1:50 PM
 */


#include <xc.h>
#define _XTAL_FREQ 20000000
#define RS RB0
#define RW RB1
#define E  RB2

void data(char x)
{   RS = 1;
    RW = 0;
    
    E=0;
    PORTD=x;
    E=1;
    __delay_ms(100);
    E=0;
     __delay_ms(100);
     
    
}
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
void adc()
{
    unsigned int adcval;
    ADCON1=0XC0;//right justified
    ADCON0=0X85;//adc on,fosc/64
    while(GO_DONE);//wait until conversation is finished
     adcval =((ADRESH<<8)|(ADRESL));
    data((adcval/1000)+48);
    data(((adcval/100)%10)+48);
    data(((adcval/10)%10)+48);
    data((adcval%10)+48);
}
void main(void) {
    TRISD=0X00;//PORTB AND D OUTPUT LCD
    TRISB=0X00;
    TRISC=0X00;
    TRISA=0X01;
    
    char str[7]="ADC Value :";
    char *s;
    
    lcd_cmd(0X38);//enable 5x7 mode for character
    lcd_cmd(0X0E);//Display OFF, Cursor ON
    lcd_cmd(0X01);//Clear Display
    lcd_cmd(0X80);//Move the cursor to beginning of the first line
    
    s=str;
    
    lcd_data(s);
    while(1)
    {
        lcd_cmd(0X8C);
        adc();
    }
    return;
}
