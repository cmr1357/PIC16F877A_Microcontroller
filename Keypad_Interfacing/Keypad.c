/*
 * File:   KEYPADHARD.c
 * Author: Chithra
 *
 * Created on 16 December, 2021, 11:52 AM
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
#define rs RC0
#define en RC2
#define rw RC1
#define R1 RB0
#define R2 RB1
#define R3 RB2
#define R4 RB3
#define C1 RB4
#define C2 RB5
#define C3 RB6
#define C4 RB7

char keypad[4][4]=
{{'0','1','2','3'},
{'4','5','6','7'},
{'8','9','A','B'},
{'C','D','E','F'}};

char rowloc,colloc;
void cmd(char a)
{
    rs=0;
    rw=0;
    en=0;
    PORTD=a;
    en=1;
    __delay_ms(100);
    en=0;
    __delay_ms(100);
}
void lcd_init()
{
    cmd(0X38);
    cmd(0X0E);
    cmd(0X80);
   // cmd(0X0F);
}
void lcd_data(char b)
{
    rs=1;
    rw=0;
    en=0;
    PORTD=b;
    en=1;
    __delay_ms(100);
    en=0;
     __delay_ms(100);
}
void show(char *s)
{
    while(*s != '\0')
    {
        lcd_data(*s);
        s=s+1;
        __delay_ms(100);
    }
}
void key_init()
{
    TRISB=0XF0;
    OPTION_REG &= 0X7F;
}
char key()
{
    PORTB= 0X00;
    while(C1&&C2&&C3&&C4);//PULLUP
    while(!C1 || !C2 ||!C3 ||!C4 )
    {
        R1=0;
        R2=R3=R4=1;
        if(!C1 || !C2 || !C3 ||!C4 )
        {
            rowloc=0;
            break;
            
            
        }
        R2=0;
        R1=1;
        if(!C1 || !C2 || !C3 ||!C4 )
        {
            rowloc=1;
            break;
            
        }R3=0;
        R2=1;
        if(!C1 || !C2 || !C3 ||!C4 )
        {
            rowloc=2;
            break;
            
        }
        R4=0;
        R3=1;
        if(!C1 || !C2 || !C3 ||!C4 )
        {
            rowloc=3;
            break;
            
        }
        
    }
    if(C1==0&&C2 !=0&&C3 !=0&&C4 !=0)
        colloc=0;
    else if(C1!=0&&C2 ==0&&C3 !=0&&C4 !=0)
        colloc=1;
    else if(C1!=0&&C2 !=0&&C3 ==0&&C4 !=0)
        colloc=2;
    else if(C1!=0&&C2 !=0&&C3 !=0&&C4 ==0)
        colloc=3;
    while(C1==0||C2==0||C3==0||C4==0)
        return(keypad[rowloc][colloc]);
    
}
void main(void) 

{   
    int i;
    TRISD=0;
    TRISC=0;
    
    
    lcd_init();
    __delay_ms(500);
    key_init();
    char b;
    show("Press Key");
    cmd(0XC0);
    while(1)
    {
        cmd(0XC7);
        b= key();
        lcd_data(b);
    }
            
    
    return;
}
