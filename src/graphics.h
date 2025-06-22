#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <TFT_eSPI.h>

void initDisplay(TFT_eSPI &tft);
void drawCreeperFace(TFT_eSPI &tft, int x, int y, int size);

#endif // GRAPHICS_H
