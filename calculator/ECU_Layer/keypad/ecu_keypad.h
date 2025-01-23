/* 
 * File:   ecu_keypad.h
 * Author: doc
 *
 * Created on 05 ??????, 2024, 12:42 ?
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H

/* Section : Includes */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_keypad_cfg.h"
 /* Section : Macro Declerations */
#define ECU_KEYPAD_ROWS         4
#define ECU_KEYPAD_COLUMNS      10


 /* Section : Macro Functions Declerations */



 /* Section : Data Type Declerations */
typedef struct{
    pin_config_t keypad_row_pins[ECU_KEYPAD_ROWS];
    pin_config_t keypad_columns_pins[ECU_KEYPAD_COLUMNS];
}keypad_t;



 /* Section : Functions Declerations */
Std_ReturnType keypad_intialize(const keypad_t *_keypad_obj);
Std_ReturnType keypad_get_value(const keypad_t *_keypad_obj, uint8 *value);


#endif	/* ECU_KEYPAD_H */

