#include <behaviour.h>

class PowerButtonBehaviour : public Behaviour
{
private:

public:
    PowerButtonBehaviour();
    void inStarting();
    void inShuttingDown();
    void inError(int errorCode);
    void onTransition(int from, int to);
};