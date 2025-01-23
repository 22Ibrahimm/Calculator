/* 
 * File:   stack.c
 * Author: doc
 *
 * Created on 15 ??????, 2024, 04:33 ?
 */

#include "stack.h"

Std_ReturnType create_stack_char(stack_char_t *ps){
    Std_ReturnType ret = E_OK;
    if(NULL == ps){
        ret = E_NOT_OK;
    }
    else{
        ps->top = 0;
    }
    return ret;
}

Std_ReturnType push_stack_char(stack_char_t *ps, sint8 value){
    Std_ReturnType ret = E_OK;
    if(NULL == ps){
        ret = E_NOT_OK;
    }
    else{
        ps->entry[ps->top++] = value;
    }
    return ret;
}

Std_ReturnType pop_stack_char(stack_char_t *ps, sint8 *value){
     Std_ReturnType ret = E_OK;
    if((NULL == ps) || (NULL == value)){
        ret = E_NOT_OK;
    }
    else{
       *value = ps->entry[--ps->top];
    }
    return ret;
}

Std_ReturnType empty_stack_char(stack_char_t *ps){
     Std_ReturnType ret = E_OK;
    if(NULL == ps){
        ret = E_NOT_OK;
    }
    else{
         if (ps->top == 0){
            ret = E_OK;  
        } else {
            ret = E_NOT_OK; 
        }
    }
    return ret;
}
Std_ReturnType size_stack_char(stack_char_t *ps, sint8 *size){
    Std_ReturnType ret = E_OK;
    if((NULL == ps) || (NULL == size)){
        ret = E_NOT_OK;
    }
    else{
        *size = ps->top;
    }
    return ret;
}

Std_ReturnType top_stack_char(stack_char_t *ps, sint8 *value){
     Std_ReturnType ret = E_OK;
    if((NULL == ps) || (NULL == value)){
        ret = E_NOT_OK;
    }
    else{
        *value = ps->entry[ps->top - 1];
    }
    return ret;
}
Std_ReturnType clear_stack_char(stack_char_t *ps){
    Std_ReturnType ret = E_OK;
    if(NULL == ps){
        ret = E_NOT_OK;
    }
    else{
        ps->top = 0;
    }
    return ret;
}
Std_ReturnType full_stack_char(stack_char_t *ps){
    Std_ReturnType ret = E_OK;
    if(NULL == ps){
        ret = E_NOT_OK;
    }
    else{
       if (ps->top >= MAX_STACK) {
            ret = E_NOT_OK;  
        } else {
            ret = E_OK;  
        }
    }
    return ret;    
}

Std_ReturnType create_stack_float(stack_float_t *ps){
    Std_ReturnType ret = E_OK;
    if(NULL == ps){
        ret = E_NOT_OK;
    }
    else{
        ps->Top = 0;
    }
    return ret;
}

Std_ReturnType push_stack_float(stack_float_t *ps, float value){
    Std_ReturnType ret = E_OK;
    if(NULL == ps){
        ret = E_NOT_OK;
    }
    else{
        ps->Entry[ps->Top++] = value;
    }
    return ret;
}

Std_ReturnType pop_stack_float(stack_float_t *ps, float *value){
    Std_ReturnType ret = E_OK;
    if((NULL == ps) || (NULL == value)){
        ret = E_NOT_OK;
    }
    else{
       *value = ps->Entry[--ps->Top];
    }
    return ret;
}

Std_ReturnType empty_stack_float(stack_float_t *ps){
    Std_ReturnType ret = E_OK;
    if(NULL == ps){
        ret = E_NOT_OK;
    }
    else{
         if (ps->Top == 0){
            ret = E_OK;  
        } else {
            ret = E_NOT_OK; 
        }
    }
    return ret;
}

Std_ReturnType size_stack_float(stack_float_t *ps, float *size){
    Std_ReturnType ret = E_OK;
    if((NULL == ps) || (NULL == size)){
        ret = E_NOT_OK;
    }
    else{
        *size = ps->Top;
    }
    return ret;
}

Std_ReturnType top_stack_float(stack_float_t *ps, float *value){
     Std_ReturnType ret = E_OK;
    if((NULL == ps) || (NULL == value)){
        ret = E_NOT_OK;
    }
    else{
        *value = ps->Entry[ps->Top - 1];
    }
    return ret;
}

Std_ReturnType clear_stack_float(stack_float_t *ps){
    Std_ReturnType ret = E_OK;
    if(NULL == ps){
        ret = E_NOT_OK;
    }
    else{
        ps->Top = 0;
    }
    return ret;
}

Std_ReturnType full_stack_float(stack_float_t *ps){
    Std_ReturnType ret = E_OK;
    if(NULL == ps){
        ret = E_NOT_OK;
    }
    else{
       if (ps->Top >= MAX_STACK) {
            ret = E_NOT_OK;  
        } else {
            ret = E_OK;  
        }
    }
    return ret; 
}

