#include <windows.h>
#include <iostream>
#include <fstream>
#include "haptlinksupervisor.h"

using namespace std;

//int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
int main(int argc, char *argv[])
{
	//QApplication a(argc, argv);
	//HapticEvaluationGUI *gui = HapticEvaluationGUI::getInstance();
    
	HaptLinkSupervisor *supervisor = HaptLinkSupervisor::getInstance();

	supervisor->SuperviseConnection("FT9498.cal");

	ofstream myforce;
	myforce.open("00_force.txt");
	myforce << "sec_x10 torque_X torque_Y torque_Z force_X force_Y force_Z" << std::endl;

	int totalDuration = 100; // 30 secondes
	int i= 00;
	while (i<totalDuration) {

		supervisor->readData();

		Vector3 force = supervisor->getForce();
		Vector3 torque = supervisor->getTorque();

		myforce << i << " " << torque.x << " " << torque.y << " " << torque.z << " " << force.x << " " << force.y << " " << force.z << std::endl;
		std::cout << "Time : " << i << " sec x10" << std::endl;
		i++;

		Sleep(100); // 100 ms (10 Hz)
	}

	myforce.close();
	supervisor->closeConnection();
	Sleep(20);

	return 0;
}
