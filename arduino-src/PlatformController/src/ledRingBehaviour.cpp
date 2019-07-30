#include <ledRingBehaviour.h>
#include <Adafruit_NeoPixel.h>

void LedRingBehaviour::setAllLedsOff()
{
    for (int i = 0; i < NUM_PIXELS; i++)
        ring->setPixelColor(i, 0);
}

void LedRingBehaviour::doLedRing(uint32_t color)
{
    if (timeToRun(100))
    {
        setAllLedsOff();

        index = (index + 1) % NUM_PIXELS;

        for (int i = 0; i < NUM_PIXELS; i += 2)
        {
            ring->setPixelColor((i + index) % NUM_PIXELS, color);
        }

        ring->show();
    }
}

LedRingBehaviour::LedRingBehaviour()
{
    ring = new Adafruit_NeoPixel(NUM_PIXELS, 6, NEO_GRB + NEO_KHZ800);
    ring->begin();
    ring->setBrightness(100);

    setAllLedsOff();
    ring->show();
}

void LedRingBehaviour::inStarting()
{
    doLedRing(ring->Color(0, 0, 200));
}

void LedRingBehaviour::inShuttingDown()
{
    doLedRing(ring->Color(50, 10, 0));
}

void LedRingBehaviour::inError(int errorCode)
{
    if (timeToRun(100))
    {
        for (int i = 0; i < NUM_PIXELS; i++)
            ring->setPixelColor(i, ring->Color(255, 0, 0));

        ring->show();
    }
}

void LedRingBehaviour::onTransition(int from, int to)
{
    setAllLedsOff();
    ring->show();
}