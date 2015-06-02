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
// ***** SOURCE FILE : SPI_routines.c ******
//**************************************************
#include <avr/io.h>
#include "SPI_routines.h"

//SPI initialize for SD card
//clock rate: 4Mhz (SPI2X)
void spi_init(void)
{
//SPCR = 0x52; //setup SPI: Master mode, MSB first, SCK phase low, SCK idle low
//SPSR = 0x00;
    SPI_HIGH_SPEED;
}

unsigned char SPI_transmit(unsigned char data)
{
// Start transmission
SPDR = data;

// Wait for transmission complete
while(!(SPSR & (1<<SPIF)));
data = SPDR;

return(data);
}

unsigned char SPI_receive(void)
{
unsigned char data;
// Wait for reception complete

SPDR = 0xff;
while(!(SPSR & (1<<SPIF)));
data = SPDR;

// Return data register
return data;
}

//******** END ****** www.dharmanitech.com *****
