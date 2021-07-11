/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef DRIVER_INIT_INCLUDED
#define DRIVER_INIT_INCLUDED

#include "atmel_start_pins.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <hal_atomic.h>
#include <hal_delay.h>
#include <hal_gpio.h>
#include <hal_init.h>
#include <hal_io.h>
#include <hal_sleep.h>

#include <hal_usart_async.h>

#include <hal_usart_sync.h>
#include <hal_usart_async.h>

#include <hal_delay.h>
#include <hal_timer.h>

extern struct usart_async_descriptor USART;

extern struct usart_sync_descriptor  TARGET_IO;
extern struct usart_async_descriptor SERIAL;

extern struct timer_descriptor Timer;

void USART_PORT_init(void);
void USART_CLOCK_init(void);
void USART_init(void);

void TARGET_IO_PORT_init(void);
void TARGET_IO_CLOCK_init(void);
void TARGET_IO_init(void);

void SERIAL_PORT_init(void);
void SERIAL_CLOCK_init(void);
void SERIAL_init(void);

void delay_driver_init(void);

/**
 * \brief Perform system initialization, initialize pins and clocks for
 * peripherals
 */
void system_init(void);

#ifdef __cplusplus
}
#endif
#endif // DRIVER_INIT_INCLUDED
