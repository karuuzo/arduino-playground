/********************************************************
/ created by karuuzo
/
/ value holder with change detection
/ provide value storage and change detection for value
/
/ use ValueHolder
/ use HasChanged
/
/*********************************************************/
#ifndef _VALUEHOLDERHASCHANGE_H
#define _VALUEHOLDERHASCHANGE_H
#include <ValueHolder.h>
#include <HasChanged.h>


template <class _Tvhhc>
class ValueHolderHasChange: protected ValueHolder<_Tvhhc>, public HasChanged<_Tvhhc>
{
public:
	ValueHolderHasChange(void) {}
	ValueHolderHasChange(_Tvhhc value): ValueHolder<_Tvhhc>(value) {}
	
	virtual void set (_Tvhhc value) 
	{
		HasChanged<_Tvhhc>::set(value, ValueHolder<_Tvhhc>::_value);
		ValueHolder<_Tvhhc>::_value = value;
	}
	virtual _Tvhhc get (void) {return ValueHolder<_Tvhhc>::_value;}
};
#endif