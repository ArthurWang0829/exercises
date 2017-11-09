#include <iostream>
#include <string.h>
using namespace std;

class String
{
public:
	String();
	String(const char* const)


private:
	String(int);
	char* value;
	int len;
};

String::String()
{
	value = new char[1];
	value[0] = '\0';
	len = 0;
}

String::String(int len)
{
	value = new char[len+1];
	int i;
	for(i = 0; i < len; i++)
		value[i] = '\0';
	len = len;
}