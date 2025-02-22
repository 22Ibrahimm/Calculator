/* 
 * File:   ecu_led.h
 * Author: doc
 *
 * Created on 08 ??????, 2024, 12:28 ?
 */

#ifndef ECU_LED_H
#define	ECU_LED_H


  

 /* Section : Includes */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"  
#include "ecu_led_cfg.h"    
 /* Section : Macro Declerations */




 /* Section : Macro Functions Declerations */



 /* Section : Data Type Declerations */
typedef enum{
    LED_OFF,
    LED_ON
}led_status;

typedef struct{
    uint8 port_name : 4;
    uint8 pin : 3;
    uint8 led_status : 1;
}led_t;



 /* Section : Functions Declerations */
 Std_ReturnType led_initialize(const led_t *led);   
 Std_ReturnType led_turn_on(const led_t *led);   
 Std_ReturnType led_turn_off(const led_t *led);   
 Std_ReturnType led_turn_toggle(const led_t *led);   

#endif	/* ECU_LED_H */

