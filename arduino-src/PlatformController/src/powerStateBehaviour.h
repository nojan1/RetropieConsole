#include <behaviour.h>
#include <pins.h>
#include <Arduino.h>

class PowerStateBehaviour : public Behaviour
{
private:

public:
    PowerStateBehaviour();
    void inStarting();
    void inPowerOff();
    void inIdle();
};