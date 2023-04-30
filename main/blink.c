#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_log.h"

#define BLINK_GPIO_Blue 18
#define BLINK_GPIO_Green 17
#define BLINK_GPIO_Red 16

static const char *TAG = "BLINK";

void app_main(void){
	//esp_log_level_set("BLINK", ESP_LOG_ERROR);       
	esp_log_level_set("BLINK", ESP_LOG_INFO);       
	
	ESP_ERROR_CHECK(gpio_set_direction(BLINK_GPIO_Red, GPIO_MODE_OUTPUT));
	ESP_ERROR_CHECK(gpio_set_direction(BLINK_GPIO_Green, GPIO_MODE_OUTPUT));
	ESP_ERROR_CHECK(gpio_set_direction(BLINK_GPIO_Blue, GPIO_MODE_OUTPUT));

	while(1) {
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
	}
}

