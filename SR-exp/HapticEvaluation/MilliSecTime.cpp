#include "MilliSecTime.h"
#include <cstring>		//for NULL


//private constructor
MilliSecTime::MilliSecTime(void)
{
}

/***************************************/
//Singleton class specific
/***************************************/

//class pointer initialization (obligatory for singleton to compile properly)
MilliSecTime* MilliSecTime::instance = NULL;

//public: returns pointer to singleton class instance
MilliSecTime* MilliSecTime::getInstance()
{
	if (instance == NULL) {
		instance = new MilliSecTime();
	}
	return instance;
}

/***************************************/
//Public
/***************************************/

//Deconstructor
MilliSecTime::~MilliSecTime(void)
{
}

//public method
int MilliSecTime::GetMilliCount()
{
	timeb tb;
	ftime( &tb );
	int nCount=	tb.millitm + (tb.time & 0xfffff) * 1000;

return nCount;
}

//public method
int MilliSecTime::GetMilliSpan()
{
	int nSpan = GetMilliCount() - nTimeStart;
	if (nSpan < 0)
	nSpan += 0x100000 * 1000;

return nSpan;
}

//public method
int MilliSecTime::GetMilliSpan(int StartTime)
{
	int nSpan = GetMilliCount() - StartTime;
	if (nSpan < 0)
	nSpan += 0x100000 * 1000;

return nSpan;
}

//public method
void MilliSecTime::setTimeStart()
{
	nTimeStart = GetMilliCount();
}

int MilliSecTime::getTimeStart()
{
return nTimeStart;
}