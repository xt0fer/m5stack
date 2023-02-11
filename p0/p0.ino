
// p zero script.

#include <M5Core2.h>


void setup() {
  M5.begin();        // Init M5Core. 

  // M5.Lcd.setTextColor(YELLOW);
  // M5.Lcd.setTextSize(3);
  // M5.Lcd.println("Zip Code Wilmington");
  // M5.Lcd.println("Take 2");

  // M5.Lcd.print("Kristofer Younger - Aeneid");  // Print text on the screen (string)

  M5.Lcd.setTextColor(
      YELLOW);  //Set the font color to yellow. 
  M5.Lcd.setTextSize(2);  //Set the font size
  M5.Lcd.setCursor(
      65, 10);  //Move the cursor position to (x, y). 
  M5.Lcd.println(
      "Aeneid");  //The screen prints the formatted string and wraps the line.  
  M5.Lcd.setCursor(3, 35);
  M5.Lcd.println("Press button B for 700ms");
  M5.Lcd.println("to clear screen.");
  M5.Lcd.setTextColor(RED);

}


void loop() {
    M5.update();  //Read the press state of the key.  读取按键 A, B, C 的状态
  if (M5.BtnA.wasReleased() || M5.BtnA.pressedFor(1000, 200)) {
    M5.Lcd.print('A');
  } else if (M5.BtnB.wasReleased() || M5.BtnB.pressedFor(1000, 200)) {
    M5.Lcd.print('B');
  } else if (M5.BtnC.wasReleased() || M5.BtnC.pressedFor(1000, 200)) {
    M5.Lcd.print('C');
  } else if (M5.BtnB.wasReleasefor(700)) {
    M5.Lcd.clear(
        WHITE);  // Clear the screen and set white to the background color. 
    M5.Lcd.setCursor(0, 0);
  }
}