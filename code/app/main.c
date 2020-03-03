#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

#include "nrf_delay.h"
#include "boards.h"

/*��ʼ����־��ӡģ��*/
static void log_init(void)
{
	ret_code_t err_code = NRF_LOG_INIT(NULL);		/*��ʼ��*/
    APP_ERROR_CHECK(err_code);
	
    NRF_LOG_DEFAULT_BACKENDS_INIT();				/*����log����ն�*/
}

/*����״̬������������������־*/
static void idle_state_handle(void)
{
    /*��������log*/
	  if (NRF_LOG_PROCESS() == false)
    {

    }
}

int main(void)
{
	log_init();
	nrf_gpio_cfg_output(LED_3);
	
	while(1)
	{
		NRF_LOG_INFO("BLE Template example:Log use uart as output terminal");
		nrf_gpio_pin_set(LED_3);
		nrf_delay_ms(2000);
		nrf_gpio_pin_clear(LED_3);
		nrf_delay_ms(2000);
		idle_state_handle();
	}
}
