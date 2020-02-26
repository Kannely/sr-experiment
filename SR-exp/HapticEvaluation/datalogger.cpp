#include "datalogger.h"
#include "haptlinksupervisor.h"
#include <stdio.h>

//private Constructor
DataLogger::DataLogger()
{
	HaptLinkSupervisor::getInstance()->attachObserver(this);		//attach LOGGER as Oberver to Subject
}


//class pointer initialization
DataLogger* DataLogger::instance = NULL;

//public: returns pointer to class instance
DataLogger* DataLogger::getInstance()
{
	if (instance == NULL) {
		instance = new DataLogger();
	}
	return instance;
}

 
//call based on notification in HaptLinkSupervisors
void DataLogger::update(short value)
{
	
	if (value == HAPTIC_UPDATE_LOG)
	{

		int militime = HaptLinkSupervisor::getInstance()->getTimeStamp();	
		/*
		xml->writeStartElement("Data" );
		xml->writeTextElement("TimeStamp_ms",militime);		
		WritePacket(HaptLinkSupervisor::getInstance()->getPosition(),"Position_m");
		WritePacket(HaptLinkSupervisor::getInstance()->getOrientation(),"Orientation_deg");
		WritePacket(HaptLinkSupervisor::getInstance()->getForce(),"Force_N");
		WritePacket(HaptLinkSupervisor::getInstance()->getTorque(),"Torque_Nmm");
		xml->writeEndElement();
		*/
	}
	
	
}

/***************************************/
//Log file manipulation
/***************************************/
//public method: Opens file for further writing  
//filename = XML filename, age = age of the subject, sex = sex of the subject, pref = left or right handed
//this function is called from GUI
void DataLogger::OpenSessionLog(std::string filename,std::string age,std::string sex,std::string pref)
{
	//Date and time information of the XML log file
	time_t TimeStamp;
	time(&TimeStamp);

	/*
	xmlfile.setFileName(filename);

    if (!xmlfile.open(QIODevice::WriteOnly | QIODevice::Text))
         return;

	xml.setDevice(&xmlfile);
	xml.writeStartDocument();

	xml.writeStartElement("LogFile");
	xml.writeTextElement("Created",QString::QString(ctime(&TimeStamp)));
	xml.writeTextElement("Age",age);
	xml.writeTextElement("Sex",sex);
	xml.writeTextElement("Preference",pref);
	*/
}

//public method: Closes open file after closing all the open keys   
void DataLogger::CloseSessionLog()
{
	/*
	xml.writeEndDocument();
	xmlfile.close();
	*/
}

//public method: writes new data from devices to xml file
//compliant with dynamicData struct defined in datamodel.h
void DataLogger::WritePacket(Vector3 &dataPack, std::string element)
{
	/*
	xml.writeStartElement(element);
	xml.writeTextElement("X",QString::number(dataPack.x,'f',3));
	xml.writeTextElement("Y",QString::number(dataPack.y,'f',3));
	xml.writeTextElement("Z",QString::number(dataPack.z,'f',3));
	xml.writeEndElement();
	*/
}


