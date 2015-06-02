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
// ***** HEADER FILE : UART_routines.h ******
//**************************************************

#ifndef _UART_ROUTINES_H_
#define _UART_ROUTINES_H_

#define CHAR 0
#define INT  1
#define LONG 2

#define TX_NEWLINE {transmitByte(0x0d); transmitByte(0x0a);}

void uart0_init(void);
unsigned char receiveByte(void);
void transmitByte(unsigned char);
void transmitString_F(char*);
void transmitString(unsigned char*);
void transmitHex( unsigned char dataType, unsigned long data );


#endif
