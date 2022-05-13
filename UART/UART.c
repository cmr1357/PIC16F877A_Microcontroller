/*
 * File:   UART.c
 * Author: Chithra
 *
 * Created on 26 December, 2021, 5:10 AM
 */


#include <xc.h>
void UART_Init( )
{
    TRISC=0X80;//Configure RX pin as input and TX as output
    TXSTA=0X24;
    RCSTA=0X90;
    SPBRG=129;//Baud rate 20Mhz Clock
    
}
void UART_Tx(char ch)
{
    while(TXIF ==0);//Wait till the transmitter register becomes empty
        TXIF=0;//clear transmitter flag
    TXREG=ch;//Load the char to be transmitted into transmit reg.
}
char UART_Rx()
{
    while(RCIF==0);//Wait till the data is received
    RCIF=0;//clear receiver flag
    return(RCREG);//Return the received data to calling function.
}

void main(void) 
{
     UART_Init();
    char i,a[]={"Abhinav"};
    char ch;
    for(i=0;a[i]!=0;i++)
    {
        UART_Tx(a[i]);//Transmit predefined string
    
   // UART_Tx('A');
    }
     //char ch;
    while(1)
    {
        ch =UART_Rx();// Receive a char from serial port
        UART_Tx(ch);//Transmit the received char
    }
    return;
}
