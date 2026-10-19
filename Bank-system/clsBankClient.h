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
	enum enMode{eEmptyMode = 0 , eUpdateMode = 1};
	enMode _eMode;

	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;

	static clsBankClient _ConvertLineToClientObject(string Line , string Separator = "#//#")
	{
		vector <string> vClient = clsString::Split(Line, Separator);

		return clsBankClient(enMode::eUpdateMode ,vClient[0], vClient[1], vClient[2], vClient[3], vClient[4],
			vClient[5], stod(vClient[6]));
	}

	static clsBankClient _GetEmptyClient()
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

	static clsBankClient Find(string AccountNumber)
	{
		fstream ClientFile;
		
		ClientFile.open("Clients.txt", ios::in);
		if(ClientFile.is_open())
		{
			string ClientInfo;
			while (getline(ClientFile, ClientInfo))
			{
				clsBankClient ClientObj = _ConvertLineToClientObject(ClientInfo);
				if (ClientObj._AccountNumber == AccountNumber)
				{
					ClientFile.close();
					return ClientObj;
				}
			}
			ClientFile.close();
		}
		return _GetEmptyClient();
	}

	static clsBankClient Find(string AccountNumber, string PINCode)
	{
		clsBankClient ClientObj = Find(AccountNumber);

		if (ClientObj._PinCode == PINCode)
			return ClientObj;

		return _GetEmptyClient();
	}

	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFull Name   : " << getFullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << _AccountNumber;
		cout << "\nPassword    : " << _PinCode;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n___________________\n";

	}


};

