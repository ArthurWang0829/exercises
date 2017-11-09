#include <iostream>
using namespace std;

class Mammal
{
public:
	Mammal():age(10) {}
	virtual ~Mammal() {}
	virtual void speak() const = 0;
	virtual void move() const = 0;

private:
	int age;
};

class Dog:public Mammal
{
public:
	void speak() const {cout<<"woof!\t";}
	void move() const {cout<<"walking with tail..";}
};

class Cat:public Mammal
{
public:
	void speak() const {cout<<"Miao.\t";}
	void move() const {cout<<"Walking with claws..";}
};

class Horse:public Mammal
{
public:
	void speak() const {cout<<"Yu.....\t";}
	void move() const {cout<<"Galloping....";}
};

int main()
{
	void (Mammal::*pFunc)() const = 0;
	Mammal* ptr = 0;
	int animal;
	int method;
	bool fQuit = false;

	while(fQuit == false)
	{
		cout<<"0:Quit\t1:Dog\t2:Cat\t3:Horse\t";
		cin>>animal;
		switch(animal)
		{
			case 1:
			ptr = new Dog;
			break;
			case 2:
			ptr = new Cat;
			break;
			case 3:
			ptr = new Horse;
			break;
			default:
			fQuit = true;
			break;
		}
		if(fQuit) break;
		cout<<"1:speak\t2:move\t";
		cin>>method;
		switch(method)
		{
			case 1:
			pFunc = &Mammal::speak;
			break;
			default:
			pFunc = &Mammal::move;
			break;
		}
		(ptr->*pFunc)();
		delete ptr;
	}
	return 0;
}