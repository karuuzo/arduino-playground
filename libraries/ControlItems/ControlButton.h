/********************************************************
/ created by karuuzo
/
/ encapsulate button control
/ control provide short and long button press detection
/
/ use ControlItem
/
/*********************************************************/

#ifndef _CONTROLBUTTON_H
#define _CONTROLBUTTON_H

#include <ControlItem.h>

class ControlButton : public ControlItem
{
	int _pButton;						// button pin
	unsigned long _downTime = 0;		// time when button pressed
	long _longButtonPressTime;			// time in milliseconds whet treated as long button press
	bool _buttonPress = false; 			// set true when button released after pressed
	bool _buttonLongPress = false; 		// set true if button released after long time pressed
public:
	ControlButton (int pButton, long longButtonPressTime = 3000) 
	{
		_pButton = pButton;
		_longButtonPressTime = longButtonPressTime;
	}
	virtual void init() 
	{
		pinMode (_pButton, INPUT);
	}
	virtual void tick() 
	{
		if (digitalRead(_pButton) == HIGH)
		{
			if (_downTime == 0)
				_downTime = millis();
		}
		else
		{
			if (_downTime > 0)
			{
				_buttonPress = true;
				if ((_downTime + _longButtonPressTime) < millis())
				{
					_buttonLongPress = true;
				}
				_downTime = 0;
			}
			else
			{
				_buttonPress = false;
				_buttonLongPress = false;
			}
		}
	}
	// button is pressed down
	virtual bool down (void)
	{
		return (_downTime > 0);
	}
	// button pressed down for long time
	virtual bool downLongTime (void)
	{
		return ((_downTime > 0) && ((_downTime + _longButtonPressTime) < millis()));
	}
	// button is pressed (down + up)
	virtual bool pressed (void)
	{
		return _buttonPress;
	}
	// button is pressed for long time (down - _longButtonPressTime - up)
	virtual bool pressedLongTime (void)
	{
		return _buttonLongPress;
	}
	
};

#endif