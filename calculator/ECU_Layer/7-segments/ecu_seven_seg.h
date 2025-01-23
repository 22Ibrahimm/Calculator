/* 
 * File:   ecu_seven_seg.h
 * Author: doc
 *
 * Created on 02 ??????, 2024, 05:34 ?
 */

#ifndef ECU_SEVEN_SEG_H
#define	ECU_SEVEN_SEG_H

/* Section : Includes */
#include"../../MCAL_Layer/GPIO/hal_gpio.h"
#include"ecu_seven_seg_cfg.h"

 /* Section : Macro Declerations */

#define SEGMENT_PIN0  0
#define SEGMENT_PIN1  1
#define SEGMENT_PIN2  2
#define SEGMENT_PIN3  3

 /* Section : Macro Functions Declerations */



 /* Section : Data Type Declerations */
typedef enum {
    SEGMENT_COMMON_ANODE,
    SEGMENT_COMMON_CATHODE
}segment_type_t;

typedef struct{
    pin_config_t segment_pins[4];
    segment_type_t segment_type;
}segment_t;

 /* Section : Functions Declerations */
Std_ReturnType seven_segement_intialize(const segment_t *seg);
Std_ReturnType seven_segement_write_number(const segment_t *seg, uint8 number);

#endif	/* ECU_SEVEN_SEG_H */

