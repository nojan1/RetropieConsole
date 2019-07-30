#include <behaviour.h>
#include <states.h>
#include <ledRingBehaviour.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET 4 // Reset pin # (or -1 if sharing Arduino reset pin)
// Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);

// int i = 0;

#define NUM_BEHAVIOURS 1
Behaviour *behaviours[NUM_BEHAVIOURS];

int currentState = STARTING;
int errorCode = -1;

void setup()
{
  Serial.begin(9600);

  behaviours[0] = new LedRingBehaviour();

  // if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) { // Address 0x3C for 128x32
  //   Serial.println(F("SSD1306 allocation failed"));
  //   for(;;); // Don't proceed, loop forever
  // }

  // display.clearDisplay();

  // // Draw a single pixel in white
  // display.drawPixel(10, 10, WHITE);
  // display.display();
  // delay(2000);
}

void loop()
{
  for (int i = 0; i < NUM_BEHAVIOURS; i++)
  {
    switch (currentState)
    {
    case STARTING:
      behaviours[i]->inStarting();
      break;
    case RUNNING:
      behaviours[i]->inRunning();
      break;
    case SHUTTINGDOWN:
      behaviours[i]->inShuttingDown();
      break;
    case ERROR:
      behaviours[i]->inError(errorCode);
      break;
    default:
      behaviours[i]->inIdle();
      break;
    }
  }

  // display.clearDisplay();

  // display.setTextSize(1);      // Normal 1:1 pixel scale
  // display.setTextColor(WHITE); // Draw white text
  // display.setCursor(0, 0);     // Start at top-left corner
  // display.cp437(true);         // Use full 256 char 'Code Page 437' font

  // // Not all the characters will fit on the display. This is normal.
  // // Library will draw what it can and the rest will be clipped.
  // display.println(F("Hello!"));
  // display.println(i, DEC);

  // display.display();

  // delay(100);
}