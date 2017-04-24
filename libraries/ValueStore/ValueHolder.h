/********************************************************
/ created by karuuzo
/
/ simple class for value encapsulation
/
/*********************************************************/
#ifndef _VALUEHOLDER_H
#define _VALUEHOLDER_H

template <class _Tvh>
class ValueHolder
{
protected:
	_Tvh _value;
public:
	ValueHolder(void) {}
	ValueHolder(_Tvh value) {_value = value;}
	
	virtual void set (_Tvh value) {_value = value;}
	virtual _Tvh get (void) {return _value;}
};

#endif