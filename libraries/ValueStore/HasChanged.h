/********************************************************
/ created by karuuzo
/
/ class for universal interface for change detection on values
/
/*********************************************************/
#ifndef _HASCHANGED_H
#define _HASCHANGED_H


template <class _Thc>
class HasChanged
{
protected:
	bool _hasChanged = false;
public:
	HasChanged(void) {}
	HasChanged(bool changed) {set(changed);}
	HasChanged(_Thc v1, _Thc v2) {set(v1, v2);}
	virtual void set (bool changed) {_hasChanged = changed;}
	virtual void set (_Thc v1, _Thc v2) 
	{
		if (v1 != v2)
			set(true);
	}
	virtual bool reset(void)
	{
		set(false);
	}
	virtual bool hasChanged (bool bReset = true)
	{
		if (_hasChanged)
		{
			if (bReset)
				_hasChanged = false;
			return true;
		}
		return false;
	}
};

#endif