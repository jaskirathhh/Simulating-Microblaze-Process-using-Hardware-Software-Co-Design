/*
 * DownCounter_MB.c
 *
 * Created on: Apr 6, 2021
 *  Author: Jaskirath Singh
 */


#include "xparameters.h"    // contain parameters like address, ID for IPs
#include "xgpio.h"        // contins driver fucntion for 
#include "xtmrctr.h"     //  Contains driver fucntion for timer IP

int main(){

	XGpio led_gpio;		// creating gpio object
	XTmrCtr timer_axi;	// creating timer object
	int value1;			// variable to store timer value
	
	XGpio_Initialize(&led_gpio, XPAR_AXI_GPIO_0_DEVICE_ID);		//initializing gpio object
	XTmrCtr_Initialize(&timer_axi, XPAR_AXI_TIMER_0_DEVICE_ID);	////initializing timer object
	
	//Setting our mode to down counter with autoreload
	XTmrCtr_SetOptions(&timer_axi, 0, XTC_CAPTURE_MODE_OPTION | XTC_DOWN_COUNT_OPTION | XTC_AUTO_RELOAD_OPTION);
	
	value1 = XTmrCtr_GetValue(&timer_axi, 0);		//get value of timer
	XTmrCtr_Start(&timer_axi, 0);					//starting timer

	while(1){
		XGpio_DiscreteWrite(&led_gpio, 1, 1);		//writing to gpio port
		value1 = XTmrCtr_GetValue(&timer_axi, 0);	//reading value of timer
		XGpio_DiscreteWrite(&led_gpio, 1, 2);
		value1 = XTmrCtr_GetValue(&timer_axi, 0);
		XGpio_DiscreteWrite(&led_gpio, 1, 4);
		value1 = XTmrCtr_GetValue(&timer_axi, 0);
		XGpio_DiscreteWrite(&led_gpio, 1, 8);
		value1 = XTmrCtr_GetValue(&timer_axi, 0);
	}
}
