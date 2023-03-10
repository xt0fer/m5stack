/*
*******************************************************************************
* Copyright (c) 2021 by M5Stack
*                  Equipped with M5Core2 sample source code
*                          配套  M5Core2 示例源代码
* Visit for more information: https://docs.m5stack.com/en/core/core2
* 获取更多资料请访问: https://docs.m5stack.com/zh_CN/core/core2
*
* Describe: NTP TIME.
* Date: 2021/8/3
*******************************************************************************/

#include <M5Core2.h>
#include <WiFi.h>
#include "time.h"

// Set the name and password of the wifi to be connected.  配置所连接wifi的名称和密码
const char* ssid = "Rectory";
const char* password = "peacebewithyou";
#define EST -18000

const char* ntpServer =
    "time.apple.com";  //Set the connect NTP server.  设置连接的NTP服务器
const long gmtOffset_sec = EST;
const int daylightOffset_sec = 3600;


void printLocalTime() {  //Output current time.  输出当前时间
  struct tm timeinfo;
  if (!getLocalTime(
          &timeinfo)) {  //Return 1 when the time is successfully obtained.  成功获取到时间返回1
    M5.Lcd.println("Failed to obtain time");
    return;
  }
  M5.Lcd.fillRect(0, 50, 320, 69, BLACK);
  M5.Lcd.setCursor(0, 50);  //Set the cursor at (0,0).  设置光标位于(0,0)处
  M5.Lcd.println(
      &timeinfo,
      "%A\n%B %d %Y");
  M5.Lcd.setCursor(0, 120);  //Set the cursor at (0,0). 
  M5.Lcd.fillRect(0, 120, 320, 120, BLACK);
  M5.Lcd.drawRect(0, 120, 320, 120, BLUE);
  M5.Lcd.setCursor(80, 130);  //Set the cursor at (0,0).
  M5.Lcd.println(
      &timeinfo,
      "%H:%M:%S");
}

void setup() {
  M5.begin();             //Init M5Core2.  初始化 M5Core2
  M5.Lcd.setTextSize(2);  //Set the font size to 2.  设置字号大小为2
  M5.Lcd.printf("\nConnecting to %s", ssid);
  WiFi.begin(
      ssid,
      password);  //Connect wifi and return connection status.  连接wifi并返回连接状态
  while (WiFi.status() !=
         WL_CONNECTED) {  //If the wifi connection fails.  若wifi未连接成功
    delay(500);           //delay 0.5s.  延迟0.5s
    M5.Lcd.print(".");
  }
  M5.Lcd.println("\nCONNECTED!");

  configTime(gmtOffset_sec, daylightOffset_sec,
             ntpServer);  //init and get the time.  初始化并设置NTP

  M5.Lcd.setTextColor(YELLOW);
  M5.Lcd.setTextSize(3);
  
  printLocalTime();
  
  WiFi.disconnect(true);  //Disconnect wifi.  断开wifi连接
  WiFi.mode(WIFI_OFF);    //Set the wifi mode to off.  设置wifi模式为关闭
  delay(20);
}

void loop() {
  delay(1000);
  printLocalTime();
}