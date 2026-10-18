#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"clsString.h"
#include<fstream>
#include"clsPerson.h"

class clsBankClient :public clsPerson
{
private :
	enum enMode{eEmptyMode = 1 , eUpdateMode = 2};
	enMode _eMode;

	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;

	clsBankClient _ConvertLineToObject(string Line)
	{
		vector <string> vClient = clsString::Split(Line, "#//#");

		return clsBankClient(enMode::eUpdateMode ,vClient[0], vClient[1], vClient[2], vClient[3], vClient[4],
			vClient[5], stod(vClient[6]));
	}

	clsBankClient _GetEmptyClient()
	{
		return clsBankClient(enMode::eEmptyMode, "", "", "", "", "", "", 0);
	}
public:

	clsBankClient(enMode eMode ,string FirstName,string LastName, string Email, string Phone,
		 string AccountNumber , string PINCode , double Salary) : 
		clsPerson(FirstName, LastName, Phone, Email)
	{
		_eMode =eMode;
		_AccountNumber = AccountNumber;
		_PinCode = PINCode;
		_AccountBalance = Salary;
	}

	static clsBankClient FindClient(string AccountNumber)
	{
		fstream ClientFile;
		
		ClientFile.open("Clients.txt", ios::in);
		if(ClientFile.is_open())
		{
			string ClientInfo;
			while (getline(ClientFile, ClientInfo))
			{
				clsBankClient ClientObj = ClientObj._ConvertLineToObject(ClientInfo);
				if (ClientObj._AccountNumber == AccountNumber)
				{
					return ClientObj;
				}
			}
			clsBankClient ClientObj = ClientObj._GetEmptyClient();
			return ClientObj;
			ClientFile.close();
		}
	}

	static clsBankClient FindClient(string AccountNumber, string PINCode)
	{
		clsBankClient ClientObj = FindClient(AccountNumber);

		if (ClientObj._PinCode == PINCode)
			return ClientObj;

		ClientObj = ClientObj._GetEmptyClient();
		return ClientObj;
	}

	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << getFirstName();
		cout << "\nLastName    : " << getLastName();
		cout << "\nFull Name   : " << getFullName();
		cout << "\nEmail       : " << getEmail();
		cout << "\nPhone       : " << getPhone();
		cout << "\nAcc. Number : " << _AccountNumber;
		cout << "\nPassword    : " << _PinCode;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n___________________\n";

	}

};

