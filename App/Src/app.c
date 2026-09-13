#include "app.h"
#include "bsp_led.h"
#include "bsp_button.h"

static app_button_state_t button_state = INITIAL;

void App_Init(void)
{
    // BSP_LED_Init();
    // BSP_Button_Init();

}

void App_Run(void)
{

	bsp_button_event_t event;

	BSP_Button_Process();

	event = BSP_Button_GetEvent();

	if (event == BSP_BUTTON_EVENT_PRESSED)
	{
		BSP_LED_Toggle();
	}
//    if (BSP_Button_GetState() == BSP_BUTTON_PRESSED)
//    {
//        BSP_LED_Set(BSP_LED_ON);
//    }
//    else
//    {
//        BSP_LED_Set(BSP_LED_OFF);
//    }

//    switch(button_state)
//    {
//    	case INITIAL:
//    		BSP_LED_Set(BSP_LED_OFF);
//    		if (BSP_Button_GetState() == BSP_BUTTON_PRESSED)
//			{
//    			button_state = BUTTON_PRESSED;
//			}
//    		break;
//
//    	case BUTTON_PRESSED:
//    		BSP_LED_Set(BSP_LED_ON);
//    		if (BSP_Button_GetState() == BSP_BUTTON_RELEASED)
//			{
//				button_state = BUTTON_RELEASED;
//			}
//			break;
//
//    	case BUTTON_RELEASED:
//    		if(BSP_LED_GetState() == BSP_LED_ON)
//    		{
//    			BSP_LED_Set(BSP_LED_ON);
//    		}
//    		else
//    		{
//    			BSP_LED_Set(BSP_LED_OFF);
//    		}
//
//    		if (BSP_Button_GetState() == BSP_BUTTON_PRESSED)
//			{
//				button_state = BUTTON_PRESSED_AGAIN;
//			}
//			break;
//
//    	case BUTTON_PRESSED_AGAIN:
//    		if(BSP_LED_GetState() == BSP_LED_ON)
//			{
//				BSP_LED_Set(BSP_LED_OFF);
//			}
//			else
//			{
//				BSP_LED_Set(BSP_LED_ON);
//			}
//
//    		if (BSP_Button_GetState() == BSP_BUTTON_RELEASED)
//			{
//				button_state = BUTTON_RELEASED;
//			}
//			break;
//
//    	default:
//    		break;
//    }
}
