#include <Arduino.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();
#define TFT_RST 4 // Make sure this matches your wiring
#define TFT_SWRESET 0x01 // Software reset command for most TFT controllers

void hardwareReset() {
  pinMode(TFT_RST, OUTPUT);
  digitalWrite(TFT_RST, LOW);
  delay(100);
  digitalWrite(TFT_RST, HIGH);
  delay(150);
}

void drawCreeperFace(int x, int y, int size) {
  uint16_t green = 0x07E0; // Bright green
  uint16_t black = TFT_BLACK;
  float unit = size / 8.0; // Use float for precise placement

  // Fill face background
  tft.fillRect(x, y, round(unit * 8), round(unit * 8), green);

  // Eyes
  tft.fillRect(round(x + unit * 1), round(y + unit * 2), round(unit * 2), round(unit * 2), black);
  tft.fillRect(round(x + unit * 5), round(y + unit * 2), round(unit * 2), round(unit * 2), black);

  // Mouth
  tft.fillRect(round(x + unit * 2), round(y + unit * 5), round(unit * 4), round(unit * 2), black);
  tft.fillRect(round(x + unit * 3), round(y + unit * 4), round(unit * 2), round(unit * 3), black);
}

void setup() {
  Serial.begin(115200);
  //hardwareReset();
  tft.init();
  tft.setRotation(0);
  tft.invertDisplay(1);
  tft.fillScreen(TFT_BLACK); // Clear after rotation
}

void loop() {
  static bool drawn = false;
  if (!drawn) {
    tft.fillScreen(TFT_BLACK);
    int faceSize = min(tft.width(), tft.height()) * 3 / 4;
    int unit = faceSize / 8;
    int actualFaceSize = unit * 8;
    int centerOffsetX = 0;
    int centerOffsetY = 0;
    int x = (tft.width() - actualFaceSize) / 2 + centerOffsetX;
    int y = (tft.height() - actualFaceSize) / 2 + centerOffsetY;
    drawCreeperFace(x, y, actualFaceSize);
    drawn = true;
  }
  delay(100);
}
