/********************************************************
/ created by karuuzo
/
/ encapsulate analogue thermometer control with temperature
/ smoothing, voltage adjusting and predefined read intervals
/
/ use ControlItem
/ use SmoothValue
/ use VoltageSupport
/ use PreciseDelay
/ use ValueHolderHasChange
/
/*********************************************************/
#ifndef _CONTROLTHERMOMETER_H
#define _CONTROLTHERMOMETER_H

#include <ControlItem.h>
#include <SmoothValue.h>
#include <PreciseDelay.h>
#include <VoltageSupport.h>
#include <ValueHolderHasChange.h>



class ControlThermometer : public ControlItem, public ValueHolderHasChange<long>, private PreciseDelay
{
	  long _voltage = 0;
	  long _voltage5v = 0;
	  long _correction = 0;
	  int _thermometerPin;
	  SmoothValue<long> _smoothTemperature;
public:

	ControlThermometer (int pTerm, long readFrequency = 250): 
		PreciseDelay(readFrequency), ValueHolderHasChange (0)
	{
		_thermometerPin = pTerm;
	}

	void init (void)
	{

	}

	void tick (void)
	{
		if (isTime())
		{
			// read 5v value for voltage correction
			_voltage5v = readVcc();
			// correction value (V^6)
			float voltageAdjustment =  (_voltage5v * 1000) / 5000000.0;
			// read sensor value
			long sensorVal = analogRead(_thermometerPin);
			// calculate sensor voltage (V^6)
			_voltage = ((5000000 * sensorVal) * voltageAdjustment) / 1024000;
			// calculate temperature (T^3)
			_smoothTemperature.set((_voltage - 500) * 100);
			set(_smoothTemperature.get());
		}
	}

	long get (void)
	{
		return ValueHolderHasChange<long>::_value + _correction;
	}

	long getVoltage (void)
	{
		return _voltage;
	}

	void setCorrecttion (long value)
	{
		_correction = value;
	}
	
	long getCorrection (void)
	{
		return _correction;
	}
};
#endif