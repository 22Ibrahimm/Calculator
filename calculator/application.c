/* 
 * File:   application.c
 * Author: doc
 *
 * Created on 07 ??????, 2024, 11:23 ?
 */



#include "application.h"

uint8 keypad_value = ZERO_INIT;
uint8 flag1 = ZERO_INIT;
uint8 infix[100] = {0};
uint8 postfix[100] = {0};
uint8 index = ZERO_INIT;
float result = ZERO_INIT;
float number = ZERO_INIT;      
uint8 collecting = ZERO_INIT;   
uint8  lcd_cursor = ZERO_INIT;
uint8 keypad_value_processed = ZERO_INIT;  
uint8 fractional_mode = ZERO_INIT ;
float fractional_multiplier = 0.1;
float Ans = ZERO_INIT;
sint8 balance = ZERO_INIT;
uint8 is_display_on = ZERO_INIT;

int main() { 
    Std_ReturnType ret = E_NOT_OK;
    application_intialize();
    
       
    
 while (1) {
     

  keypad_value = keypad_read_value();  

    
    if (keypad_value_processed){
        continue;  
    }
    
     if (!is_display_on && keypad_value != '$') {
        continue;
    }
  
    
    if ('C' == keypad_value){  
        ret = lcd_8bit_send_command(&lcd, _LCD_CLEAR);  
        keypad_value_processed = 1;  
    } 
    else if (isdigit(keypad_value) || '.' == keypad_value){ 
        if (keypad_value == '.'){  
            if (!fractional_mode){  
                 fractional_mode = 1;
                 fractional_multiplier = 0.1;  
                 ret = lcd_8bit_send_char_data_pos(&lcd, 1, ++lcd_cursor, keypad_value); 
                  keypad_value_processed = 1;  
            }
        }
        else{
             if (fractional_mode){
                  number += (keypad_value - '0') * fractional_multiplier;
                  fractional_multiplier /= 10.0;
             }
             else{
                 number = number * 10 + (keypad_value - '0'); 
             }
        collecting = 1;
        ret = lcd_8bit_send_char_data_pos(&lcd, 1, ++lcd_cursor, keypad_value);  
        keypad_value_processed = 1;  
      
        }
    } 
    else if ((keypad_value == '+')||( keypad_value == '-') ||(keypad_value == '*')
          || (keypad_value == '%')||(keypad_value == '_') || (keypad_value == '^')
          || (keypad_value == '/' )|| (keypad_value == '(') ||(keypad_value == ')')){
        if (collecting) { 
            sprintf(&infix[index], "%.6f ", number); 
            index += strlen(&infix[index]);     
            collecting = 0;
            fractional_mode = 0;  
            fractional_multiplier = 0.1;  
            number = 0; 
        }
        infix[index++] = keypad_value;  
        ret = lcd_8bit_send_char_data_pos(&lcd, 1, ++lcd_cursor, keypad_value); 
        keypad_value_processed = 1;  
      
    } 
    else if ('=' == keypad_value){  
        if (collecting){ 
            sprintf(&infix[index], "%.6f ", number);
            index += strlen(&infix[index]);
            collecting = 0;
            fractional_mode = 0;  
            fractional_multiplier = 0.1;  
            number = 0; 
        }
        Check_Balanced(infix,&balance);     
        infix_to_postfix(infix, postfix);
        evaluate_postfix(postfix, &result);
         if ((result == -1) ||(balance == 1)) {
            uint8 error_msg[20] = "Syntax ERROR";
            ret = lcd_8bit_send_command(&lcd, _LCD_CLEAR);  
            lcd_8bit_send_string_pos(&lcd, 1, 1, error_msg);
        } 
        else {
            uint8 result_str[20] = {0};
            sprintf(result_str, "=%.6f", result);
            lcd_8bit_send_string_pos(&lcd, 2, 1, result_str);
        }
        
        Ans = result;
        lcd_cursor = 0;
        index = 0; 
        keypad_value_processed = 1;  
    }
         else if(keypad_value == 'E'){
            infix[index++] = keypad_value;

             uint8 sin_msg[20] = "sin(";
            lcd_8bit_send_string_pos(&lcd, 1,++lcd_cursor, sin_msg);
            lcd_cursor += strlen(sin_msg) - 1;
           keypad_value_processed = 1;
        }
         else if(keypad_value == 'R'){
            infix[index++] = keypad_value;

             uint8 cos_msg[20] = "cos(";
            lcd_8bit_send_string_pos(&lcd, 1,++lcd_cursor, cos_msg);
            lcd_cursor += strlen(cos_msg) - 1;
           keypad_value_processed = 1;
        }
            else if(keypad_value == 'T'){
            infix[index++] = keypad_value;

             uint8 tan_msg[20] = "tan(";
            lcd_8bit_send_string_pos(&lcd, 1,++lcd_cursor, tan_msg);
            lcd_cursor += strlen(tan_msg) - 1;
           keypad_value_processed = 1;
        }
            else if(keypad_value == 'P'){
            infix[index++] = keypad_value;

             uint8 tan__msg[20] = "tan-1(";
            lcd_8bit_send_string_pos(&lcd, 1,++lcd_cursor, tan__msg);
            lcd_cursor += strlen(tan__msg) - 1;
           keypad_value_processed = 1;
        }
            else if(keypad_value == 'Y'){
            infix[index++] = keypad_value;

             uint8 sinh_msg[20] = "sinh(";
            lcd_8bit_send_string_pos(&lcd, 1,++lcd_cursor, sinh_msg);
            lcd_cursor += strlen(sinh_msg) - 1;
           keypad_value_processed = 1;
        }
            else if(keypad_value == 'U'){
            infix[index++] = keypad_value;

             uint8 cosh_msg[20] = "cosh(";
            lcd_8bit_send_string_pos(&lcd, 1,++lcd_cursor, cosh_msg);
            lcd_cursor += strlen(cosh_msg) - 1;
           keypad_value_processed = 1;
        }
            else if(keypad_value == 'I'){
            infix[index++] = keypad_value;

             uint8 tanh_msg[20] = "tanh(";
            lcd_8bit_send_string_pos(&lcd, 1,++lcd_cursor, tanh_msg);
            lcd_cursor += strlen(tanh_msg) - 1;
           keypad_value_processed = 1;
        }
            else if(keypad_value == 'K'){
            infix[index++] = keypad_value;

             uint8 sin__msg[20] = "sin-1(";
            lcd_8bit_send_string_pos(&lcd, 1,++lcd_cursor, sin__msg);
            lcd_cursor += strlen(sin__msg) - 1;
           keypad_value_processed = 1;
        }
            else if(keypad_value == '@'){
            infix[index++] = keypad_value;

             uint8 sqrt_msg[20] = "sqrt(";
            lcd_8bit_send_string_pos(&lcd, 1,++lcd_cursor, sqrt_msg);
            lcd_cursor += strlen(sqrt_msg) - 1;
           keypad_value_processed = 1;
        }
            else if(keypad_value == 'A'){
            infix[index++] = keypad_value;

             uint8 cos__msg[20] = "cos-1(";
            lcd_8bit_send_string_pos(&lcd, 1,++lcd_cursor, cos__msg);
            lcd_cursor += strlen(cos__msg) - 1;
           keypad_value_processed = 1;
        }
             else if(keypad_value == 'S'){
            infix[index++] = keypad_value;

             uint8 cprt_msg[20] = "cbrt(";
            lcd_8bit_send_string_pos(&lcd, 1,++lcd_cursor, cprt_msg);
            lcd_cursor += strlen(cprt_msg) - 1;
           keypad_value_processed = 1;
        }
            else if(keypad_value == 'D'){
            infix[index++] = keypad_value;

             uint8 log_msg[20] = "log(";
            lcd_8bit_send_string_pos(&lcd, 1,++lcd_cursor, log_msg);
            lcd_cursor += strlen(log_msg) - 1;
           keypad_value_processed = 1;
        }
             else if(keypad_value == 'W'){
         ret = lcd_8bit_send_command(&lcd, _LCD_CLEAR); 
          uint8 result_str[20] = {0};
         sprintf((char*)result_str, "%.2f", Ans);
         lcd_8bit_send_string_pos(&lcd, 1, 1, result_str);
         
         sprintf((char*)&infix[index], "%.6f ", Ans);
         index += strlen((char*)&infix[index]);
          lcd_cursor = strlen(result_str); 
         keypad_value_processed = 1;
                 }
            else if(keypad_value == '<'){
                lcd_8bit_send_command(&lcd, 0x10);
                lcd_cursor--; 
                keypad_value_processed = 1;
                  }
            else if(keypad_value == '>'){
               lcd_8bit_send_command(&lcd, 0x14);
               lcd_cursor++; 
               keypad_value_processed = 1;
                  }
            else if(keypad_value == '$'){
               ret = lcd_8bit_send_command(&lcd, _LCD_CLEAR); 
               ret = lcd_8bit_send_command(&lcd, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON);  
                is_display_on = 1; 
               keypad_value_processed = 1;
            }      
                   else if(keypad_value == '#'){
               ret = lcd_8bit_send_command(&lcd, _LCD_CLEAR); 
               ret = lcd_8bit_send_command(&lcd, _LCD_DISPLAY_OFF_CURSOR_OFF);  
                is_display_on = 0; 
               keypad_value_processed = 1;
               
            }      

  

       
   
   
    __delay_ms(200);  
    keypad_value_processed = 0; 
 
}
   
    
    return (EXIT_SUCCESS);
} 



void application_intialize (void){
Std_ReturnType ret = E_NOT_OK;
     ecu_layer_intialize();
}





