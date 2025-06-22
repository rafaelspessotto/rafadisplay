#include <Arduino.h>
#include <TFT_eSPI.h>
#include "graphics.h"

TFT_eSPI tft = TFT_eSPI();
#define TFT_RST 4 // Make sure this matches your wiring
#define TFT_SWRESET 0x01 // Software reset command for most TFT controllers

void initDisplay(TFT_eSPI &tft);

void showSplashScreen(){
  tft.fillScreen(TFT_BLACK);
  int faceSize = min(tft.width(), tft.height()) * 3 / 4;
  int unit = faceSize / 8;
  int actualFaceSize = unit * 8;
  int centerOffsetX = 0;
  int centerOffsetY = 0;
  int x = (tft.width() - actualFaceSize) / 2 + centerOffsetX;
  int y = (tft.height() - actualFaceSize) / 2 + centerOffsetY;
  drawCreeperFace(tft, x, y, actualFaceSize);
}

void setup() {
    Serial.begin(115200);
    initDisplay(tft);
    showSplashScreen();
}

void loop() {
  
}
