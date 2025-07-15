#include "graphics.h"

void initDisplay(TFT_eSPI &tft) {
    tft.init();
    tft.setRotation(0);
    tft.invertDisplay(1);
    tft.fillScreen(TFT_BLACK);
}

void drawCreeperFace(TFT_eSPI &tft, int x, int y, int size) {
  uint16_t green = 0x07E0;
  uint16_t black = TFT_BLACK;
  float unit = size / 8.0;
  tft.fillRect(x, y, round(unit * 8), round(unit * 8), green);
  tft.fillRect(round(x + unit * 1), round(y + unit * 2), round(unit * 2), round(unit * 2), black);
  tft.fillRect(round(x + unit * 5), round(y + unit * 2), round(unit * 2), round(unit * 2), black);
  tft.fillRect(round(x + unit * 2), round(y + unit * 5), round(unit * 4), round(unit * 2), black);
  tft.fillRect(round(x + unit * 3), round(y + unit * 4), round(unit * 2), round(unit * 3), black);
}

void drawCreeperFaceTurned(TFT_eSPI &tft, int x, int y, int size, float direction) {
    uint16_t green = 0x07E0;
    uint16_t black = TFT_BLACK;
    float unit = size / 8.0;
    float dx = direction * unit;
    tft.fillRect(x, y, size, size, TFT_BLACK);
    int faceOffset = 1;
    int faceSize = size - 2 * faceOffset;
    tft.fillRect(x + faceOffset, y + faceOffset, faceSize, faceSize, green);
    tft.fillRect(round(x + unit * 1 + dx), round(y + unit * 2), round(unit * 2), round(unit * 2), black);
    tft.fillRect(round(x + unit * 5 + dx), round(y + unit * 2), round(unit * 2), round(unit * 2), black);
    tft.fillRect(round(x + unit * 2 + dx), round(y + unit * 5), round(unit * 4), round(unit * 2), black);
    tft.fillRect(round(x + unit * 3 + dx), round(y + unit * 4), round(unit * 2), round(unit * 3), black);
}

void drawCreeperFaceLeft(TFT_eSPI &tft, int x, int y, int size) {
    uint16_t green = 0x07E0;
    uint16_t black = TFT_BLACK;
    float unit = size / 8.0;
    tft.fillRect(x, y, size, size, green);
    tft.fillRect(round(x + unit * 0.5), round(y + unit * 2), round(unit * 2), round(unit * 2), black);
    tft.fillRect(round(x + unit * 4.5), round(y + unit * 2), round(unit * 2), round(unit * 2), black);
    tft.fillRect(round(x + unit * 1.5), round(y + unit * 5), round(unit * 4), round(unit * 2), black);
    tft.fillRect(round(x + unit * 2.5), round(y + unit * 4), round(unit * 2), round(unit * 3), black);
}

void drawCreeperFaceRight(TFT_eSPI &tft, int x, int y, int size) {
    uint16_t green = 0x07E0;
    uint16_t black = TFT_BLACK;
    float unit = size / 8.0;
    tft.fillRect(x, y, size, size, green);
    tft.fillRect(round(x + unit * 1.5), round(y + unit * 2), round(unit * 2), round(unit * 2), black);
    tft.fillRect(round(x + unit * 5.5), round(y + unit * 2), round(unit * 2), round(unit * 2), black);
    tft.fillRect(round(x + unit * 2.5), round(y + unit * 5), round(unit * 4), round(unit * 2), black);
    tft.fillRect(round(x + unit * 3.5), round(y + unit * 4), round(unit * 2), round(unit * 3), black);
}

void drawCreeperEyes(TFT_eSPI &tft, int x, int y, int size, float eyeOffset) {
    uint16_t black = TFT_BLACK;
    float unit = size / 8.0;
    uint16_t green = 0x07E0;
    tft.fillRect(round(x + unit * 0.5), round(y + unit * 2), round(unit * 7), round(unit * 2), green);
    tft.fillRect(round(x + unit * (1 + eyeOffset)), round(y + unit * 2), round(unit * 2), round(unit * 2), black);
    tft.fillRect(round(x + unit * (5 + eyeOffset)), round(y + unit * 2), round(unit * 2), round(unit * 2), black);
}

void drawCreeperMouth(TFT_eSPI &tft, int x, int y, int size, float mouthOffset) {
    uint16_t black = TFT_BLACK;
    float unit = size / 8.0;
    uint16_t green = 0x07E0;
    tft.fillRect(round(x + unit * 1.5), round(y + unit * 4), round(unit * 5), round(unit * 4), green);
    tft.fillRect(round(x + unit * (2 + mouthOffset)), round(y + unit * 5), round(unit * 4), round(unit * 2), black);
    tft.fillRect(round(x + unit * (3 + mouthOffset)), round(y + unit * 4), round(unit * 2), round(unit * 3), black);
}

void drawCreeperFaceShaded(TFT_eSPI &tft, int x, int y, int size, float shade) {
    uint16_t green = 0x07E0;
    uint16_t darkGreen = tft.color565(0, 80, 0);
    float unit = size / 8.0;
    for (int i = 0; i < 8; ++i) {
        uint16_t color = (i < 8 * shade) ? darkGreen : green;
        tft.fillRect(x + round(unit * i), y, round(unit), size, color);
    }
    tft.fillRect(round(x + unit * 1), round(y + unit * 2), round(unit * 2), round(unit * 2), TFT_BLACK);
    tft.fillRect(round(x + unit * 5), round(y + unit * 2), round(unit * 2), round(unit * 2), TFT_BLACK);
    tft.fillRect(round(x + unit * 2), round(y + unit * 5), round(unit * 4), round(unit * 2), TFT_BLACK);
    tft.fillRect(round(x + unit * 3), round(y + unit * 4), round(unit * 2), round(unit * 3), TFT_BLACK);
}

void drawCreeperFaceAt(TFT_eSPI &tft, int x, int y, int size, float eyeOffset, float mouthOffset, float angle) {
    uint16_t green = 0x07E0;
    uint16_t black = TFT_BLACK;
    float unit = size / 8.0;
    int drawX = x, drawY = y;
    bool swapXY = false, flipX = false, flipY = false;
    if (angle == 90) { swapXY = true; flipY = true; }
    else if (angle == 180) { flipX = true; flipY = true; }
    else if (angle == 270) { swapXY = true; flipX = true; }
    tft.fillRect(x, y, size, size, green);
    int e1x = round(x + unit * (1 + eyeOffset));
    int e2x = round(x + unit * (5 + eyeOffset));
    int ey = round(y + unit * 2);
    if (swapXY) {
        int tmp = e1x; e1x = y + (e1x - x); e2x = y + (e2x - x); ey = x + (ey - y);
    }
    if (flipX) { e1x = x + size - (e1x - x) - round(unit * 2); e2x = x + size - (e2x - x) - round(unit * 2); }
    if (flipY) { ey = y + size - (ey - y) - round(unit * 2); }
    tft.fillRect(e1x, ey, round(unit * 2), round(unit * 2), black);
    tft.fillRect(e2x, ey, round(unit * 2), round(unit * 2), black);
    int m1x = round(x + unit * (2 + mouthOffset));
    int m2x = round(x + unit * (3 + mouthOffset));
    int my1 = round(y + unit * 5);
    int my2 = round(y + unit * 4);
    if (swapXY) {
        m1x = y + (m1x - x); m2x = y + (m2x - x); my1 = x + (my1 - y); my2 = x + (my2 - y);
    }
    if (flipX) { m1x = x + size - (m1x - x) - round(unit * 4); m2x = x + size - (m2x - x) - round(unit * 2); }
    if (flipY) { my1 = y + size - (my1 - y) - round(unit * 2); my2 = y + size - (my2 - y) - round(unit * 3); }
    tft.fillRect(m1x, my1, round(unit * 4), round(unit * 2), black);
    tft.fillRect(m2x, my2, round(unit * 2), round(unit * 3), black);
}

void animateCreeper(TFT_eSPI &tft, int x, int y, int size) {
    const char* creeperText = "Creeper";
    int delayFrame = 350;
    int steps = 12;
    int startY = y + size * 2;
    int textY = y + size + 24;
    for (int i = 0; i <= steps; ++i) {
        int cy = startY - (startY - y) * i / steps;
        tft.fillRect(x, y, size, size * 3, TFT_BLACK);
        drawCreeperFaceAt(tft, x, cy, size, 0, 0);
        if (cy == y) {
            tft.setTextColor(TFT_WHITE, TFT_BLACK);
            tft.setTextDatum(MC_DATUM);
            tft.drawString(creeperText, x + size / 2, textY, 2);
        }
        delay(30);
    }
    drawCreeperFaceAt(tft, x, y, size, 0, 0);
    tft.setTextColor(0x07E0, TFT_BLACK);
    tft.setTextDatum(MC_DATUM);
    tft.drawString(creeperText, x + size / 2, textY, 4);
    delay(delayFrame);
    drawCreeperFaceAt(tft, x, y, size, -0.5, -0.5);
    tft.setTextColor(0x07E0, TFT_BLACK);
    tft.setTextDatum(MC_DATUM);
    tft.drawString(creeperText, x + size / 2, textY, 4);
    delay(delayFrame);
    drawCreeperFaceAt(tft, x, y, size, 0, 0);
    tft.setTextColor(0x07E0, TFT_BLACK);
    tft.setTextDatum(MC_DATUM);
    tft.drawString(creeperText, x + size / 2, textY, 4);
    delay(delayFrame);
    drawCreeperFaceAt(tft, x, y, size, 0.5, 0.5);
    tft.setTextColor(0x07E0, TFT_BLACK);
    tft.setTextDatum(MC_DATUM);
    tft.drawString(creeperText, x + size / 2, textY, 4);
    delay(delayFrame);
    drawCreeperFaceAt(tft, x, y, size, 0, 0);
    tft.setTextColor(0x07E0, TFT_BLACK);
    tft.setTextDatum(MC_DATUM);
    tft.drawString(creeperText, x + size / 2, textY, 4);
    delay(delayFrame);
    for (int i = 0; i <= steps; ++i) {
        int cy = y + (startY - y) * i / steps;
        tft.fillRect(x, y, size, size * 3, TFT_BLACK);
        drawCreeperFaceAt(tft, x, cy, size, 0, 0);
        if (cy == y) {
            tft.setTextColor(TFT_WHITE, TFT_BLACK);
            tft.setTextDatum(MC_DATUM);
            tft.drawString(creeperText, x + size / 2, textY, 2);
        }
        delay(30);
    }
    tft.fillRect(x, y, size, size * 3, TFT_BLACK);
}
