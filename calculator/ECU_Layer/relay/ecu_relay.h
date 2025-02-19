/* 
 * File:   ecu_relay.h
 * Author: doc
 *
 * Created on 04 ??????, 2024, 09:59 ?
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

  /* Section : Includes */
#include "ecu_relay_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"  
 /* Section : Macro Declerations */
#define REALY_ON_STATUS     0x01U
#define REALY_OFF_STATUS    0x00U

 /* Section : Macro Functions Declerations */



 /* Section : Data Type Declerations */
typedef struct{
    uint8 relay_port : 4;
    uint8 relay_pin : 3;
    uint8 relay_status : 1;
}relay_t;



 /* Section : Functions Declerations */

Std_ReturnType relay_initialize(const relay_t *_relay);
Std_ReturnType relay_turn_on(const relay_t *_relay);
Std_ReturnType relay_turn_off(const relay_t *_relay);


#endif	/* ECU_RELAY_H */

