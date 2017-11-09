#include <iostream>
using namespace std;

enum {larger , smaller , same };
//specific states of comparison

class Data
{
public:
	Data(int dValue):value(dValue) {} //initialize Data
	~Data() {}
	int compare(const Data&);
	void show() {cout<<value<<endl;}
private:
	int value;
};

int Data::compare(const Data& otherData)
{
	if(value > otherData.value)
		return larger;
	if(value < otherData.value)
		return smaller;
	else
		return same;
}

class Cat
{
public:
	Cat(int newAge): age(newAge) {}
	~Cat()	{cout<<"Deleting "<<age<<" years old cat.\t\n";}
	int compare(const Cat&);
	void show() {cout<<"This cat is "<<age<<" years old.\t\n";}

private:
	int age;
};

int Cat::compare(const Cat& otherCat)
{
	if(age > otherCat.age)
		return larger;
	if(age < otherCat.age)
		return smaller;
	else
		return same;
}



template <class T> class Node;
template <class T> class HeadNode;
template <class T> class TailNode;
template <class T> class InterNode;

template <class T> class Node//initialize ADT
{
public:
	Node() {}
	virtual ~Node() {}
	virtual Node<T>* insert(T* data) = 0;
	virtual void show() = 0;
private:
};

template <class T> class InterNode:public Node<T>
{
public:
	InterNode(T* data,Node<T>* next);
	virtual ~InterNode() {delete next;delete data;}
	virtual Node<T>* insert(T* data);
	virtual void show() {data->show();next->show();}
private:
	T* data;
	Node<T>* next;
};

template <class T> InterNode<T>::InterNode(T* newData,Node<T>* newNext):
data(newData),next(newNext) {}

template <class T> Node<T>* InterNode<T>::insert(T* otherData)
{
	int result = data->compare(*otherData);
	switch(result)
	{
		case same: 
		{
			next = next->insert(otherData);
			return this;
		}
		case larger:
		{
			InterNode<T>* dataNode = new InterNode<T>(otherData,this);
			return dataNode;
		}
		case smaller:
			next = next->insert(otherData);
			return this;
	}	
	return this;
}

template <class T> class TailNode:public Node<T>
{
public:
	TailNode() {}
	virtual ~TailNode() {}
	virtual Node<T>* insert(T* data);
	virtual void show() {}
private:
};

template <class T> Node<T>* TailNode<T>::insert(T* data)
{
	InterNode<T>* dataNode = new InterNode<T>(data,this);
	return dataNode;
}

template <class T> class HeadNode:public Node<T>
{
public:
	HeadNode();
	virtual ~HeadNode() {delete next;}
	virtual Node<T>* insert(T* data);
	virtual void show() {next->show();}
private:
	Node<T>* next;
};

template <class T> HeadNode<T>::HeadNode()
{
	next = new TailNode<T>;
}

template <class T> Node<T>* HeadNode<T>::insert(T* odata)
{
	next = next->insert(odata);
	return this;
}

template <class T> class LinkList
{
public:
	LinkList();
	~LinkList() {delete head;}
	void insert(T* data);
	void showAll() {head->show();}
private:
	HeadNode<T>* head;
};

template <class T> LinkList<T>::LinkList()
{
	head = new HeadNode<T>;
}

template <class T> void LinkList<T>::insert(T* data)
{
	head->insert(data);
}

int main()
{
	Data* pData;
	Cat* pCat;
	LinkList<Data> ll;
	LinkList<Cat> catll;
	int val;
	while(1)
	{
		cout<<"What value? (0 to stop.)\n";
		cin>>val;
		if(!val)
			break;
		pData = new Data(val);
		pCat = new Cat(val);
		ll.insert(pData);
		catll.insert(pCat);
	}
	ll.showAll();
	catll.showAll();
	return 0;
}
