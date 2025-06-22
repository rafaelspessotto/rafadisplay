#include "graphics.h"

void initDisplay(TFT_eSPI &tft) {
    tft.init();
    tft.setRotation(0);
    tft.invertDisplay(1);
    tft.fillScreen(TFT_BLACK);
}

void drawCreeperFace(TFT_eSPI &tft, int x, int y, int size) {
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
