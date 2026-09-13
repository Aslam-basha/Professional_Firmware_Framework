#include "bsp.h"
#include "bsp_led.h"
#include "bsp_button.h"

void BSP_Init(void)
{
    BSP_LED_Init();
    BSP_Button_Init();
}
