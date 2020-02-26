#ifndef HAPTLINKSUPERVISOR_H
#define HAPTLINKSUPERVISOR_H

#include <ctime>
#include "datamodel.h"
#include "Device.h"
#include "Subject.h"


//Start of class definition
class HaptLinkSupervisor : public Subject {
	Device *ati;
	Device *opti;

public:
	//constants
	
	long counter;
	
	//methods
	static HaptLinkSupervisor* getInstance()
	
	{
	if (instance == NULL) {
		instance = new HaptLinkSupervisor();
	}
	
	return instance;
	}
	int SuperviseConnection(char *filename);			
	void readData();		

	Vector3 getPosition(){return opti->getTranslation();}
	Vector3 getOrientation(){return opti->getRotation();}
	Vector3 getForce(){return ati->getTranslation();}
	Vector3 getTorque(){return ati->getRotation();}
	int getTimeStamp(){return timestamp;}


	void timerEvent() { } //(QTimerEvent *event) { this->readData(); }
	void start() { } // { timerId = startTimer(SAMPLE_RATE); }
	void stop() { }//{ killTimer(timerId); }
	
	void closeConnection();

protected:
	void setTimeStamp(int tps) { timestamp = tps; }
private:  
	int timerId;
	int logFlag;
	//methods
	static HaptLinkSupervisor *instance;
	HaptLinkSupervisor() { logFlag = 0; }					//Constructor (private because class is Singleton)
	~HaptLinkSupervisor();
	
	int timestamp;

};
#endif // HAPTLINKSUPERVISOR_H
