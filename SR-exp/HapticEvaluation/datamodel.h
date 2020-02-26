#ifndef DATAMODEL_H
#define DATAMODEL_H

//constants
const int HAPTIC_UPDATE_LOG = 1;
const int HAPTIC_UPDATE_GUI = 2;

const int SAMPLE_RATE = 60;
const int HAPTIC_GUI_RATE = 4;
const int HAPTIC_LOG_RATE = 1;

const int DURATION = 100;
const int MILI_OFFSET = 3;
const int PERIOD = (SAMPLE_RATE+MILI_OFFSET)*HAPTIC_GUI_RATE;

struct Vector3 {
	
	float x;
	float y;
	float z;
};

#endif // DATAMODEL_H
