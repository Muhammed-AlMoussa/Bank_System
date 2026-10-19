#pragma once
#include<iostream>

using namespace std;

class clsPerson
{
private:

	string _FirstName;
	string _LastName;
	string _Phone;
	string _Email;
	string _FullName;
public:

	clsPerson(string FirstName, string LastName, string Phone, string Email)
	{
		_FirstName = FirstName;
		_LastName = LastName;;
		_Email = Email;
		_Phone = Phone;
	}

	void setFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}

	string getFirstName()
	{
		return _FirstName;
	}
	__declspec(property(get = getFirstName, put = setFirstName)) string FirstName;

	void setLastName(string LastName)
	{
		_LastName = LastName;
	}
	string  getLastName()
	{
		return _LastName;
	}
	__declspec(property(get = getLastName, put = setLastName)) string LastName;

	string getFullName()
	{
		_FullName = _FirstName + " " + _LastName;
		return _FullName;
	}
	void setEmail(string Email)
	{
		_Email = Email;
	}

	string getEmail()
	{
		return _Email;
	}
	__declspec(property(get = getEmail, put = setEmail)) string Email;

	void setPhone(string Phone)
	{
		_Phone = Phone;
	}

	string getPhone()
	{
		return _Phone;
	}
	__declspec(property(get = getPhone, put = setPhone)) string Phone;

};

