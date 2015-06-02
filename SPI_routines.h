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
// ***** HEADER FILE : SPI_routines.h ******
//**************************************************
#ifndef _SPI_ROUTINES_H_
#define _SPI_ROUTINES_H_

#define SPI_SD             SPCR = 0x52
#define SPI_HIGH_SPEED     SPCR = 0x50; SPSR |= (1<<SPI2X)


void spi_init(void);
unsigned char SPI_transmit(unsigned char);
unsigned char SPI_receive(void);

#endif
