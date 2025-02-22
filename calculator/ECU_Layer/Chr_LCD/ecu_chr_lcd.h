/* 
 * File:   ecu_chr_lcd.h
 * Author: doc
 *
 * Created on 12 ??????, 2024, 08:45 ?
 */

#ifndef ECU_CHR_LCD_H
#define	ECU_CHR_LCD_H

 /* Section : Includes */

#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_chr_lcd_cfg.h"

 /* Section : Macro Declerations */
#define _LCD_CLEAR                                     0x01
#define _LCD_RETURN_HOME                               0x02
#define _LCD_ENTRY_MODE_DEC_SHIFT_OFF                  0x04
#define _LCD_ENTRY_MODE_DEC_SHIFT_ON                   0x05
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF                  0x06
#define _LCD_ENTRY_MODE_INC_SHIFT_ON                   0x07
#define _LCD_CURSOR_MOVE_SHIFT_LEFT                    0x10
#define _LCD_CURSOR_MOVE_SHIFT_RIGHT                   0x14
#define _LCD_DISPLAY_SHIFT_LEFT                        0x18
#define _LCD_DISPLAY_SHIFT_RIGHT                       0x1C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF       0x0C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON        0x0D
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF        0x0E
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON         0x0F
#define _LCD_DISPLAY_OFF_CURSOR_OFF                    0x08
#define _LCD_8BIT_MODE_2_LINE                          0x38
#define _LCD_4BIT_MODE_2_LINE                          0x28

#define _LCD_CGRAM_START                                0x40
#define _LCD_DDRAM_START                                0x80



#define Row1    1
#define Row2    2
#define Row3    3
#define Row4    4







 /* Section : Macro Functions Declerations */



 /* Section : Data Type Declerations */
typedef struct{
    pin_config_t lcd_rs;
    pin_config_t lcd_en;
    pin_config_t lcd_data[4];
}chr_lcd_4bit;

typedef struct{
    pin_config_t lcd_rs;
    pin_config_t lcd_en;
    pin_config_t lcd_data[8];
}chr_lcd_8bit;


 /* Section : Functions Declerations */
Std_ReturnType lcd_4bit_initialize(const chr_lcd_4bit *lcd);
Std_ReturnType lcd_4bit_send_command(const chr_lcd_4bit *lcd, uint8 command);
Std_ReturnType lcd_4bit_send_char_data(const chr_lcd_4bit *lcd, uint8 data);
Std_ReturnType lcd_4bit_send_char_data_pos(const chr_lcd_4bit *lcd, uint8 row, uint8 column, uint8 data);
Std_ReturnType lcd_4bit_send_string(const chr_lcd_4bit *lcd, uint8 *str);
Std_ReturnType lcd_4bit_send_string_pos(const chr_lcd_4bit *lcd, uint8 row, uint8 column, uint8 *str);
Std_ReturnType lcd_4bit_send_custom_char(const chr_lcd_4bit *lcd, uint8 row, uint8 column,
                                        const uint8 _chr[], uint8 mem_pos);

Std_ReturnType lcd_8bit_initialize(const chr_lcd_8bit *lcd);
Std_ReturnType lcd_8bit_send_command(const chr_lcd_8bit *lcd, uint8 command);
Std_ReturnType lcd_8bit_send_char_data(const chr_lcd_8bit *lcd, uint8 data);
Std_ReturnType lcd_8bit_send_char_data_pos(const chr_lcd_8bit *lcd, uint8 row, uint8 column, uint8 data);
Std_ReturnType lcd_8bit_send_string(const chr_lcd_8bit *lcd, uint8 *str);
Std_ReturnType lcd_8bit_send_string_pos(const chr_lcd_8bit *lcd, uint8 row, uint8 column, uint8 *str);
Std_ReturnType lcd_8bit_send_custom_char(const chr_lcd_8bit *lcd, uint8 row, uint8 column,
                                         const uint8 _chr[], uint8 mem_pos);


Std_ReturnType convert_uint8_to_string(uint8 value, uint8 *str);
Std_ReturnType convert_uint16_to_string(uint16 value, uint8 *str);
Std_ReturnType convert_uint32_to_string(uint32 value, uint8 *str);





#endif	/* ECU_CHR_LCD_H */

