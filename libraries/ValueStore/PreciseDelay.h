/********************************************************
/ created by karuuzo
/
/ class for precise delay measurements
/ provide blocking {delay()} and non-blocking {isTime()} delays
/
/*********************************************************/
#ifndef _PRECISEDELAY_H
#define _PRECISEDELAY_H

class PreciseDelay
{
	unsigned long _lastMillis;
	unsigned long _delayMillis;
public:
	PreciseDelay (unsigned long defaultDelay = 50)
	{
		_lastMillis = 0;
		_delayMillis = defaultDelay;
	}
	
	void delay(unsigned long delayMillis)
	{
		unsigned long curMillis = millis();
		long curDelay = (_lastMillis + delayMillis) - curMillis;
		nextStep(delayMillis);
		if (curDelay > 0)
			delay (curDelay);
	}
	
	void delay(void)
	{
		delay(_delayMillis);
	}

	long getDelayValue (unsigned long delayMillis)
	{
		return (_lastMillis + delayMillis) - millis();
	}

	
	long getDelayValue (void)
	{
		return getDelayValue(_delayMillis);
	}

	bool isTime (unsigned long delayMillis, bool autoNextStep = true)
	{
		bool ret = (getDelayValue(delayMillis) <= 0);
		if (autoNextStep && ret)
			nextStep(delayMillis);
		return ret;
	}
	
	bool isTime (bool autoNextStep = true)
	{
		return isTime(_delayMillis, autoNextStep);
	}
	
	void nextStep(unsigned long delayMillis)
	{
		_lastMillis = _lastMillis + delayMillis;
	}

	void nextStep(void)
	{
		nextStep(_delayMillis);
	}
	
};

#endif