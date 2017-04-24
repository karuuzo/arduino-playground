/********************************************************
/ created by karuuzo
/
/ define value holder with value smoothing
/ returns average value from n-th values
/
/*********************************************************/
#ifndef _SMOOTHVALUE_H
#define _SMOOTHVALUE_H

// default smooth array length, redefine before include to change value count
#ifndef SMOOTH_VALUE_LEN
#define SMOOTH_VALUE_LEN 10
#endif

template <class _Tsv>
class SmoothValue
{
	 _Tsv _valArray[SMOOTH_VALUE_LEN];
	 int _curValue = -1;
public:
	void set (_Tsv val)
	{
		if (_curValue < 0)
		{
			for (int i = 0; i < SMOOTH_VALUE_LEN; i++)
			{
				_valArray[i] = val;
			}
			_curValue = 0;
		}
		else
		{
			_valArray[_curValue] = val;
			_curValue = (_curValue + 1) % SMOOTH_VALUE_LEN;
		}
	}
	
	_Tsv get (void)
	{
		_Tsv retValue = _valArray[0];
		for (int i = 1; i < SMOOTH_VALUE_LEN; i++)
			retValue += _valArray[i];
		return (retValue / SMOOTH_VALUE_LEN);
	}
};

#endif