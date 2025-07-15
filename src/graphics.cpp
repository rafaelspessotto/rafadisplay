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

void drawCreeperFaceTurned(TFT_eSPI &tft, int x, int y, int size, float direction) {
    // direction: -1.0 = left, 0.0 = center, 1.0 = right
    uint16_t green = 0x07E0;
    uint16_t black = TFT_BLACK;
    float unit = size / 8.0;
    float dx = direction * unit; // smooth shift

    // Always clear the full bounding box to black before drawing the face
    tft.fillRect(x, y, size, size, TFT_BLACK);

    // Face background (draw slightly inside the bounding box to avoid leftover bars)
    int faceOffset = 1;
    int faceSize = size - 2 * faceOffset;
    tft.fillRect(x + faceOffset, y + faceOffset, faceSize, faceSize, green);

    // Eyes
    tft.fillRect(round(x + unit * 1 + dx), round(y + unit * 2), round(unit * 2), round(unit * 2), black);
    tft.fillRect(round(x + unit * 5 + dx), round(y + unit * 2), round(unit * 2), round(unit * 2), black);

    // Mouth
    tft.fillRect(round(x + unit * 2 + dx), round(y + unit * 5), round(unit * 4), round(unit * 2), black);
    tft.fillRect(round(x + unit * 3 + dx), round(y + unit * 4), round(unit * 2), round(unit * 3), black);
}

void drawCreeperFaceLeft(TFT_eSPI &tft, int x, int y, int size) {
    uint16_t green = 0x07E0;
    uint16_t black = TFT_BLACK;
    float unit = size / 8.0;
    // Face background
    tft.fillRect(x, y, size, size, green);
    // Eyes shifted left
    tft.fillRect(round(x + unit * 0.5), round(y + unit * 2), round(unit * 2), round(unit * 2), black);
    tft.fillRect(round(x + unit * 4.5), round(y + unit * 2), round(unit * 2), round(unit * 2), black);
    // Mouth shifted left
    tft.fillRect(round(x + unit * 1.5), round(y + unit * 5), round(unit * 4), round(unit * 2), black);
    tft.fillRect(round(x + unit * 2.5), round(y + unit * 4), round(unit * 2), round(unit * 3), black);
}

void drawCreeperFaceRight(TFT_eSPI &tft, int x, int y, int size) {
    uint16_t green = 0x07E0;
    uint16_t black = TFT_BLACK;
    float unit = size / 8.0;
    // Face background
    tft.fillRect(x, y, size, size, green);
    // Eyes shifted right
    tft.fillRect(round(x + unit * 1.5), round(y + unit * 2), round(unit * 2), round(unit * 2), black);
    tft.fillRect(round(x + unit * 5.5), round(y + unit * 2), round(unit * 2), round(unit * 2), black);
    // Mouth shifted right
    tft.fillRect(round(x + unit * 2.5), round(y + unit * 5), round(unit * 4), round(unit * 2), black);
    tft.fillRect(round(x + unit * 3.5), round(y + unit * 4), round(unit * 2), round(unit * 3), black);
}

void drawCreeperEyes(TFT_eSPI &tft, int x, int y, int size, float eyeOffset) {
    uint16_t black = TFT_BLACK;
    float unit = size / 8.0;
    uint16_t green = 0x07E0;
    // Erase old eyes (draw over with green)
    tft.fillRect(round(x + unit * 0.5), round(y + unit * 2), round(unit * 7), round(unit * 2), green);
    // Draw new eyes
    tft.fillRect(round(x + unit * (1 + eyeOffset)), round(y + unit * 2), round(unit * 2), round(unit * 2), black);
    tft.fillRect(round(x + unit * (5 + eyeOffset)), round(y + unit * 2), round(unit * 2), round(unit * 2), black);
}

void drawCreeperMouth(TFT_eSPI &tft, int x, int y, int size, float mouthOffset) {
    uint16_t black = TFT_BLACK;
    float unit = size / 8.0;
    uint16_t green = 0x07E0;
    // Erase old mouth (draw over with green)
    tft.fillRect(round(x + unit * 1.5), round(y + unit * 4), round(unit * 5), round(unit * 4), green);
    // Draw new mouth
    tft.fillRect(round(x + unit * (2 + mouthOffset)), round(y + unit * 5), round(unit * 4), round(unit * 2), black);
    tft.fillRect(round(x + unit * (3 + mouthOffset)), round(y + unit * 4), round(unit * 2), round(unit * 3), black);
}

void animateCreeper(TFT_eSPI &tft, int x, int y, int size) {
    int delayFrame = 350;
    // Draw face background once
    uint16_t green = 0x07E0;
    tft.fillRect(x, y, size, size, green);
    // Center
    drawCreeperEyes(tft, x, y, size, 0);
    drawCreeperMouth(tft, x, y, size, 0);
    delay(delayFrame);
    // Left
    drawCreeperEyes(tft, x, y, size, -0.5);
    drawCreeperMouth(tft, x, y, size, -0.5);
    delay(delayFrame);
    // Center
    drawCreeperEyes(tft, x, y, size, 0);
    drawCreeperMouth(tft, x, y, size, 0);
    delay(delayFrame);
    // Right
    drawCreeperEyes(tft, x, y, size, 0.5);
    drawCreeperMouth(tft, x, y, size, 0.5);
    delay(delayFrame);
    // Center
    drawCreeperEyes(tft, x, y, size, 0);
    drawCreeperMouth(tft, x, y, size, 0);
    delay(delayFrame);
    // Explosion: flash white, then black, then scatter
    tft.fillRect(x, y, size, size, TFT_WHITE);
    delay(80);
    tft.fillRect(x, y, size, size, TFT_BLACK);
    delay(80);
    // ...scatter effect...
}
