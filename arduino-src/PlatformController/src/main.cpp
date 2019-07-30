#include <behaviour.h>
#include <states.h>

#include <ledRingBehaviour.h>
#include <displayBehaviour.h>
#include <powerButtonBehaviour.h>

#define NUM_BEHAVIOURS 2
Behaviour *behaviours[NUM_BEHAVIOURS];

int currentState = STARTING;
int errorCode = -1;

void setup()
{
  Serial.begin(9600);

  behaviours[0] = new LedRingBehaviour();
  behaviours[1] = new DisplayBehaviour();
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
}