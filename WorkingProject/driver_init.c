/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>
#include <hpl_gclk_base.h>
#include <hpl_pm_base.h>

#include <hpl_rtc_base.h>

/*! The buffer size for USART */
#define USART_BUFFER_SIZE 16

/*! The buffer size for USART */
#define SERIAL_BUFFER_SIZE 16

struct usart_async_descriptor USART;
struct usart_async_descriptor SERIAL;
struct timer_descriptor       Timer;

static uint8_t USART_buffer[USART_BUFFER_SIZE];
static uint8_t SERIAL_buffer[SERIAL_BUFFER_SIZE];

struct usart_sync_descriptor TARGET_IO;

/**
 * \brief USART Clock initialization function
 *
 * Enables register interface and peripheral clock
 */
void USART_CLOCK_init()
{

	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM0);
	_gclk_enable_channel(SERCOM0_GCLK_ID_CORE, CONF_GCLK_SERCOM0_CORE_SRC);
}

/**
 * \brief USART pinmux initialization function
 *
 * Set each required pin to USART functionality
 */
void USART_PORT_init()
{

	gpio_set_pin_function(PA08, PINMUX_PA08C_SERCOM0_PAD0);

	gpio_set_pin_function(PA09, PINMUX_PA09C_SERCOM0_PAD1);
}

/**
 * \brief USART initialization function
 *
 * Enables USART peripheral, clocks and initializes USART driver
 */
void USART_init(void)
{
	USART_CLOCK_init();
	usart_async_init(&USART, SERCOM0, USART_buffer, USART_BUFFER_SIZE, (void *)NULL);
	USART_PORT_init();
}

void TARGET_IO_PORT_init(void)
{

	gpio_set_pin_function(PA00, PINMUX_PA00D_SERCOM1_PAD0);

	gpio_set_pin_function(PA01, PINMUX_PA01D_SERCOM1_PAD1);
}

void TARGET_IO_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM1);
	_gclk_enable_channel(SERCOM1_GCLK_ID_CORE, CONF_GCLK_SERCOM1_CORE_SRC);
}

void TARGET_IO_init(void)
{
	TARGET_IO_CLOCK_init();
	usart_sync_init(&TARGET_IO, SERCOM1, (void *)NULL);
	TARGET_IO_PORT_init();
}

/**
 * \brief USART Clock initialization function
 *
 * Enables register interface and peripheral clock
 */
void SERIAL_CLOCK_init()
{

	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM4);
	_gclk_enable_channel(SERCOM4_GCLK_ID_CORE, CONF_GCLK_SERCOM4_CORE_SRC);
}

/**
 * \brief USART pinmux initialization function
 *
 * Set each required pin to USART functionality
 */
void SERIAL_PORT_init()
{

	gpio_set_pin_function(PB08, PINMUX_PB08D_SERCOM4_PAD0);

	gpio_set_pin_function(PB09, PINMUX_PB09D_SERCOM4_PAD1);
}

/**
 * \brief USART initialization function
 *
 * Enables USART peripheral, clocks and initializes USART driver
 */
void SERIAL_init(void)
{
	SERIAL_CLOCK_init();
	usart_async_init(&SERIAL, SERCOM4, SERIAL_buffer, SERIAL_BUFFER_SIZE, (void *)NULL);
	SERIAL_PORT_init();
}

void delay_driver_init(void)
{
	delay_init(SysTick);
}

/**
 * \brief Timer initialization function
 *
 * Enables Timer peripheral, clocks and initializes Timer driver
 */
static void Timer_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBA, RTC);
	_gclk_enable_channel(RTC_GCLK_ID, CONF_GCLK_RTC_SRC);
	timer_init(&Timer, RTC, _rtc_get_timer());
}

/**
 * \brief PTC initialization function
 *
 * Enables PTC peripheral, clocks and initializes PTC driver
 */
static void PTC_clock_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, PTC);
	_gclk_enable_channel(PTC_GCLK_ID, CONF_GCLK_PTC_SRC);
}

void system_init(void)
{
	init_mcu();

	USART_init();

	TARGET_IO_init();
	SERIAL_init();

	delay_driver_init();

	Timer_init();

	PTC_clock_init();
}
