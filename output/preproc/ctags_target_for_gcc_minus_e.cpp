# 1 "/Volumes/Terabyte/kristofer/LocalProjects/m5stack/p0/p0.ino"
/*
*******************************************************************************
* Copyright (c) 2021 by  M5Stack
*                 Equipped with M5Core sample source code
*                          配套  M5Core 示例源代码
* Visit for more information: https://docs.m5stack.com/en/core/gray
* 获取更多资料请访问: https://docs.m5stack.com/zh_CN/core/gray
*
* Describe: Hello World
* Date: 2021/7/15
*******************************************************************************
*/
# 14 "/Volumes/Terabyte/kristofer/LocalProjects/m5stack/p0/p0.ino" 2


void setup() {
  M5.begin(); // Init M5Core.  初始化 M5Core

  M5.Lcd.setTextColor(0xFFE0 /* 255, 255,   0 */);
  M5.Lcd.setTextSize(3);
  M5.Lcd.println("Zip Code Wilmington");
  M5.Lcd.println("Take 2");

  M5.Lcd.print("Kristofer Younger - Aeneid"); // Print text on the screen (string)
                                  // 在屏幕上打印文本(字符串)
}


void loop() {
}
