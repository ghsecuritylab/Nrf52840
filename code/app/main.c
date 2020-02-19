#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "boards.h"

int main(void)
{
	nrf_gpio_cfg_output(LED_2);
	
	while(1)
	{
		nrf_gpio_pin_set(LED_2);
		nrf_delay_ms(2000);
		nrf_gpio_pin_clear(LED_2);
		nrf_delay_ms(2000);
	}
}
