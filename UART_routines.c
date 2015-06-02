//*******************************************************
// **** ROUTINES FOR FAT32 IMPLEMATATION OF SD CARD ****
//**********************************************************
//Controller: ATmega328p (Clock: 16 Mhz-internal)
//Compiler	: AVR-GCC (Atmel Studio 6.2)
//Version 	: 0.1
//Author	: CC Dharmani, Chennai (India)
//Ported by : Fritz, John (USA)
//			  www.dharmanitech.com
//Date		: 01 June 2015
//********************************************************

//Link to the original Post: http://www.dharmanitech.com/2009/01/sd-card-interfacing-with-atmega8-fat32.html

//**************************************************
// ***** SOURCE FILE : UART_routines.c ******
//**************************************************

#include "UART_routines.h"
#include <avr/io.h>
#include <avr/pgmspace.h>

//**************************************************
//UART0 initialize
//baud rate: 115200  (for controller clock = 16MHz)
//char size: 8 bit
//parity: Disabled
//**************************************************
void uart0_init(void)
{
    UCSR0A = 0x00;
    UCSR0B = 0x18;			// enable UART TX and RX
    UCSR0C = 0x06;			// set the UART for N, 8, 1
    UBRR0L = 8;				// set BAUD Rate for 115200 with 16MHz clock
    UBRR0H = 0;
}

//**************************************************
//Function to receive a single byte
//*************************************************
unsigned char receiveByte( void )
{
	unsigned char data, status;
	
	while(!(UCSRA & (1<<RXC))); 	// Wait for incomming data
	
	status = UCSRA;
	data = UDR;
	
	return(data);
}

//***************************************************
//Function to transmit a single byte
//***************************************************
void transmitByte( unsigned char data )
{
    while ( (UCSR0A & (1<<RXC0)) == 0 )			    // wait until the received character flag is set
    {
    }

    data = UDR0;
}


//***************************************************
//Function to transmit hex format data
//first argument indicates type: CHAR, INT or LONG
//Second argument is the data to be displayed
//***************************************************
void transmitHex( unsigned char dataType, unsigned long data )
{
unsigned char count, i, temp;
unsigned char dataString[] = "0x        ";

if (dataType == CHAR) count = 2;
if (dataType == INT) count = 4;
if (dataType == LONG) count = 8;

for(i=count; i>0; i--)
{
  temp = data % 16;
  if((temp>=0) && (temp<10)) dataString [i+1] = temp + 0x30;
  else dataString [i+1] = (temp - 10) + 0x41;

  data = data/16;
}

transmitString (dataString);
}

//***************************************************
//Function to transmit a string in Flash
//***************************************************
void transmitString_F(char* string)
{
  while (pgm_read_byte(&(*string)))
   transmitByte(pgm_read_byte(&(*string++)));
}

//***************************************************
//Function to transmit a string in RAM
//***************************************************
void transmitString(unsigned char* string)
{
  while (*string)
   transmitByte(*string++);
}

//************ END ***** www.dharmanitech.com *******
