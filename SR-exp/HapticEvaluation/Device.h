#ifndef HAPTDEVICE_H
#define HAPTDEVICE_H

#include "datamodel.h"

class Device
{
public:

	static const short SUCCESS = 1;
	static const short FAILED = 0;

	//Constructor
	Device()
	{

		// empty body
	}
	
	Vector3 getTranslation() { return translation; }
    Vector3 getRotation() { return rotation; }

	virtual short readData() = 0;
    virtual void closeConnection() = 0;

protected:
	
	void setTranslation(float x, float y, float z) 
	{ 
		translation.x = x;  
		translation.y = y;  
		translation.z = z; 
	} 

	
	void setRotation(float x, float y, float z) 
	{ 
		rotation.x = x;  
		rotation.y = y;  
		rotation.z = z; 
	} 

	
private:
	
    Vector3 translation;
	Vector3 rotation;
    
};

#endif // HAPTDEVICE_H
