#include <behaviour.h>
#include <Adafruit_NeoPixel.h>

#define NUM_PIXELS 16

class LedRingBehaviour : public Behaviour
{
private:
    Adafruit_NeoPixel *ring; 
    int index = 0;

    void setAllLedsOff();

    void doLedRing(uint32_t color);
public:
    LedRingBehaviour();
    void inStarting();
    void inShuttingDown();
    void inError(int errorCode);
    void onTransition(int from, int to);
};