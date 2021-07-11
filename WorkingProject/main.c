#include <atmel_start.h>
#include <Usart_test.h>

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	wifi_protocol_init();
	uart_init();
	/* Replace with your application code */
	while (1) {
		wifi_uart_service();
		//Uart_PutChar('a');
		//Uart_PutChar('\n');
		//delay_ms(1000);
	}
}
