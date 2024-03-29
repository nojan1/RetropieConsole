#include <displayBehaviour.h>
#include <states.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>

DisplayBehaviour::DisplayBehaviour()
{
    display = new Adafruit_SSD1306(128, 64, &Wire, OLEDRESET_PIN);

    if (!display->begin(SSD1306_SWITCHCAPVCC, 0x3D))
    { 
        Serial.println(F("SSD1306 allocation failed"));
        setState(ERROR, ERROR_DISPLAYALLOC);         
    }

    display->cp437(true);         // Use full 256 char 'Code Page 437' font
    display->setTextColor(WHITE); // Draw white text

    display->clearDisplay();
    display->display();
}

void DisplayBehaviour::inStarting()
{
    if(!hasDrawn){
        display->setTextSize(2);
        display->setCursor(25, 25); 
        
        display->print("BOOTING");
        display->display();

        hasDrawn = true;
    }
}

void DisplayBehaviour::inShuttingDown()
{
}

void DisplayBehaviour::inError(int errorCode)
{
}

void DisplayBehaviour::onTransition(int from, int to)
{
    hasDrawn = false;
    display->clearDisplay();
    display->display();
}