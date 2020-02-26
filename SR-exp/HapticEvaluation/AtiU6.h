#pragma once
#include "Device.h"
#include "ftconfig.h"
#include "LabJackUD.h"
#pragma comment(lib, "labjackud.lib")

class AtiU6 : public Device
{
public:
	AtiU6(char *filename);
	~AtiU6(void);

    short readData(); // changed by me
	void closeConnection();

private:
	
	//Struct containing calibration information for Nano17	
	Calibration *cal;		
	float Total[6];
	//unsigned short index = 1;

	//Labjack U6 variables
	LJ_ERROR lngErrorcode;
	LJ_HANDLE lngHandle;
	double dblValue;
	long lngIOType;
	long lngChannel;

	//Variables that store voltage from U6
	float voltages[6];
	//Variables that store Force & Torque
	float FT[6];

	void nano17Init(char *filename);	
	void setVoltage(void);
   	void setFT(void);
};

