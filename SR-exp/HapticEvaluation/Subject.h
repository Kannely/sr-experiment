#pragma once
#include "Observer.h"

#include <vector>

using std::vector;

class Subject
{

	vector<Observer*> list;

public:
	Subject(void);
	~Subject(void);
	void attachObserver(Observer *obs) { list.push_back(obs); }
	void notify(short value=0)
	{
		for (int i=0; i<(int)list.size();i++) list[i]->update(value);
	}

};
