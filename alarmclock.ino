#include <Wire.h> // IIC-Bibliothek            
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHTTYPE DHT11


#include <virtuabotixRTC.h> 
 
//CLK -> 9 , DAT -> 10, Reset -> 11
 
virtuabotixRTC zeit(9, 10, 11); 

LiquidCrystal_I2C lcd(0x3F,16,2);

int button1 = 3;
int button2 = 7;
int dhtpin = 8;

DHT dht(dhtpin, DHTTYPE);

void setup(void) {
  //myRTC.setDS1302Time(10, 48, 17, 7, 06, 10, 2021); < Setze Zeit beim Setup. Entfernen nach Einstellung
  lcd.init();   
  lcd.backlight();
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

  dht.begin();

}

void loop() {
  zeit.updateTime();
  String zeit_now = zeit.hours + ":" + zeit.minutes;
  delay(2000);
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  lcd.setCursor(0,0);  
  lcd.print("      23:34");
  lcd.setCursor(0,1);  
  lcd.print(String(t) + char(223) +"C         " + String(h) + "%");
}