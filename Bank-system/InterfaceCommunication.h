#pragma once
#include<iostream>
#include<string>

class InterfaceCommunication
{
	//we are making the definition of the abstract class that force you to implement 
		//some feature by making pure virtual methods
public:

	virtual void SendEmail(string Body, string Title) = 0;
	virtual void SendSMS(string Body, string Title) = 0;
	virtual void SendFax(string Body, string Title) = 0;
};

