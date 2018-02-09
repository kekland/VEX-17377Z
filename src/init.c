/** @file init.c
 * @brief File for initialization code
 *
 * This file should contain the user initialize() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "lcd.h"
/*
 * Runs pre-initialization code. This function will be started in kernel mode one time while the
 * VEX Cortex is starting up. As the scheduler is still paused, most API functions will fail.
 *
 * The purpose of this function is solely to set the default pin modes (pinMode()) and port
 * states (digitalWrite()) of limit switches, push buttons, and solenoids. It can also safely
 * configure a UART port (usartOpen()) but cannot set up an LCD (lcdInit()).
 */
void initializeIO() {

}
int selectedAutonomous = -1;
int currentPage = 0;
int maxPages = 3;
int autonomousCount = 2;
char* autonomousNames[] = {"Auto 1", "Auto 2"};
/*
 * Runs user initialization code. This function will be started in its own task with the default
 * priority and stack size once when the robot is starting up. It is possible that the VEXnet
 * communication link may not be fully established at this time, so reading from the VEX
 * Joystick may fail.
 *
 * This function should initialize most sensors (gyro, encoders, ultrasonics), LCDs, global
 * variables, and IMEs.
 *
 * This function must exit relatively promptly, or the operatorControl() and autonomous() tasks
 * will not start. An autonomous mode selection menu like the pre_auton() in other environments
 * can be implemented in this task if desired.
 */

void lcd_clicked(int direction) {
  if(direction == 0 && currentPage < autonomousCount) {
    if(selectedAutonomous == -1) {
      selectedAutonomous = currentPage;
    }
    else {
      selectedAutonomous = -1;
    }
    return;
  }


  if(currentPage + direction >= 0 && currentPage + direction < maxPages) {
    currentPage += direction;
  }
}

void show_lcd_page() {
  //________________
  //Auto 1
  //
  //PWR_MAIN:40002mV
  //PWR_BACK:0mV
  if(selectedAutonomous != -1) {
    write_text("SELECTED: ", autonomousNames[selectedAutonomous]);
    return;
  }
  if(currentPage < autonomousCount) {
    write_text(autonomousNames[currentPage], "<    SELECT    >");
  }
  else if(currentPage >= autonomousCount) {
    int pageIndex = autonomousCount - currentPage;
    if(pageIndex == 0) {
      char mainPowerLevel[16]; itoa(powerLevelMain(), mainPowerLevel, 10);
      char backupPowerLevel[16]; itoa(powerLevelBackup(), backupPowerLevel, 10);
      write_text(mainPowerLevel, backupPowerLevel);
    }
  }
}

void initialize() {
  while(!isEnabled()) {
    update_lcd_buttons();
    if(buttonUp[1]) {
      lcd_clicked(0);
    }
    else if(buttonUp[0]) {
      lcd_clicked(-1);
    }
    else if(buttonUp[2]) {
      lcd_clicked(1);
    }
    show_lcd_page();
  }
  if(selectedAutonomous == -1) {
    selectedAutonomous = 0;
  }
}
