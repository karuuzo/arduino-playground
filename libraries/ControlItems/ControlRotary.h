/********************************************************
/ created by karuuzo
/
/ provide rotary encoder control
/ encapsulate Encoder library for using with ControlItem interface
/
/ use ControlItem
/ use Encoder (http://www.pjrc.com/teensy/td_libs_Encoder.html)
/
/*********************************************************/
#ifndef _CONTROLROTARY_H
#define _CONTROLROTARY_H

#include <ControlItem.h>
#include <ValueHolderHasChange.h>
#include <Encoder.h>

// ----------------------------------------------------------------------------------
//                           RotoryControl
// ----------------------------------------------------------------------------------
class ControlRotary : public ControlItem, private Encoder
{
	ValueHolderHasChange<long> _value;
	long _rotorStep;
	public:

	ControlRotary (int pLeft, int pRight, long rotorStep = 1) : Encoder (pLeft, pRight)
	{
		_rotorStep = rotorStep;
	}

	void init (void)
	{

	}

	void tick (void)
	{
		_value.set(read());
	}

	bool hasChanged(bool bReset = true)
	{
		return _value.hasChanged(bReset);
	}


	long get (void)
	{
		return (_rotorStep == 1)?_value.get():(_value.get() / _rotorStep);
	}

	void reset (void)
	{
		_value.set(0);
		_value.reset();
	}
};

#endif