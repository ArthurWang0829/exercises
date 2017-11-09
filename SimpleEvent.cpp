//SimpleEvent.cpp
#include <iostream>
using namespace std;

class Condition
{
public:
	Condition() {}
	virtual ~Condition() {}
	virtual void log() = 0;
};

class Normal:public Condition
{
public:
	Normal() {log();}
	virtual ~Normal() {}
	virtual void log() {cout<<"Logging normal conditions...\t";}
};

class Error:public Condition
{
public:
	Error() {log();}
	virtual ~Error() {}
	virtual void log() {cout<<"Logging error conditions..";}
};

class Alarm:public Condition
{
public:
	Alarm();
	virtual ~Alarm() {}
	virtual void warn() {cout<<"Warning!\n\a";}
	virtual void log() {cout<<"General alarm log\n";}
	virtual void call() = 0;
};

Alarm::Alarm()
{
	log();
	warn();
}

class FireAlarm:public Alarm
{
public:
	FireAlarm() {log();};
	virtual ~FireAlarm() {}
	virtual void call() {cout<<"Calling fire department..\t";}
	virtual void log() {cout<<"Logging fire call..\n";}
};

int main()
{
	int input;
	int okay = 1;
	Condition *pCondition;
	while(okay)
	{
		cout<<"0:Quit\t1:Noraml\t2:Fire\t";
		cin>>input;
		okay = input;
		switch(input)
		{
			case 0:
				break;
			case 1:
				pCondition = new Normal;
				delete pCondition;
				break;
			case 2:
				pCondition = new FireAlarm;
				delete pCondition;
				break;
			default:
				pCondition = new Error;
				delete pCondition;
				okay = 0;
				break;
		}

	}
	return 0;
}