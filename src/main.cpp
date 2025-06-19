#include <Arduino.h>
<<<<<<< Updated upstream
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <SPI.h>
#include <Fonts/FreeSerif24pt7b.h>

/*
Pin Connections for ESP32 Dev Board:
Display Pin  ->  ESP32 GPIO  ->  Physical Pin Number
MOSI        ->  GPIO 23     ->  Pin 37
SCLK        ->  GPIO 18     ->  Pin 30
DC          ->  GPIO 2      ->  Pin 24
CS          ->  GPIO 15     ->  Pin 23
RST         ->  GPIO 4      ->  Pin 26
VCC         ->  3.3V        ->  Pin 1
GND         ->  GND         ->  Pin 2

Note: These pins are selected because:
1. They are all output-capable (unlike GPIO 34-39 which are input-only)
2. They work well with the SPI interface
3. They avoid pins with special boot functions
*/

// Declare pins for the display:
#define TFT_MOSI 23  // SPI MOSI pin (Physical pin 37)
#define TFT_SCLK 18  // SPI Clock pin (Physical pin 30)
#define TFT_DC   2   // Data/Command pin (Physical pin 24)
#define TFT_CS   15  // Chip Select pin (Physical pin 23)
#define TFT_RST  4   // Reset pin (Physical pin 26)

// Create display with hardware SPI:
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

int Variable1;  // Create a variable to have something dynamic to show on the display

void setup() {
  // Initialize Serial for debugging
  Serial.begin(115200);
  Serial.println("TFT Display Test");

  // Configure pins
  pinMode(TFT_RST, OUTPUT);
  pinMode(TFT_DC, OUTPUT);
  pinMode(TFT_CS, OUTPUT);
  
  // Initial reset sequence
  digitalWrite(TFT_RST, HIGH);
  delay(10);
  digitalWrite(TFT_RST, LOW);
  delay(10);
  digitalWrite(TFT_RST, HIGH);
  delay(150);

  Serial.println("Initializing SPI...");
  SPI.begin(TFT_SCLK, -1, TFT_MOSI, TFT_CS);
  SPI.setFrequency(10000000); // Slower SPI speed (10MHz)
  
  Serial.println("Initializing display...");
  tft.begin();
  
  // Test display connection
  uint8_t x = tft.readcommand8(ILI9341_RDMODE);
  Serial.print("Display ID: 0x"); Serial.println(x, HEX);
  // Initialize display parameters
  tft.setRotation(1);  // Landscape mode (320x240)
  delay(10);
  tft.fillScreen(ILI9341_BLACK);
  delay(10);
  
  Serial.println("Display initialized");
  Serial.print("Width: "); Serial.println(tft.width());
  Serial.print("Height: "); Serial.println(tft.height());
  
  // Set default text parameters
  tft.setTextWrap(false);
  tft.setTextSize(4);
  tft.setTextColor(ILI9341_WHITE);

  // Write to the display the text "Hello":
  tft.setCursor(0, 0);
  tft.println("Hello");

  // Start using a custom font:
  tft.setFont(&FreeSerif24pt7b);
  tft.setTextSize(0);

  // Write to the display the text "World":
  tft.setCursor(0, 80);
  tft.setTextColor(0xF800);
  tft.println("World!");

  // Stop using a custom font
  tft.setFont();

  // Draw rectangle:
  tft.drawRect(0, 110, 100, 50, 0x07FF);  // Reduced size slightly
                                             
  // Draw rounded rectangle:
  tft.drawRoundRect(120, 110, 100, 50, 10, 0x07FF);  // Adjusted position and size

  // Draw triangle:
  tft.drawTriangle(90,220, 120,180, 150,220, 0xFFE0);  // Adjusted coordinates

  // Draw filled triangle:
  tft.fillTriangle(170,220, 200,180, 230,220, 0x07FF);  // Adjusted coordinates

  // Draw line:
  tft.drawLine(0, 230, tft.width()-1, 230, 0x07FF);  // Using display width

  //  Draw circle:
  tft.drawCircle(30, 270, 25, 0x07E0);  // Adjusted radius and position

  // Draw a filled circle:
  tft.fillCircle(100, 270, 25, 0x001F);  // Adjusted radius and position

  // Draw filled rounded rectangle:
  tft.fillRoundRect(150, 250, 70, 50, 10, 0xF81B);  // Adjusted position and size
}

void loop() {
  Variable1++;  // Increase variable by 1
  if(Variable1 > 150) {
    Variable1 = 0;
  }

  // Convert Variable1 into a string
  char string[10];
  dtostrf(Variable1, 3, 0, string);

  // Write Variable1 with left text alignment:
  tft.setCursor(21, 125);
  tft.setTextColor(0xFFE0, 0x0000);
  tft.setTextSize(4);
  tft.println(Variable1);
  
  // Fill remaining space for numbers less than 10 or 100
  if(Variable1 < 10) {
    tft.fillRect(44, 124, 24, 34, 0x0000);
  }
  if(Variable1 < 100) {
    tft.fillRect(69, 124, 24, 34, 0x0000);
  }

  // Write string with right text alignment:
  tft.setCursor(150, 125);
  tft.setTextColor(0x07E0, 0x0000);
  tft.setTextSize(4);
  tft.println(string);

  // Clear space for custom font text:
  tft.fillRect(0, 198, 75, 34, 0x0000);

  // Write Variable1 with custom font:
  tft.setFont(&FreeSerif24pt7b);
  tft.setTextSize(0);
  tft.setCursor(0, 230);
  tft.setTextColor(0xF81F);
  tft.println(Variable1);
  tft.setFont();
=======
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
>>>>>>> Stashed changes
}
