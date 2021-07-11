/*
 * usart_testing.c
 *
 * Created: 7/10/2021 7:29:22 PM
 *  Author: anand
 */ 
void Uart_PutChar(unsigned char);

void printin1s(void){
	Uart_PutChar('a');
	Uart_PutChar('n');
	Uart_PutChar('d');
	Uart_PutChar(' ');
	Uart_PutChar('w');
	Uart_PutChar('\n');
	delay_ms(1000);
}