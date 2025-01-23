/* 
 * File:   stack.h
 * Author: doc
 *
 * Created on 15 ??????, 2024, 04:33 ?
 */

#ifndef STACK_H
#define	STACK_H
 /* Section : Includes */
#include "../../MCAL_Layer/mcal_std_types.h"
 /* Section : Macro Declerations */
#define MAX_STACK   100

 /* Section : Macro Functions Declerations */


 /* Section : Data Type Declerations */
typedef struct{
  sint8 top;
  uint8 entry[MAX_STACK];
}stack_char_t; 

typedef struct{
  sint8 Top;
  float Entry[MAX_STACK];
}stack_float_t; 

 /* Section : Functions Declerations */

Std_ReturnType create_stack_char(stack_char_t *ps);
Std_ReturnType push_stack_char(stack_char_t *ps, sint8 value);
Std_ReturnType pop_stack_char(stack_char_t *ps, sint8 *value);
Std_ReturnType empty_stack_char(stack_char_t *ps);
Std_ReturnType size_stack_char(stack_char_t *ps, sint8 *size);
Std_ReturnType top_stack_char(stack_char_t *ps, sint8 *value);
Std_ReturnType clear_stack_char(stack_char_t *ps);
Std_ReturnType full_stack_char(stack_char_t *ps);

Std_ReturnType create_stack_float(stack_float_t *ps);
Std_ReturnType push_stack_float(stack_float_t *ps, float value);
Std_ReturnType pop_stack_float(stack_float_t *ps, float *value);
Std_ReturnType empty_stack_float(stack_float_t *ps);
Std_ReturnType size_stack_float(stack_float_t *ps, float *size);
Std_ReturnType top_stack_float(stack_float_t *ps, float *value);
Std_ReturnType clear_stack_float(stack_float_t *ps);
Std_ReturnType full_stack_float(stack_float_t *ps);




#endif	/* STACK_H */

