
// p zero script.

#include <M5Core2.h>


void setup() {
  M5.begin();        // Init M5Core.  初始化 M5Core

  M5.Lcd.setTextColor(YELLOW);
  M5.Lcd.setTextSize(3);
  M5.Lcd.println("Zip Code Wilmington");
  M5.Lcd.println("Take 2");

  M5.Lcd.print("Kristofer Younger - Aeneid");  // Print text on the screen (string)
                                  // 在屏幕上打印文本(字符串)
}


void loop() {
}