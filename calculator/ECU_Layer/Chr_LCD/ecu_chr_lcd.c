/* 
 * File:   ecu_chr_lcd.c
 * Author: doc
 *
 * Created on 12 ??????, 2024, 08:45 ?
 */

#include "ecu_chr_lcd.h"

static Std_ReturnType lcd_send_4bits(const chr_lcd_4bit *lcd, uint8 _data_command);
static Std_ReturnType lcd_4bits_send_enable_signal(const chr_lcd_4bit *lcd);
static Std_ReturnType lcd_8bits_send_enable_signal(const chr_lcd_8bit *lcd);
static Std_ReturnType lcd_8bit_set_cursor(const chr_lcd_8bit *lcd, uint8 row, uint8 column);
static Std_ReturnType lcd_4bit_set_cursor(const chr_lcd_4bit *lcd, uint8 row, uint8 column);


Std_ReturnType lcd_4bit_initialize(const chr_lcd_4bit *lcd){
    Std_ReturnType ret = E_OK;
    uint8 l_data_pins_counter = ZERO_INIT;
    if( NULL == lcd ){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_intialize(&(lcd->lcd_rs));
        ret = gpio_pin_intialize(&(lcd->lcd_en));
        for(l_data_pins_counter = ZERO_INIT ; l_data_pins_counter < 4 ; l_data_pins_counter++){
            ret =  gpio_pin_intialize(&(lcd->lcd_data[l_data_pins_counter]));
        }
        __delay_ms(20);
        ret = lcd_4bit_send_command(lcd ,_LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        ret = lcd_4bit_send_command(lcd ,_LCD_8BIT_MODE_2_LINE);
        __delay_us(150);
        ret = lcd_4bit_send_command(lcd ,_LCD_8BIT_MODE_2_LINE);
        
        ret = lcd_4bit_send_command(lcd , _LCD_CLEAR);
        ret = lcd_4bit_send_command(lcd , _LCD_RETURN_HOME);
        ret = lcd_4bit_send_command(lcd , _LCD_ENTRY_MODE_INC_SHIFT_OFF);
        ret = lcd_4bit_send_command(lcd , _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
        ret = lcd_4bit_send_command(lcd , _LCD_4BIT_MODE_2_LINE);
        ret = lcd_4bit_send_command(lcd , _LCD_DDRAM_START);
        
    }
     return ret;
}

Std_ReturnType lcd_4bit_send_command(const chr_lcd_4bit *lcd, uint8 command){
    Std_ReturnType ret = E_OK;
    if( NULL == lcd ){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(lcd->lcd_rs),GPIO_LOW);
        ret = lcd_send_4bits(lcd ,command >> 4);
        ret = lcd_4bits_send_enable_signal(lcd);
        ret = lcd_send_4bits(lcd ,command);
        ret = lcd_4bits_send_enable_signal(lcd);
    }
     return ret;
}

Std_ReturnType lcd_4bit_send_char_data(const chr_lcd_4bit *lcd, uint8 data){
    Std_ReturnType ret = E_OK;
    if( NULL == lcd ){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(lcd->lcd_rs),GPIO_HIGH);
        ret = lcd_send_4bits(lcd ,data >> 4);
        ret = lcd_4bits_send_enable_signal(lcd);
        ret = lcd_send_4bits(lcd ,data);
        ret = lcd_4bits_send_enable_signal(lcd);
    }
     return ret;
}

Std_ReturnType lcd_4bit_send_char_data_pos(const chr_lcd_4bit *lcd, uint8 row, uint8 column, uint8 data){
    Std_ReturnType ret = E_OK;
    if( NULL == lcd ){
        ret = E_NOT_OK;
    }
    else{
        ret = lcd_4bit_set_cursor(lcd, row, column);
        ret = lcd_4bit_send_char_data(lcd, data);
    }
     return ret;
}

Std_ReturnType lcd_4bit_send_string(const chr_lcd_4bit *lcd, uint8 *str){
    Std_ReturnType ret = E_OK;
    if( NULL == lcd ){
        ret = E_NOT_OK;
    }
    else{
        while(*str){
            ret = lcd_4bit_send_char_data(lcd,*str++);
        }
    }
     return ret;
}

Std_ReturnType lcd_4bit_send_string_pos(const chr_lcd_4bit *lcd, uint8 row, uint8 column, uint8 *str){
    Std_ReturnType ret = E_OK;
    if( NULL == lcd ){
        ret = E_NOT_OK;
    }
    else{
        ret = lcd_4bit_set_cursor(lcd, row, column);
       while(*str){
            ret = lcd_4bit_send_char_data(lcd,*str++);
        }
    }
     return ret;
}

Std_ReturnType lcd_4bit_send_custom_char(const chr_lcd_4bit *lcd, uint8 row, uint8 column, 
                                        const uint8 _chr[], uint8 mem_pos){
    Std_ReturnType ret = E_OK;
    uint8 lcd_counter = ZERO_INIT;
    if( NULL == lcd ){
        ret = E_NOT_OK;
    }
    else{
        ret = lcd_4bit_send_command(lcd, _LCD_CGRAM_START + (mem_pos * 8));
        for(lcd_counter = 0 ; lcd_counter < 7 ; ++lcd_counter){
            ret = lcd_4bit_send_char_data(lcd ,_chr[lcd_counter]);
        }
        ret = lcd_4bit_send_char_data_pos(lcd, row, column, mem_pos);
        
    }
     return ret;   
}


Std_ReturnType lcd_8bit_initialize(const chr_lcd_8bit *lcd){
    Std_ReturnType ret = E_OK;
    uint8 l_data_pins_counter = ZERO_INIT;
    if( NULL == lcd ){
        ret = E_NOT_OK;
    }
    else{
       ret = gpio_pin_intialize(&(lcd->lcd_rs));
        ret = gpio_pin_intialize(&(lcd->lcd_en));
        for(l_data_pins_counter = ZERO_INIT ; l_data_pins_counter < 8 ; l_data_pins_counter++){
            ret =  gpio_pin_intialize(&(lcd->lcd_data[l_data_pins_counter]));
        }
        __delay_ms(20);
        ret = lcd_8bit_send_command(lcd ,_LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        ret = lcd_8bit_send_command(lcd ,_LCD_8BIT_MODE_2_LINE);
        __delay_us(150);
        ret = lcd_8bit_send_command(lcd ,_LCD_8BIT_MODE_2_LINE);
        
        ret = lcd_8bit_send_command(lcd , _LCD_CLEAR);
        ret = lcd_8bit_send_command(lcd , _LCD_RETURN_HOME);
        ret = lcd_8bit_send_command(lcd , _LCD_ENTRY_MODE_INC_SHIFT_OFF);
        ret = lcd_8bit_send_command(lcd , _LCD_DISPLAY_OFF_CURSOR_OFF);
        ret = lcd_8bit_send_command(lcd , _LCD_8BIT_MODE_2_LINE);
        ret = lcd_8bit_send_command(lcd , _LCD_DDRAM_START);
    }
     return ret;
}

Std_ReturnType lcd_8bit_send_command(const chr_lcd_8bit *lcd, uint8 command){
    Std_ReturnType ret = E_OK;
    uint8 l_command_counter = ZERO_INIT;
    if( NULL == lcd ){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(lcd->lcd_rs), GPIO_LOW);
        for(l_command_counter = 0 ; l_command_counter < 8 ; ++l_command_counter){
            ret = gpio_pin_write_logic(&(lcd->lcd_data[l_command_counter]), (command >> l_command_counter) & (uint8) 0x01);
        }
        ret = lcd_8bits_send_enable_signal(lcd);
    }
     return ret;
}

Std_ReturnType lcd_8bit_send_char_data(const chr_lcd_8bit *lcd, uint8 data){
    Std_ReturnType ret = E_OK;
    uint8 l_data_counter = 0;
    if( NULL == lcd ){
        ret = E_NOT_OK;
    }
    else{
       ret = gpio_pin_write_logic(&(lcd->lcd_rs), GPIO_HIGH);
        for(l_data_counter = 0 ; l_data_counter < 8 ; ++l_data_counter){
            ret = gpio_pin_write_logic(&(lcd->lcd_data[l_data_counter]), (data >> l_data_counter) & (uint8) 0x01);
        }
        ret = lcd_8bits_send_enable_signal(lcd);
    }
     return ret;
}

Std_ReturnType lcd_8bit_send_char_data_pos(const chr_lcd_8bit *lcd, uint8 row, uint8 column, uint8 data){
    Std_ReturnType ret = E_OK;
    if( NULL == lcd ){
        ret = E_NOT_OK;
    }
    else{
        ret = lcd_8bit_set_cursor(lcd ,row, column);
        ret = lcd_8bit_send_char_data(lcd, data);
    }
     return ret;
}

Std_ReturnType lcd_8bit_send_string(const chr_lcd_8bit *lcd, uint8 *str){
    Std_ReturnType ret = E_OK;
    if( NULL == lcd ){
        ret = E_NOT_OK;
    }
    else{
        while(*str){
            ret = lcd_8bit_send_char_data(lcd,*str++);
        }
    }
     return ret;
}

Std_ReturnType lcd_8bit_send_string_pos(const chr_lcd_8bit *lcd, uint8 row, uint8 column, uint8 *str){
    Std_ReturnType ret = E_OK;
    if( NULL == lcd ){
        ret = E_NOT_OK;
    }
    else{
       ret = lcd_8bit_set_cursor(lcd, row, column);
       while(*str){
            ret = lcd_8bit_send_char_data(lcd,*str++);
        }
    }
     return ret;
}

Std_ReturnType lcd_8bit_send_custom_char(const chr_lcd_8bit *lcd, uint8 row, uint8 column,
                                         const uint8 _chr[], uint8 mem_pos){
 Std_ReturnType ret = E_OK;
 uint8 lcd_counter = ZERO_INIT;
    if( NULL == lcd ){
        ret = E_NOT_OK;
    }
    else{
        ret = lcd_8bit_send_command(lcd, _LCD_CGRAM_START + (mem_pos * 8));
        for(lcd_counter = 0 ; lcd_counter < 7 ; ++lcd_counter){
            ret = lcd_8bit_send_char_data(lcd ,_chr[lcd_counter]);
        }
        ret = lcd_8bit_send_char_data_pos(lcd, row, column, mem_pos);
        
    }
     return ret;   
}



Std_ReturnType convert_uint8_to_string(uint8 value, uint8 *str){
    Std_ReturnType ret = E_OK;
   if( NULL == str ){
        ret = E_NOT_OK;
    }
    else{
       memset(str,'\0',4);
       sprintf(str,"%i",value);
    }
     return ret;    
}

Std_ReturnType convert_uint16_to_string(uint16 value, uint8 *str){
   Std_ReturnType ret = E_OK;
   if( NULL == str ){
        ret = E_NOT_OK;
    }
    else{
       memset(str,'\0',6);
       sprintf(str,"%i",value);
    }
     return ret;   
}

Std_ReturnType convert_uint32_to_string(uint32 value, uint8 *str){
   Std_ReturnType ret = E_OK;
   if( NULL == str ){
        ret = E_NOT_OK;
    }
    else{
       memset(str,'\0',11);
       sprintf(str,"%i",value);
    }
     return ret;   
}

static Std_ReturnType lcd_send_4bits(const chr_lcd_4bit *lcd, uint8 _data_command){
     Std_ReturnType ret = E_OK;
     ret = gpio_pin_write_logic(&(lcd->lcd_data[0]), (_data_command >> 0) & (uint8)0x01);
     ret = gpio_pin_write_logic(&(lcd->lcd_data[1]), (_data_command >> 1) & (uint8)0x01);
     ret = gpio_pin_write_logic(&(lcd->lcd_data[2]), (_data_command >> 2) & (uint8)0x01);
     ret = gpio_pin_write_logic(&(lcd->lcd_data[3]), (_data_command >> 3) & (uint8)0x01);
     return ret;
}
static Std_ReturnType lcd_4bits_send_enable_signal(const chr_lcd_4bit *lcd){
    Std_ReturnType ret = E_OK;
    ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_HIGH);
    __delay_us(5);
    ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_LOW);
    return ret;
}
static Std_ReturnType lcd_8bits_send_enable_signal(const chr_lcd_8bit *lcd){
    Std_ReturnType ret = E_OK;
    ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_HIGH);
    __delay_us(5);
    ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_LOW);
    return ret;
}
static Std_ReturnType lcd_8bit_set_cursor(const chr_lcd_8bit *lcd, uint8 row, uint8 column){
    Std_ReturnType ret = E_OK;
    column --;
    switch(row){
        case Row1 : ret = lcd_8bit_send_command(lcd ,(0x80 + column));   break;  /*0x00 - > Decimal : 0 */ 
        case Row2 : ret = lcd_8bit_send_command(lcd ,(0xc0 + column));   break;  /*0x40 - > Decimal : 0 */ 
        case Row3 : ret = lcd_8bit_send_command(lcd ,(0x94 + column));   break;  /*0x14 - > Decimal : 0 */ 
        case Row4 : ret = lcd_8bit_send_command(lcd ,(0xd4 + column));   break;  /*0x54 - > Decimal : 0 */ 
        default : ;
    }
    return ret;
}

static Std_ReturnType lcd_4bit_set_cursor(const chr_lcd_4bit *lcd, uint8 row, uint8 column){
    Std_ReturnType ret = E_OK;
    column --;
    switch(row){
        case Row1 : ret = lcd_4bit_send_command(lcd ,(0x80 + column));   break;  /*0x00 - > Decimal : 0 */ 
        case Row2 : ret = lcd_4bit_send_command(lcd ,(0xc0 + column));   break;  /*0x40 - > Decimal : 0 */ 
        case Row3 : ret = lcd_4bit_send_command(lcd ,(0x94 + column));   break;  /*0x14 - > Decimal : 0 */ 
        case Row4 : ret = lcd_4bit_send_command(lcd ,(0xd4 + column));   break;  /*0x54 - > Decimal : 0 */ 
        default : ;
    }
    return ret;
}