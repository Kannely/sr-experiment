/**********************************************************************************************************
DataLogger class

Created: March 2010
Author: mr.sc. Boris Takac, dipl.ing

This class is used for writing real-time data from devices to .xml file. Class is implemented as singleton 
and observer. It is attached to HaptLinkSupervisor class subject during single instance construction.
Observer inherited update() function is reipmlemented and it executes upon getting notification from 
Supervisor class.

Logging of data can only be done in programm after connection to devices was established in Supervisor class.
Start of logging is calles bz user event on the StartLog button at gui. This button changes the state of 
sessionOpen bool variable. Upon user event for start of logging OpenSessionLog() method is executed.
Then the  m

*************************************************************************************************************/
#ifndef DATALOGGER_H
#define DATALOGGER_H


#include "datamodel.h"
#include "Observer.h"
#include <string> 
#include <iostream>

class DataLogger : public Observer
{
public:
	//Inherited and class specific
	static DataLogger* getInstance();	 //returns pointer to singleton class instance
    virtual void update(short value);    //Observer class virtual function
    
	//Log file manipulation
	void OpenSessionLog(std::string filename, std::string age, std::string sex, std::string pref);
	void CloseSessionLog();	
	void WritePacket(Vector3 &dataPack, std::string element);
	//ofstream  xml;			//main object for holding xml for writing

private:
	static DataLogger *instance;	//pointeron the class instance 
    DataLogger();					//Constructor
	std::ofstream *xml;					//pointer for output file for use of QXmlStreamWriter
	
	
	
};

#endif // DATALOGGER_H
