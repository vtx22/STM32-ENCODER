#pragma once
#include "stm32f1xx_hal.h"

class Encoder
{
public:
	Encoder();
	Encoder(bool direction);

	void tick(bool secondChannelState);

	void setDirection(bool direction);

	void setLimits(int32_t upper, int32_t lower);
	void resetLimits();

	void setUpperLimit();
	void setLowerLimit();
	void resetUpperLimit();
	void resetLowerLimit();

	void setCounter(int32_t value);
	void resetCounter();

	void setButtonPressed();
	bool getButtonPressed();

	bool hasTicked();

	int32_t getCounter();
private:
	int32_t _cnt = 0;
	int32_t _upperLimit = INT32_MAX, _lowerLimit = INT32_MIN;
	bool _direction = false, _buttonState = false;
	bool _hasTicked = false;
};
