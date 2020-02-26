#pragma once
#include <sys/timeb.h>


class MilliSecTime
{
public:
	//Inherited and class specific
	static MilliSecTime* getInstance();	 //returns pointer to singleton class instance
 
	~MilliSecTime(void);

	int GetMilliCount();
	int GetMilliSpan();
	int GetMilliSpan(int StartTime);
	void setTimeStart();
	int getTimeStart();

private:
	static MilliSecTime *instance;	//pointer on the class instance 
    MilliSecTime(void);				//Constructor
	int nTimeStart;
	int nTimeEllapsed;

};
