#include <Arduino.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

void setup() {
  Serial.begin(115200);
  Serial.println("Setup running");
  tft.init();
  tft.setRotation(3);
  tft.invertDisplay(1); // Invert display colors
  tft.fillScreen(TFT_BLACK);
}

void loop() {
  Serial.println("Loop running");
  tft.fillRect(0, 0, 50, 50, 0x001F);
  tft.fillRect(50, 0, 50, 50, 0x07E0);
  tft.fillRect(100, 0, 50, 50, 0xF800);
  tft.fillRect(150, 0, 50, 50, 0x07FF);

  delay(1000);
}
