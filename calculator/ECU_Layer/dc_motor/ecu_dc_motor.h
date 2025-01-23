/* 
 * File:   ecu_dc_motor.h
 * Author: doc
 *
 * Created on 08 ??????, 2024, 05:54 ?
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/* Section : Includes */
#include "ecu_dc_motor_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

 /* Section : Macro Declerations */

#define DC_MOTOR_ON_STATUS     0x01U
#define DC_MOTOR_OFF_STATUS    0x00U

#define DC_MOTOR_PIN1 0x00U
#define DC_MOTOR_PIN2 0x01U


 /* Section : Macro Functions Declerations */



 /* Section : Data Type Declerations */

typedef struct{
    pin_config_t dc_motor_bin[2];
}dc_motor_t;


 /* Section : Functions Declerations */
Std_ReturnType dc_motor_intialize(const dc_motor_t *_dc_motor);
Std_ReturnType dc_motor_move_right(const dc_motor_t *_dc_motor);
Std_ReturnType dc_motor_move_left(const dc_motor_t *_dc_motor);
Std_ReturnType dc_motor_stop(const dc_motor_t *_dc_motor);

#endif	/* ECU_DC_MOTOR_H */

