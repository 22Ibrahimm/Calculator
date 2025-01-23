/* 
 * File:   Calculator.c
 * Author: doc
 *
 * Created on 25 ??????, 2024, 07:14 ?
 */
#include "Calculator.h"

uint8 keypad_read_value() {
    Std_ReturnType ret = E_NOT_OK;
    uint8 keypad_pressed_value = ZERO_INIT;
    do {
        __delay_ms(20);  
        ret = keypad_get_value(&kyp, &keypad_pressed_value); 
    } while (0 == keypad_pressed_value);  
    __delay_ms(20); 
    return keypad_pressed_value;  
}



sint8 precedence(uint8 op) {
    if (op == 'E' || op == 'R' || op == 'T' 
     || op == 'P' || op == 'K' || op == 'Y' 
     || op == 'U' || op == 'I' || op == '@' 
     || op == 'A' || op == 'S' || op == 'D'
     || op == 'W')                           return 4;
    if (op == '^')                           return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-' || op == '_') return 1;
    return 0;
}

void infix_to_postfix(uint8 *infix, uint8 *postfix){
    uint8 l_counter = ZERO_INIT;
    uint8 index_postfix = ZERO_INIT;
    sint8 previous_operator = 1;
    
    for(l_counter = 0 ; infix[l_counter] != '\0' ; l_counter++){
        uint8 variable = infix[l_counter];
        
       if(isdigit(variable) || variable == ' ' ||  variable == '.'){
            postfix[index_postfix++] = variable;
             previous_operator = 0;
        } 
        else if(variable == '-' && (l_counter == 0 || infix[l_counter - 1] == '(' || previous_operator)){ 
            postfix[index_postfix++] = variable;
            previous_operator = 0;
        } 
        
        else if('(' == variable){
            push_stack_char(&stack_char, variable);
        }
        else if (')' == variable) {
            uint8 _top;
            if (!empty_stack_char(&stack_char)) {
                do {
                    pop_stack_char(&stack_char, &_top);
                    if (_top != '(') {
                        postfix[index_postfix++] = _top;
                    }
                } while (!empty_stack_char(&stack_char) && _top != '(');
            }
        } 
       else {
            uint8 _top;
            while (!empty_stack_char(&stack_char)) {
                top_stack_char(&stack_char, &_top);
                if (precedence(_top) >= precedence(variable)) {
                    pop_stack_char(&stack_char, &_top);
                    postfix[index_postfix++] = _top;
                } else {
                    break; 
                }
            }
            push_stack_char(&stack_char, variable);
             previous_operator = 1;
        }
    }
    
            uint8 top_token;
            while (!empty_stack_char(&stack_char)) {
            pop_stack_char(&stack_char, &top_token);
            postfix[index_postfix++] = top_token;
    }
    postfix[index_postfix] = '\0';
} 

void evaluate_postfix(uint8 *postfix, float *result) {
    uint8 l_counter = ZERO_INIT;
    float operand1 = ZERO_INIT, operand2 = ZERO_INIT, eval_result = ZERO_INIT;
    float temp_num = ZERO_INIT;
    sint8 number_found = ZERO_INIT;
    sint8 is_negative = ZERO_INIT;
    float fractional_part = ZERO_INIT;  
    sint8 divisor = 1;

    for (l_counter = 0; postfix[l_counter] != '\0'; l_counter++) {
        uint8 variable = postfix[l_counter];

     
        if (variable == '-' && !number_found && (l_counter == 0 || postfix[l_counter - 1] == ' ')) {
            is_negative = 1;
        }
        
        else if (isdigit(variable) || variable == '.') {
            if (variable == '.') {
                fractional_part = 0; 
                divisor = 10;
            } else {
                if (divisor == 1) { 
                    temp_num = temp_num * 10 + (variable - '0');
                } else { 
                    fractional_part += (float)(variable - '0') / divisor;
                    divisor *= 10;
                }
            }
            number_found = 1;
        }
        else if (variable == ' ' && number_found) {
            if (is_negative) {
                temp_num = -temp_num;
                is_negative = 0;
            }
            
            temp_num += fractional_part;  
            
            push_stack_float(&stack_evaulate, temp_num);  
            temp_num = 0;  
            number_found = 0;
            divisor = 1;   
            fractional_part = 0; 
        }

        else {
            if('E' == variable){
                  pop_stack_float(&stack_evaulate, &operand1);
                  eval_result = sin(operand1 * (M_PI / 180.0));
                  push_stack_float(&stack_evaulate, eval_result);
            }
            else if('R' == variable){
                  pop_stack_float(&stack_evaulate, &operand1);
                  eval_result = cos(operand1 * (M_PI / 180.0));
                  push_stack_float(&stack_evaulate, eval_result);
            }
            else if('T' == variable){
                  pop_stack_float(&stack_evaulate, &operand1);
                  eval_result = tan(operand1 * (M_PI / 180.0));
                  push_stack_float(&stack_evaulate, eval_result);
            }
            else if('P' == variable){
                  pop_stack_float(&stack_evaulate, &operand1);
                  eval_result = atan(operand1);
                  eval_result *= 180.0 / M_PI ;
                  push_stack_float(&stack_evaulate, eval_result);
            }
            else if('K' == variable){
                  pop_stack_float(&stack_evaulate, &operand1);
                  eval_result = asin(operand1);
                  eval_result *= 180.0 / M_PI ;
                  push_stack_float(&stack_evaulate, eval_result);
            } 
            else if('A' == variable){
                  pop_stack_float(&stack_evaulate, &operand1);
                  eval_result = acos(operand1);
                  eval_result *= 180.0 / M_PI ;
                  push_stack_float(&stack_evaulate, eval_result);
            }
            else if('Y' == variable){
                  pop_stack_float(&stack_evaulate, &operand1);
                  eval_result = sinh(operand1);
                  push_stack_float(&stack_evaulate, eval_result);
            }
            else if('U' == variable){
                  pop_stack_float(&stack_evaulate, &operand1);
                  eval_result = cosh(operand1);
                  push_stack_float(&stack_evaulate, eval_result);
            }
            else if('I' == variable){
                  pop_stack_float(&stack_evaulate, &operand1);
                  eval_result = tanh(operand1);
                  push_stack_float(&stack_evaulate, eval_result);
            }
            else if('@' == variable){
                  pop_stack_float(&stack_evaulate, &operand1);
                  eval_result = sqrtf(operand1);
                  push_stack_float(&stack_evaulate, eval_result);
            }
            else if('S' == variable){
                  pop_stack_float(&stack_evaulate, &operand1);
                  eval_result = cbrt(operand1);
                  push_stack_float(&stack_evaulate, eval_result);
            }
            else if('D' == variable){
                  pop_stack_float(&stack_evaulate, &operand1);
                  eval_result = log(operand1);
                  push_stack_float(&stack_evaulate, eval_result);
            }
            else{
            pop_stack_float(&stack_evaulate, &operand2);
            pop_stack_float(&stack_evaulate, &operand1);

            switch (variable) {
                case '+': eval_result = operand1 + operand2;      break;
                case '_': eval_result = operand1 - operand2;      break;
                case '%': eval_result = fmod(operand1, operand2); break;
                case '*': eval_result = operand1 * operand2;      break;
                case '/':
                    if (operand2 == 0) {
                        *result = -1;  
                        return;
                    }
                    eval_result = operand1 / operand2;
                    break;
                    
                case '^':  
                    eval_result = pow(operand1, operand2); 
                    break;

                default:
                    *result = -1; 
                    return;
            }

            push_stack_float(&stack_evaulate, eval_result);  
        }
        }
    }

    if (!empty_stack_float(&stack_evaulate)) {
        pop_stack_float(&stack_evaulate, &eval_result);
    }

    *result = eval_result;  
}


void Check_Balanced (uint8 *infix, sint8 *flag){
    uint8 l_counter = ZERO_INIT;
    sint8 value = ZERO_INIT;
   
    for(l_counter = 0 ; infix[l_counter] != '\0' ; l_counter++){
        if('(' == infix[l_counter]){
            push_stack_char(&stack_balanced , &infix[l_counter]);
        }
        else if(')' == infix[l_counter]){   
            if(empty_stack_char(&stack_balanced)){
                *flag = -1;  
                return;
            }
            pop_stack_char(&stack_balanced , &value);
        }
    }
    if (!empty_stack_char(&stack_balanced)) {
        *flag = -1;  
    } else {
        *flag = 0;   
    }
    
}
