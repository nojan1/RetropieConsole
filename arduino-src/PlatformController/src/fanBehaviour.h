#include <behaviour.h>
#include <pins.h>
#include <Arduino.h>

class FanBehaviour : public Behaviour
{
private:

public:
    FanBehaviour();
    void onTransition(int from, int to);
};