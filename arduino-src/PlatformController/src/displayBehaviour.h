#include <behaviour.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4

class DisplayBehaviour : public Behaviour
{
private:
    Adafruit_SSD1306 *display;
    bool hasDrawn = false;

public:
    DisplayBehaviour();
    void inStarting();
    void inShuttingDown();
    void inError(int errorCode);
    void onTransition(int from, int to);
};