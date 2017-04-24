#ifndef _ControlDHT_H
#define _ControlDHT_H

#include <ControlItem.h>
#include <PreciseDelay.h>
#include <HasChanged.h>
#include <dht.h>

class ControlDHT : public ControlItem, protected dht, private PreciseDelay, public HasChanged<double>
{
	  int _DHTPin;
	  ValueHolderHasChange<double> _temperature;
	  ValueHolderHasChange<double> _humidity;
public:

	ControlDHT (int pDHT, long readFrequency = 250): 
		PreciseDelay(readFrequency)
	{
		_DHTPin = pDHT;
		_temperature.set(0.0);
		_humidity.set(0.0);
	}

	void init (void)
	{

	}

	void tick (void)
	{
		if (isTime())
		{
			if (read11(_DHTPin) == DHTLIB_OK)
			{
				_temperature.set(dht::temperature);
				_humidity.set(dht::humidity);
				HasChanged<double>::set(_temperature.hasChanged(false) || _humidity.hasChanged(false));
			}
		}
	}

	double getTemperature (void)
	{
		return _temperature.get();
	}

	double getHumidity (void)
	{
		return _humidity.get();
	}
	
	bool reset(void)
	{
		_temperature.reset();
		_humidity.reset();
		HasChanged<double>::reset();
	}
	bool hasChanged (bool bReset = true)
	{
		if (HasChanged<double>::hasChanged())
		{
			if (bReset)
			{
				_temperature.reset();
				_humidity.reset();
			}
			return true;
		}
		return false;
	}
};





#endif