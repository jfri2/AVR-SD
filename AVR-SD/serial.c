/*******************************

serial.c

********************************/
void InitUART(void);
static int UARTPutChar(char ch, FILE *stream);
static int UARTGetChar(FILE *stream);
void UARTSendByte(uint8_t);

static FILE mystdout = FDEV_SETUP_STREAM(UARTPutChar, UARTGetChar, _FDEV_SETUP_RW);	/* Assign I/O stream to UART */


void InitUART(void)
{

	UCSR0A = 0x00;			
	UCSR0B = 0x18;			// enable UART TX and RX
	UCSR0C = 0x06;			// set the UART for N, 8, 1
	UBRR0L = 8;				// set BAUD Rate for 115200 with 16MHz clock
	UBRR0H = 0;

	stdout = &mystdout;		// define the output stream
	stdin = &mystdout;		// define the input stream	

}


// the following function sends a single character out of the serial port
static int UARTPutChar(char ch, FILE *stream)
{

    while ( (UCSR0A & (1 << UDRE0)) == 0 )		// wait until there is room in the transmit buffer
	{
	}

    UDR0 = ch;									// load the character into the UART data register

    return 0;
}

void UARTSendByte(uint8_t send_byte)
{
	while ((UCSR0A & (1 << UDRE0)) == 0)
	{		
	}
	
	UDR0 = send_byte;
}

// the following function waits for a serial character to be received
static int UARTGetChar(FILE *stream)
{
   unsigned char ch;   							// create a variable to hold the received value
   
   while ( (UCSR0A & (1<<RXC0)) == 0 )			// wait until the received character flag is set
   {
   }
   
   ch=UDR0;  									// load the received character into the local variable


   return ch;									// return the value
}

