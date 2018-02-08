#ifndef LCD_H_
#include <stdbool.h>
#define LCD_H_
#define LCD_PORT uart2

extern bool buttonPressed[];
extern bool buttonUp[];
extern bool buttonDown[];
extern int selectedAutonomous;

void update_lcd_buttons();
void write_text(char* c1, char* c2);

#endif
