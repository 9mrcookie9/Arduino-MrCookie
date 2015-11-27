#include "ButtonUse.h"

void ButtonMain::Use(int id) {
	if (timer == 0)
		buttonState = digitalRead(id);
	else
		timer++;

	if (timer > 10)
		timer = 0;

	if (buttonState != lastState && timer == 0) {
		if (buttonState == 1) {
			State = !State;
			if (timer == 0)
				timer = 1;
		}
	}
	lastState = buttonState;
}