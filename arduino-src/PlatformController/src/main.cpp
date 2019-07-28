#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, 6, NEO_GRB + NEO_KHZ800);

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);

int i = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  strip.begin();
  strip.setBrightness(100);
  strip.show();

  display.clearDisplay();

  // Draw a single pixel in white
  display.drawPixel(10, 10, WHITE);
  display.display();
  delay(2000);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  for(int x = 0; x < 16; x++){
    strip.setPixelColor(x, 0);
  }
  
  i = (i + 1) % 16;
  strip.setPixelColor(i, strip.Color(0,0,200));
  strip.setPixelColor((i + 2) % 16, strip.Color(0,0,200)); 
  strip.setPixelColor((i + 4) % 16, strip.Color(0,0,200)); 
  strip.setPixelColor((i + 6) % 16, strip.Color(0,0,200)); 
  strip.setPixelColor((i + 8) % 16, strip.Color(0,0,200)); 
  strip.setPixelColor((i + 10) % 16, strip.Color(0,0,200)); 
  strip.setPixelColor((i + 12) % 16, strip.Color(0,0,200));
  strip.setPixelColor((i + 14) % 16, strip.Color(0,0,200)); 
  strip.show();

  display.clearDisplay();

  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  // Not all the characters will fit on the display. This is normal.
  // Library will draw what it can and the rest will be clipped.
  display.println(F("Hello!"));
  display.println(i, DEC);
 
  display.display();
  
  delay(100);
}