#include "AtiU6.h"

const int AVERAGE_NUM = 50;

AtiU6::AtiU6(char *filename)
{
	//SI
	//nano17Init("FT9498.cal");

	//US
	//nano17Init("FT7816.cal");
	nano17Init(filename);

}

AtiU6::~AtiU6(void)
{
	closeConnection();
}

void AtiU6::closeConnection(void)
{
	destroyCalibration(cal);
}

short AtiU6::readData()
{
	setFT();

	
	if (true) //gui->calSI == true)
	{
		this->setTranslation( FT[0], FT[1], FT[2] );
		this->setRotation( FT[3], FT[4], FT[5] );
	}
	else
	{
		this->setTranslation( FT[0]*4.44822161526, FT[1]*4.44822161526, FT[2]*4.44822161526 );
		this->setRotation( FT[3]*112.984829028, FT[4]*112.984829028, FT[5]*112.984829028 );
	}

	return SUCCESS;
}

void AtiU6::setFT(void)
{
	setVoltage();
	ConvertToFT(cal,voltages,FT);
}

void AtiU6::setVoltage(void)
{
	lngErrorcode = GoOne(lngHandle);  
	lngErrorcode = GetFirstResult(lngHandle, &lngIOType,&lngChannel,&dblValue,0,0);
	
	lngErrorcode = GetNextResult(lngHandle, &lngIOType,&lngChannel,&dblValue,0,0);
	voltages[0] = dblValue;
	
	lngErrorcode = GetNextResult(lngHandle, &lngIOType,&lngChannel,&dblValue,0,0);
	voltages[1] = dblValue;
	
	lngErrorcode = GetNextResult(lngHandle, &lngIOType,&lngChannel,&dblValue,0,0);
	voltages[2] = dblValue;

	lngErrorcode = GetNextResult(lngHandle, &lngIOType,&lngChannel,&dblValue,0,0);
	voltages[3] = dblValue;

	lngErrorcode = GetNextResult(lngHandle, &lngIOType,&lngChannel,&dblValue,0,0);
	voltages[4] = dblValue;

	lngErrorcode = GetNextResult(lngHandle, &lngIOType,&lngChannel,&dblValue,0,0);
	voltages[5] = dblValue;

	lngErrorcode = GetNextResult(lngHandle, &lngIOType,&lngChannel,&dblValue,0,0);
	voltages[6] = dblValue;
}

void AtiU6::nano17Init(char *filename)
{
	for(int k=0;k<6;k++)
	{
		Total[k]=0;
		voltages[k]=0;
		FT[k]=0;
	}
	 
	lngErrorcode = OpenLabJack (LJ_dtU6, LJ_ctUSB, "1", TRUE, &lngHandle);

	lngErrorcode = AddRequest (lngHandle, LJ_ioPUT_CONFIG, LJ_chAIN_RESOLUTION, 1, 0, 0);
	lngErrorcode = AddRequest(lngHandle, LJ_ioGET_AIN, 0, LJ_rgBIP10V,0,0);
	lngErrorcode = AddRequest(lngHandle, LJ_ioGET_AIN, 2, LJ_rgBIP10V,0,0);
	lngErrorcode = AddRequest(lngHandle, LJ_ioGET_AIN, 4, LJ_rgBIP10V,0,0);
	lngErrorcode = AddRequest(lngHandle, LJ_ioGET_AIN, 6, LJ_rgBIP10V,0,0);
	lngErrorcode = AddRequest(lngHandle, LJ_ioGET_AIN, 8, LJ_rgBIP10V,0,0);
	lngErrorcode = AddRequest(lngHandle, LJ_ioGET_AIN, 10, LJ_rgBIP10V,0,0);

	cal = createCalibration(filename,1);
	for(int j=0;j<AVERAGE_NUM;j++)
	{
		setVoltage();

		for(int k=0;k<6;k++)
			Total[k]=Total[k]+voltages[k];
	}
	
	for(int k=0;k<6;k++)
     Total[k]=Total[k]/AVERAGE_NUM;

	Bias(cal,Total);

}