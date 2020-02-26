#include "haptlinksupervisor.h"
#include "AtiDummy.h"
#include "Ati.h"
#include "AtiU6.h"
#include <windows.h>
#include "MilliSecTime.h"

//public method for setting up and sustaining device connection and managing data logging
int HaptLinkSupervisor::SuperviseConnection(char *filename) 
{
	//Create new instance for ATI sensor
	//AtiDummy is a dummy class which allows execution of the program without any actual hardware connected to the PC
	//ati = new AtiDummy(filename);

	ati = new AtiU6(filename);
	
	return 0;
}

HaptLinkSupervisor::~HaptLinkSupervisor()
{
	
}

void HaptLinkSupervisor::closeConnection()
{
	ati->closeConnection();
	delete ati;
}

HaptLinkSupervisor *HaptLinkSupervisor::instance = NULL;

void HaptLinkSupervisor::readData()
{
	//Start and store the initial value of the timer
	if(logFlag == 0)
	{
		 logFlag = 1;
		 MilliSecTime::getInstance()->setTimeStart();
	}
	
	//record the time for XML, difference between each time instants is equal to SAMPLE_RATE
	this->setTimeStamp(MilliSecTime::getInstance()->GetMilliSpan()); 
	
	//get value from the sensors
	ati->readData();	
	
	counter++;
}
