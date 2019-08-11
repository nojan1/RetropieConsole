#include <behaviour.h>
#include <states.h>

#include <ledRingBehaviour.h>
#include <displayBehaviour.h>
#include <powerButtonBehaviour.h>
#include <powerStateBehaviour.h>
#include <fanBehaviour.h>

#define NUM_BEHAVIOURS 5
Behaviour *behaviours[NUM_BEHAVIOURS];

int currentState = IDLE;
int errorCode = -1;

void setup()
{
  Serial.begin(9600);

  behaviours[0] = new LedRingBehaviour();
  behaviours[1] = new DisplayBehaviour();
  behaviours[2] = new PowerButtonBehaviour();
  behaviours[3] = new PowerStateBehaviour();
  behaviours[4] = new FanBehaviour();
}

void setState(int state, int errorCode)
{
  for (int i = 0; i < NUM_BEHAVIOURS; i++)
    behaviours[i]->onTransition(currentState, state);

  currentState = state;
  errorCode = errorCode;
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
    case POWEROFF:
      behaviours[i]->inPowerOff();
      break;
    default:
      behaviours[i]->inIdle();
      break;
    }
  }
}