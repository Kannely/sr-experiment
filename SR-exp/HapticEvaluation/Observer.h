#pragma once
class Observer
{
public:
	//Constructor
	Observer(void);
	~Observer(void);

	virtual void update(short value)=0;
};
