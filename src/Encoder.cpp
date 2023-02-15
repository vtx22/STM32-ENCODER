#include "Encoder.hpp"

Encoder::Encoder()
{
}

Encoder::Encoder(bool direction) : _direction(direction)
{
}

void Encoder::setDirection(bool direction)
{
	_direction = direction;
}

void Encoder::tick(bool secondChannelState)
{
	_hasTicked = true;
	_cnt += (secondChannelState ^ _direction) ? 1 : -1;

	if(_cnt > _upperLimit)
	{
		_cnt = _upperLimit;
		return;
	}
	if(_cnt < _lowerLimit)
	{
		_cnt = _lowerLimit;
	}


}

void Encoder::resetCounter()
{
	_cnt = 0;
}

int32_t Encoder::getCounter()
{
	return _cnt;
}
void Encoder::resetUpperLimit()
{
	_upperLimit = INT32_MAX;
}

void Encoder::resetLowerLimit()
{
	_lowerLimit = INT32_MIN;
}

void Encoder::resetLimits()
{
	_upperLimit = INT32_MAX;
	_lowerLimit = INT32_MIN;
}

void Encoder::setCounter(int32_t value)
{
	_cnt = value;
}

bool Encoder::getButtonPressed()
{
	if(_buttonState)
	{
		_buttonState = false;
		return true;
	}
	return false;
}

void Encoder::setButtonPressed()
{
	_buttonState = true;
}

bool Encoder::hasTicked()
{
	if(_hasTicked)
	{
		_hasTicked = false;
		return true;
	}
	return false;
}
