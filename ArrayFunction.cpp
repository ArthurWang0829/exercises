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
	int maxP = 5;
	void (*pFunc[maxP])(int&,int&);
	bool fQuit = false;

	int va1 = 1,va2 = 2;
	int choice,i;
	for(i=0;i<maxP;i++)
	{
		cout<<"0:Quit\t1:Input\t2:Square\t3:Cube\t4:Swap ";
		cin>>choice;
		switch(choice)
		{
			case 1:
			pFunc[i] = getVal;
			break;
			case 2:
			pFunc[i] = square;
			break;
			case 3:
			pFunc[i] = cube;
			break;
			case 4:
			pFunc[i] = swap;
			break;
			default:
			pFunc[i] = 0;
		}
		for(i=0;i<maxP;i++)
		{
			pFunc[i](va1,va2);
			priVal(va1,va2);
		}
		
	}
	return 0;
}