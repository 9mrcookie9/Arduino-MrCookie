#include "ButtonUse.h"

void ButtonMain::Init(int pinId, int timerLimit) {
    iPin = pinId;
    iTimerLimit = timerLimit;
}

bool ButtonMain::State() {
    if (iTimer == 0)
        iActualState = digitalRead(iPin);
    else
        iTimer++;
    iTimer = (iTimer > iTimerLimit) ? 0 : iTimer;
    if (iActualState != iLastState && iTimer == 0) {
        if (iActualState == 1) {
            bState = !bState;
            iTimer = (iTimer == 0) ? 1 : iTimer;
        }
    }
    iLastState = iActualState;
    return bState;
}