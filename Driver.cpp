#include <iostream>
#include <string.h>
using namespace std;

typedef unsigned long pDate;

enum SERVICE {PostMaster,Interchange,Gmail,Hotmail,AOL,Internet};

class String
{
public:
	//constructor
	String();
	String(const char *const);
	String(const String&);
	~String();
	//reloader
	char& operator[](int offset);
	char operator[](int offset) const;
	String operator+(const String&);
	void operator+=(const String&);
	String& operator=(const String&);
	friend ostream& operator<<(ostream& stream, String& newString);
	//general ancessors
	int getlen() const {return len;}
	const char* getString() const {return string;}
	//static int constructorCount;
private:
	String(int);
	char* string;
	int len;
};

String::String()
{
	string = new char[1];
	string[0] = '\0';
	len = 0;
}

String::String(int newlen)
{
	string = new char[newlen+1];
	for(int i=0;i<=newlen;i++)
		string[i] = '\0';
	len = newlen;
}

String::String(const char *const cString)
{
	len = strlen(cString);
	string = new char[len+1];
	for(int i=0;i<len;i++)
		string[i] = cString[i];
	string[len] = '\0';
}

String::String(const String &rhs)
{
	len = rhs.getlen();
	string = new char[len+1];
	for(int i=0;i<len;i++)
		string[i] = rhs[i];
	string[len] = '\0';
}

String::~String()
{
	delete [] string;
	len = 0;
}

String& String::operator=(const String &rhs)
{
	if(this == &rhs)
		return *this;
	delete [] string;
	len = rhs.getlen();
	string = new char[len+1];
	for(int i=0;i<len;i++)
		string[i] = rhs[i];
	string[len] = '\0';
	return *this;
}

char &String::operator[](int offset)
{
	if(offset>len)
		return string[len-1];
	else
		return string[offset];
}

char String::operator[](int offset) const
{
	if(offset>len)
		return string[len-1];
	else
		return string[offset];
}

String String::operator+(const String& rhs)
{
	int total = len + rhs.getlen();
	String temp(total);
	int i,j;
	for(i=0;i<len;i++)
		temp[i] = string[i];
	for(j=0;j<rhs.getlen();j++)
		temp[i+j] = rhs[j];
	temp[total] = '\0';
	return temp;
}

void String::operator+=(const String& rhs)
{
	int total = len + rhs.getlen();
	String temp(total);
	int i,j;
	for(i=0;i<len;i++)
		temp[i] = string[i];
	for(j=0;j<rhs.getlen();j++)
		temp[i+j] = rhs[j];
	temp[total] = '\0';
	*this = temp;
}

ostream& operator<<(ostream& stream,String& newString)
{
	stream<<newString.getString();
	return stream;
}

class pAddress
{
public:
	pAddress(SERVICE newService,const String& newAddress,const String& newDisplay):
	service(newService),address(newAddress),display(newDisplay)
	{}
	~pAddress() {}
	friend ostream& operator<<(ostream& stream,pAddress& address);
	String& getDisplayString() {return display;}

private:
	SERVICE service;
	String address;
	String display;
};

ostream& operator<<(ostream& stream,pAddress& address)
{
	stream<<address.getDisplayString();
	return stream;
}

class PostMasterMessage
{
public:
	PostMasterMessage();
	PostMasterMessage(const pAddress& newSender,
					  const pAddress& newRecipient,
					  const String& newSubject,
					  const pDate& newCreationDate);
	~PostMasterMessage() {}
	void Edit();
	pAddress& getSender() {return sender;}
	pAddress& getRecipient() {return recipient;}
	String& getSubject() {return subject;}

private:
	pAddress sender;
	pAddress recipient;
	String subject;
	pDate creationDate;
	pDate lastModDate;
	pDate firstReadDate;
	pDate lastReadDate;
};

PostMasterMessage::PostMasterMessage(const pAddress& newSender,
					  				 const pAddress& newRecipient,
					  				 const String& newSubject,
					  				 const pDate& newCreationDate):
sender(newSender),recipient(newRecipient),subject(newSubject),creationDate(newCreationDate)
{
	cout<<"PostMaster message created...\n";
}

void PostMasterMessage::Edit()
{
	cout<<"PostMaster message edit funtion called.\n";
}

int main()
{
	pAddress sender(PostMaster,"Arthur@gmail.com","Arthur");
	pAddress recipient(PostMaster,"Samantha@gmail.com","Samantha");
	PostMasterMessage post(sender,recipient,"Greetings",0);
	cout<<"Message review\t\n";
	cout<<"From\t\t"<<post.getSender()<<endl;
	cout<<"To\t\t\t"<<post.getRecipient()<<endl;
	cout<<"Subject:\t"<<post.getSubject()<<endl;
	return 0;
}
