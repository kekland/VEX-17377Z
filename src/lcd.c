#include "main.h"
#include "lcd.h"
bool buttonPressed[3] = {false, false, false};
bool buttonNewStates[3] = {false, false, false};
bool buttonDown[3] = {false, false, false};
bool buttonUp[3] = {false, false, false};

char* saved_c1 = "";
char* saved_c2 = "";
void update_lcd_buttons() {
  int buttons = lcdReadButtons(LCD_PORT);
  buttonNewStates[0] = (buttons & 1) == 1;
  buttonNewStates[1] = (buttons & 2) == 2;
  buttonNewStates[2] = (buttons & 4) == 4;

  for(int i = 0; i < 3; i++) {
    buttonUp[i] = false;
    buttonDown[i] = false;
    if(buttonPressed[i] && !buttonNewStates[i]) {
      buttonUp[i] = true;
    }
    else if(!buttonPressed[i] && buttonNewStates[i]) {
      buttonDown[i] = true;
    }
    buttonPressed[i] = buttonNewStates[i];
  }
  //test
}

void write_text(char* c1, char* c2) {
  if(c1 != saved_c1) {
    saved_c1 = c1;
    lcdSetText(LCD_PORT, 1, c1);
  }
  if(c2 != saved_c2) {
    saved_c2 = c2;
    lcdSetText(LCD_PORT, 2, c2);
  }
}
