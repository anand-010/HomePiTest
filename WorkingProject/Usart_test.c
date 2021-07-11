/*
 * Usart_test.c
 *
 * Created: 7/10/2021 8:44:51 AM
 *  Author: anand
 */ 
//	Serial Receiving flag

#include <Usart_test.h>
#include <stdint-gcc.h>
#include <driver_init.h>

volatile uint8_t UART0_Receiving = 0;

//	Bytes received counter
volatile uint8_t UART0_received_Bytes_counter = 0;
volatile uint8_t total_Bytes = 0;

//	Size of receive Buffer
#define BUFFER_SIZE 100

//	Receive Buffer
volatile uint8_t rx_buffer[BUFFER_SIZE];

void send_uart(char message[100])
{
	//	Get length of message
	int length=strlen(message);

	//	Write message
	io_write(&SERIAL.io, (uint8_t *)message,length);
}

void serial_rx_callback(const struct usart_async_descriptor *const io_descr)
{
	//	Counters
	uint8_t ch,count;

	//	Read a Character
	count = io_read(&SERIAL.io,&ch,1);
	uart_receive_input((unsigned char)ch);
	
}
void uart_init()
{
	struct io_descriptor *io;
	//	Setup RX callback
	usart_async_register_callback(&SERIAL, USART_ASYNC_RXC_CB, serial_rx_callback);
	// 	usart_async_register_callback(&USART_0, USART_ASYNC_ERROR_CB, err_cb);
	//	Setup USART
	usart_async_get_io_descriptor(&SERIAL, &io);
	usart_async_enable(&SERIAL);
}
void Uart_PutChar(unsigned char value){
		char val[] = { value };
		io_write(&SERIAL.io, (uint8_t *)val,1);
}