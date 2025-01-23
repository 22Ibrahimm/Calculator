/* 
 * File:   Calculator.h
 * Author: doc
 *
 * Created on 25 ??????, 2024, 07:14 ?
 */

#ifndef CALCULATOR_H
#define	CALCULATOR_H

/* Section : Includes */

#include "ECU_Layer/ecu_layer_init.h"
 /* Section : Macro Declerations */







 /* Section : Macro Functions Declerations */



 /* Section : Data Type Declerations */

    extern keypad_t kyp;
    extern chr_lcd_8bit lcd;
    extern stack_char_t stack_char;
    extern stack_float_t stack_evaulate;
    extern stack_char_t stack_balanced;
 
    
   
 /* Section : Functions Declerations */
    
    void infix_to_postfix(uint8 *infix, uint8 *postfix);
    void evaluate_postfix(uint8 *postfix ,  float *result);
    sint8 precedence(uint8 op);
    uint8 keypad_read_value();
    void Check_Balanced (uint8 *infix, sint8 *flag);
  
    





#endif	/* CALCULATOR_H */

