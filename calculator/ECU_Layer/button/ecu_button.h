/* 
 * File:   ecu_button.h
 * Author: doc
 *
 * Created on 30 ??????, 2024, 05:23 ?
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H


 /* Section : Includes */
#include "ecu_button_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"  
    
 /* Section : Macro Declerations */




 /* Section : Macro Functions Declerations */



 /* Section : Data Type Declerations */
typedef enum{
     BUTTON_PRESSED = 0,
     BUTTON_RELEASED
}button_state_t;

typedef enum{
    BUTTON_ACTIVE_HIGH ,
    BUTTON_ACTIVE_LOW
}button_active_t;

typedef struct{
    pin_config_t button_pin; 
    button_state_t button_state;
    button_active_t button_connection;
}button_t;
            

 /* Section : Functions Declerations */
Std_ReturnType button_initialize(const button_t *btn);
Std_ReturnType button_read_state(const button_t *btn, button_state_t *btn_state);

#endif	/* ECU_BUTTON_H */

