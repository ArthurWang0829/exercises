#include <iostream>
using namespace std;

void square(int&,int&);
void cube(int&,int&);
void swap(int&,int&);
void getVal(int&,int&);
void priVal(int&,int&);

void square(int& a,int& b)
{
	a *= a;
	b *= b;
}

void cube(int& a,int& b)
{
	int temp;
	temp = a;
	a *= a;
	a *= temp;

	temp = b;
	b *= b;
	b *= temp;
}

void swap(int& a,int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void getVal(int& a,int& b)
{
	cout<<"New value for x:\t";
	cin>>a;
	cout<<"New value for y:\t";
	cin>>b;
}

void priVal(int& a,int& b)
{
	cout<<"x Value: "<<a<<"\t";
	cout<<"y value: "<<b<<"\t";
}

int main()
{
	void (*pFunc)(int&,int&);
	bool fQuit = false;

	int va1 = 1,va2 = 2;
	int choice;
	while(fQuit == false)
	{
		cout<<"0:Quite\t1:Input\t2:Square\t3:Cube\t4:Swap ";
		cin>>choice;
		switch(choice)
		{
			case 1:
			pFunc = getVal;
			break;
			case 2:
			pFunc = square;
			break;
			case 3:
			pFunc = cube;
			break;
			case 4:
			pFunc = swap;
			break;
			default:
			fQuit = true;
			break;
		}
		if(fQuit) break;
		priVal(va1,va2);
		pFunc(va1,va2);
		priVal(va1,va2);
	}
	return 0;
}