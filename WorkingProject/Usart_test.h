/*
 * Usart_test.h
 *
 * Created: 7/10/2021 8:50:35 AM
 *  Author: anand
 */ 


#ifndef USART_TEST_H_
#define USART_TEST_H_
#include <TuyaMCU/wifi.h>

void Uart_PutChar(unsigned char);
void send_uart(char[100]);
void uart_init();


#endif /* USART_TEST_H_ */