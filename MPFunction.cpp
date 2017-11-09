#include <iostream>
using namespace std;

constexpr double getpi()
{
	return (double)22/7;
}
class Dog
{
public:
	void speak() const {cout<<"Speaking...\t";}
	void move() const {cout<<"Moving....\t";}
	void hit() const {cout<<"hitting...\t";}
	void bite() const {cout<<"Biting...\t";}
	void eat() const {cout<<"Eating now...\t";}
};

typedef void(Dog::*PDF)() const;

int main()
{
	const int maxF = 5;
	PDF dogF[maxF] = {&Dog::speak,
				      &Dog::move,
				  	  &Dog::hit,
				  	  &Dog::bite,
				  	  &Dog::eat};
	Dog* pDog = 0;
	int method;
	bool fQuit = false;
	auto index = 3;

	while(!fQuit)
	{
		cout<<"0:Quit\t1:Speak\t2:Move\t3:Hit\t4:Bite\t5:Eat\t";
		cin>>method;
		if(method == 0)
		{
			fQuit = true;
			break;
		}
		else
		{
			pDog = new Dog;
			(pDog->*dogF[method-1])();
			delete pDog;
		}
	}
	return 0;
}