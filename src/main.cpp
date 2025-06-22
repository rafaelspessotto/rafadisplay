#include <Arduino.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();
#define TFT_RST 4 // Make sure this matches your wiring

void hardwareReset() {
  pinMode(TFT_RST, OUTPUT);
  digitalWrite(TFT_RST, LOW);
  delay(100);
  digitalWrite(TFT_RST, HIGH);
  delay(150);
}

void setup() {
  Serial.begin(115200);
  Serial.println("Setup running");
  hardwareReset();
  tft.init();
  tft.setRotation(3);
  tft.invertDisplay(1); 
  tft.fillScreen(TFT_BLACK);
  delay(100);
}

void loop() {
  Serial.println("Loop running");
  tft.fillRect(0, 0, 50, 50, 0x001F);
  tft.fillRect(50, 0, 50, 50, 0x07E0);
  tft.fillRect(100, 0, 50, 50, 0xF800);
  tft.fillRect(150, 0, 50, 50, 0x07FF);
  delay(1000);
}
