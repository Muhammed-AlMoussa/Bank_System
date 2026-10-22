#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"clsString.h"
#include<fstream>
#include"clsPerson.h"

class clsBankClient :public clsPerson
{
private:
	enum enMode { eEmptyMode = 0, eUpdateMode = 1, eAddMode = 2 };
	enMode _eMode;

	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	bool MarkToDelete = false;

	static clsBankClient _ConvertLineToClientObject(string Line, string Separator = "#//#")
	{
		vector <string> vClient = clsString::Split(Line, Separator);

		return clsBankClient(enMode::eUpdateMode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4],
			vClient[5], stod(vClient[6]));
	}

	static clsBankClient _GetEmptyClient()
	{
		return clsBankClient(enMode::eEmptyMode, "", "", "", "", "", "", 0);
	}

	string _ConvertClientObjectToLine(clsBankClient Client, string Separator = "#//#")
	{
		string Line = "";
		Line += Client.FirstName + Separator;
		Line += Client.LastName + Separator;
		Line += Client.Email + Separator;
		Line += Client.Phone + Separator;
		Line += Client.getAccountNumber() + Separator;
		Line += Client.PinCode + Separator;
		Line += to_string(Client.AccountBalance);
		return Line;
	}

	static vector <clsBankClient> _LoadClientDataFromFile()
	{
		fstream ClientFile;
		vector <clsBankClient> Clients;

		ClientFile.open("Clients.txt", ios::in);
		if (ClientFile.is_open())
		{
			string ClientInfo;

			while (getline(ClientFile, ClientInfo))
			{
				clsBankClient ClientObj = _ConvertLineToClientObject(ClientInfo);

				Clients.push_back(ClientObj);
			}

			ClientFile.close();
		}
		return Clients;
	}

	void _SaveClientObjectToFile(vector <clsBankClient>& Clients)
	{
		fstream ClientFile;
		ClientFile.open("Clients.txt", ios::out);

		if (ClientFile.is_open())
		{
			string Line;
			for (clsBankClient& C : Clients)
			{
				if (C.MarkToDelete == false)
				{
					Line = _ConvertClientObjectToLine(C);
					ClientFile << Line << endl;
				}
			}
			ClientFile.close();
		}
	}

	void _Update()
	{
		vector <clsBankClient> _vClients = _LoadClientDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.getAccountNumber() == getAccountNumber())
			{
				C = *this;
				_SaveClientObjectToFile(_vClients);
			}
		}
	}

	void _AddNew(string Line)
	{
		fstream ClientFile;
		ClientFile.open("Clients.txt", ios::app);
		if (ClientFile.is_open())
		{
			ClientFile << Line << endl;
			ClientFile.close();
		}
	}

	void _AddNewClient()
	{
		_AddNew(_ConvertClientObjectToLine(*this));
	}

public:

	clsBankClient(enMode eMode, string FirstName, string LastName, string Email, string Phone,
		string AccountNumber, string PINCode, double Salary) :
		clsPerson(FirstName, LastName, Phone, Email)
	{
		_eMode = eMode;
		_AccountNumber = AccountNumber;
		_PinCode = PINCode;
		_AccountBalance = Salary;
	}

	string getAccountNumber()
	{
		return _AccountNumber;
	}

	void setPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string getPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = getPinCode, put = setPinCode)) string PinCode;

	void setAccountBalance(double AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	double getAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = getAccountBalance, put = setAccountBalance)) double AccountBalance;

	static clsBankClient Find(string AccountNumber)
	{
		fstream ClientFile;

		ClientFile.open("Clients.txt", ios::in);
		if (ClientFile.is_open())
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

		if (ClientObj.IsEmpty())
		{
			return _GetEmptyClient();
		}

		if (ClientObj._PinCode == PINCode)
			return ClientObj;

		return _GetEmptyClient();
	}

	static clsBankClient GetNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::eAddMode, "", "", "", "", AccountNumber, "", 0);
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	bool IsEmpty()
	{
		return (_eMode == enMode::eEmptyMode);
	}

	bool Delete()
	{
		vector <clsBankClient> vClient = _LoadClientDataFromFile();
		for (clsBankClient& C : vClient)
		{
			if (C.getAccountNumber() == getAccountNumber())
			{
				C.MarkToDelete = true;
				_SaveClientObjectToFile(vClient);
				*this = _GetEmptyClient();
				return true;
			}
		}
		return false;
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

	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientDataFromFile();
	}

	static double GetTotalBalances()
	{
		vector <clsBankClient> vClients = GetClientsList();
		double TotalBalance = 0;

		for (clsBankClient& C : vClients)
		{
			TotalBalance += C.AccountBalance;
		}
		return TotalBalance;
	}

	enum enSaveResult {enSvFailEmptyProject = 0 , enSvSucceeded = 1 , enSvFailAccountNumberExist = 2};

	enSaveResult Save()
	{
		switch (_eMode)
		{
		case enMode::eEmptyMode:
		{
			return enSaveResult::enSvFailEmptyProject;
			break;
		}
		case enMode::eUpdateMode:
		{
			_Update();

			return enSaveResult::enSvSucceeded;
			break;
		}
		case enMode::eAddMode:
		{
			if (IsClientExist(_AccountNumber))
				return enSaveResult::enSvFailAccountNumberExist;
			
			else
			{
				_AddNewClient();
				_eMode = enMode::eUpdateMode;
				return enSaveResult::enSvSucceeded;
			}

		}

		}
	
	
	}
};

