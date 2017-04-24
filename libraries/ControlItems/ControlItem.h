/********************************************************
/ created by karuuzo
/
/ base class for control item
/ used for universal interface with controls
/
/*********************************************************/
#ifndef _CONTROLITEM_H
#define _CONTROLITEM_H

class ControlItem
{
public:
	ControlItem (void) {}
	virtual void init() = 0;
	virtual void tick() = 0;
};

#endif