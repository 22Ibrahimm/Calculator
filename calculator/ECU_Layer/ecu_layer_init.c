/* 
 * File:   ecu_layer_init.c
 * Author: doc
 *
 * Created on 05 ??????, 2024, 12:23 ?
 */

#include "ecu_layer_init.h"

keypad_t kyp ={
  .keypad_row_pins[0].port = PORTC_INDEX,
  .keypad_row_pins[0].pin = GPIO_PIN0,
  .keypad_row_pins[0].direction = GPIO_DIRECTION_OUTPUT,
  .keypad_row_pins[0].logic = GPIO_LOW,
  .keypad_row_pins[1].port = PORTC_INDEX,
  .keypad_row_pins[1].pin = GPIO_PIN1,
  .keypad_row_pins[1].direction = GPIO_DIRECTION_OUTPUT,
  .keypad_row_pins[1].logic = GPIO_LOW,
  .keypad_row_pins[2].port = PORTC_INDEX,
  .keypad_row_pins[2].pin = GPIO_PIN2,
  .keypad_row_pins[2].direction = GPIO_DIRECTION_OUTPUT,
  .keypad_row_pins[2].logic = GPIO_LOW,
  .keypad_row_pins[3].port = PORTC_INDEX,
  .keypad_row_pins[3].pin = GPIO_PIN3,
  .keypad_row_pins[3].direction = GPIO_DIRECTION_OUTPUT,
  .keypad_row_pins[3].logic = GPIO_LOW,
  .keypad_columns_pins[0].port = PORTC_INDEX,
  .keypad_columns_pins[0].pin = GPIO_PIN4,
  .keypad_columns_pins[0].direction = GPIO_DIRECTION_INPUT,
  .keypad_columns_pins[0].logic = GPIO_LOW,
  .keypad_columns_pins[1].port = PORTC_INDEX,
  .keypad_columns_pins[1].pin = GPIO_PIN5,
  .keypad_columns_pins[1].direction = GPIO_DIRECTION_INPUT,
  .keypad_columns_pins[1].logic = GPIO_LOW,
  .keypad_columns_pins[2].port = PORTC_INDEX,
  .keypad_columns_pins[2].pin = GPIO_PIN6,
  .keypad_columns_pins[2].direction = GPIO_DIRECTION_INPUT,
  .keypad_columns_pins[2].logic = GPIO_LOW,
  .keypad_columns_pins[3].port = PORTC_INDEX,
  .keypad_columns_pins[3].pin = GPIO_PIN7,
  .keypad_columns_pins[3].direction = GPIO_DIRECTION_INPUT,
  .keypad_columns_pins[3].logic = GPIO_LOW,
  .keypad_columns_pins[4].port = PORTD_INDEX,
  .keypad_columns_pins[4].pin = GPIO_PIN0,
  .keypad_columns_pins[4].direction = GPIO_DIRECTION_INPUT,
  .keypad_columns_pins[4].logic = GPIO_LOW,
  .keypad_columns_pins[5].port = PORTD_INDEX,
  .keypad_columns_pins[5].pin = GPIO_PIN1,
  .keypad_columns_pins[5].direction = GPIO_DIRECTION_INPUT,
  .keypad_columns_pins[5].logic = GPIO_LOW,
     .keypad_columns_pins[6].port = PORTD_INDEX,
    .keypad_columns_pins[6].pin = GPIO_PIN4,
    .keypad_columns_pins[6].direction = GPIO_DIRECTION_INPUT,
    .keypad_columns_pins[6].logic = GPIO_LOW,
    .keypad_columns_pins[7].port = PORTD_INDEX,
    .keypad_columns_pins[7].pin = GPIO_PIN5,
    .keypad_columns_pins[7].direction = GPIO_DIRECTION_INPUT,
    .keypad_columns_pins[7].logic = GPIO_LOW,
    .keypad_columns_pins[8].port = PORTD_INDEX,
    .keypad_columns_pins[8].pin = GPIO_PIN6,
    .keypad_columns_pins[8].direction = GPIO_DIRECTION_INPUT,
    .keypad_columns_pins[8].logic = GPIO_LOW,
    .keypad_columns_pins[9].port = PORTD_INDEX,
    .keypad_columns_pins[9].pin = GPIO_PIN7,
    .keypad_columns_pins[9].direction = GPIO_DIRECTION_INPUT,
    .keypad_columns_pins[9].logic = GPIO_LOW

};

chr_lcd_8bit lcd = {
  .lcd_rs.port = PORTD_INDEX,
  .lcd_rs.pin = GPIO_PIN2,
  .lcd_rs.direction = GPIO_DIRECTION_OUTPUT,
  .lcd_rs.logic = GPIO_LOW,
  .lcd_en.port = PORTD_INDEX,
  .lcd_en.pin = GPIO_PIN3,
  .lcd_en.direction = GPIO_DIRECTION_OUTPUT,
  .lcd_en.logic = GPIO_LOW,
  .lcd_data[0].port = PORTB_INDEX,
  .lcd_data[0].pin = GPIO_PIN0,
  .lcd_data[0].direction = GPIO_DIRECTION_OUTPUT,
  .lcd_data[0].logic = GPIO_LOW,
  .lcd_data[1].port = PORTB_INDEX,
  .lcd_data[1].pin = GPIO_PIN1,
  .lcd_data[1].direction = GPIO_DIRECTION_OUTPUT,
  .lcd_data[1].logic = GPIO_LOW,
  .lcd_data[2].port = PORTB_INDEX,
  .lcd_data[2].pin = GPIO_PIN2,
  .lcd_data[2].direction = GPIO_DIRECTION_OUTPUT,
  .lcd_data[2].logic = GPIO_LOW,
  .lcd_data[3].port = PORTB_INDEX,
  .lcd_data[3].pin = GPIO_PIN3,
  .lcd_data[3].direction = GPIO_DIRECTION_OUTPUT,
  .lcd_data[3].logic = GPIO_LOW,
  .lcd_data[4].port = PORTB_INDEX,
  .lcd_data[4].pin = GPIO_PIN4,
  .lcd_data[4].direction = GPIO_DIRECTION_OUTPUT,
  .lcd_data[4].logic = GPIO_LOW,
  .lcd_data[5].port = PORTB_INDEX,
  .lcd_data[5].pin = GPIO_PIN5,
  .lcd_data[5].direction = GPIO_DIRECTION_OUTPUT,
  .lcd_data[5].logic = GPIO_LOW,
  .lcd_data[6].port = PORTB_INDEX,
  .lcd_data[6].pin = GPIO_PIN6,
  .lcd_data[6].direction = GPIO_DIRECTION_OUTPUT,
  .lcd_data[6].logic = GPIO_LOW,
  .lcd_data[7].port = PORTB_INDEX,
  .lcd_data[7].pin = GPIO_PIN7,
  .lcd_data[7].direction = GPIO_DIRECTION_OUTPUT,
  .lcd_data[7].logic = GPIO_LOW
};



stack_char_t stack_char;
stack_float_t stack_evaulate;
stack_char_t stack_balanced;

        
void ecu_layer_intialize (void){
Std_ReturnType ret = E_NOT_OK;
ret = keypad_intialize(&kyp);
ret = lcd_8bit_initialize(&lcd);
ret = create_stack_char(&stack_char);
ret = create_stack_float(&stack_evaulate);
ret = create_stack_char(&stack_balanced);

}