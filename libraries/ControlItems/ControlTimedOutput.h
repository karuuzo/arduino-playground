/********************************************************
/ created by karuuzo
/
/ provide defined time signal to output
/
/ use ControlItem
/
/*********************************************************/
#ifndef _CONTROLTIMEDOUTPUT_H
#define _CONTROLTIMEDOUTPUT_H
class ControlTimedOutput : public ControlItem
{
	int _pinOutput;
	unsigned long _outputTime; // time in milliseconds output must be provided
	unsigned long _endTime = 0;	// time when output will be stopped
public:
	ControlTimedOutput (int pOutput, unsigned long outputTime) 
	{
		_pinOutput = pOutput;
		_outputTime = outputTime;
	}
	virtual void init() 
	{
		pinMode (_pinOutput, OUTPUT);
	}
	
	virtual void tick() 
	{
		if (_endTime > 0 && _endTime < millis())
		{
			_endTime = 0;
			digitalWrite (_pinOutput, LOW);
		}
	}
	
	void set (void)
	{
		set(_outputTime);
	}
	
	void set (unsigned long outputTime)
	{
		_endTime = millis() + outputTime;
		digitalWrite (_pinOutput, HIGH);
	}
	
};
#endif