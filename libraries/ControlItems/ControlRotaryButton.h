/********************************************************
/ created by karuuzo
/
/ provide rotary encoder control with button
/ extends ControlRotary library by adding button interface
/
/ use ControlButton
/ use ControlRotary
/
/*********************************************************/
#ifndef _CONTROLROTARYBUTTON_H
#define _CONTROLROTARYBUTTON_H


#include <ControlButton.h>
#include <ControlRotary.h>

class ControlRotaryButton: public ControlButton, public ControlRotary
{
public:
	ControlRotaryButton (int pLeft, int pRight, int pButton, 
		long longButtonPressTime = 3000, long rotorStep = 1):
		ControlRotary (pLeft, pRight, rotorStep), 
		ControlButton (pButton, longButtonPressTime)
	{
	}
	
	virtual void init() 
	{
		ControlRotary::init();
		ControlButton::init();
	}
	
	virtual void tick() 
	{
		ControlRotary::tick();
		ControlButton::tick();
	}
};
#endif