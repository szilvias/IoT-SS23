#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_log.h"

#define BLINK_GPIO_Blue 18
#define BLINK_GPIO_Green 17
#define BLINK_GPIO_Red 16
#define Start_Stop_Button 2
//#define BLINK_GPIO_ExtLed 15

static const char *TAG = "BLINK";

void app_main(void){
	//esp_log_level_set("BLINK", ESP_LOG_ERROR);       
	esp_log_level_set("BLINK", ESP_LOG_INFO);       
	
	ESP_ERROR_CHECK(gpio_set_direction(BLINK_GPIO_Red, GPIO_MODE_OUTPUT));
	ESP_ERROR_CHECK(gpio_set_direction(BLINK_GPIO_Green, GPIO_MODE_OUTPUT));
	ESP_ERROR_CHECK(gpio_set_direction(BLINK_GPIO_Blue, GPIO_MODE_OUTPUT));
        //ESP_ERROR_CHECK(gpio_set_direction(BLINK_GPIO_ExtLed, GPIO_MODE_OUTPUT));
        ESP_ERROR_CHECK(gpio_set_direction(Start_Stop_Button, GPIO_MODE_INPUT));
        ESP_ERROR_CHECK(gpio_pulldown_en(Start_Stop_Button));

        while(1) {
                int button_state = gpio_get_level(Start_Stop_Button);
                ESP_LOGI(TAG, "Button state: %d", button_state);
                if (button_state == 1) {
                        /* Red LED */
                        ESP_LOGI(TAG, "Turning on the Red LED");
                        ESP_ERROR_CHECK(gpio_set_level(BLINK_GPIO_Red, 0));
                        vTaskDelay(1000 / portTICK_PERIOD_MS);
                        ESP_LOGI(TAG, "Turning off the Red LED");
                        ESP_ERROR_CHECK(gpio_set_level(BLINK_GPIO_Red, 1));

                        /* Green LED */
                        ESP_LOGI(TAG, "Turning on the Green LED");
                        ESP_ERROR_CHECK(gpio_set_level(BLINK_GPIO_Green, 0));
                        vTaskDelay(1000 / portTICK_PERIOD_MS);
                        ESP_LOGI(TAG, "Turning off the Green LED");
                        ESP_ERROR_CHECK(gpio_set_level(BLINK_GPIO_Green, 1));

                        /* Blue LED */
                        ESP_LOGI(TAG, "Turning on the Blue LED");
                        ESP_ERROR_CHECK(gpio_set_level(BLINK_GPIO_Blue, 0));
                        vTaskDelay(1000 / portTICK_PERIOD_MS);
                        ESP_LOGI(TAG, "Turning off the Blue LED");
                        ESP_ERROR_CHECK(gpio_set_level(BLINK_GPIO_Blue, 1));
                        /*
                        ESP_LOGI(TAG, "Turning on the external LED");
                        ESP_ERROR_CHECK(gpio_set_level(BLINK_GPIO_ExtLed, 1));
                        vTaskDelay(1000 / portTICK_PERIOD_MS);
                        ESP_LOGI(TAG, "Turning off the external LED");
                        ESP_ERROR_CHECK(gpio_set_level(BLINK_GPIO_ExtLed, 0));
                        */
	        } else {
                        ESP_LOGI(TAG, "Button is released");
                        vTaskDelay(100 / portTICK_PERIOD_MS);
                }
        }
}

