#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"clsString.h"
#include<fstream>
#include"clsPerson.h"
#include"clsDate.h"
#include"clsGlobal.h"

class clsBankClient :public clsPerson
{
private:
	enum enMode { eEmptyMode = 0, eUpdateMode = 1, eAddMode = 2 };
	enMode _eMode;
	struct stTransferLog;
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

	string _PrepareTransferLogLine(double Amount, clsBankClient DestinationClient , string Separator = "#//#")
	{
		string TransferLogLine = "";

		TransferLogLine += clsDate::GetSystemDateTimeString() + Separator;
		TransferLogLine += this->getAccountNumber() + Separator;
		TransferLogLine += DestinationClient.getAccountNumber() + Separator;
		TransferLogLine += to_string(Amount) + Separator;
		TransferLogLine += to_string(this->AccountBalance) + Separator;
		TransferLogLine += to_string(DestinationClient.AccountBalance) + Separator;
		TransferLogLine += CurrentUser.UserName;

		return TransferLogLine;

	}

	void _SaveTransferLogToFile(double Amount , clsBankClient DestinationClient)
	{
		string TransferLoginLine = _PrepareTransferLogLine(Amount, DestinationClient);

		fstream TransferLog;
		TransferLog.open("TransferLog.txt",ios::out | ios::app);
		if (TransferLog.is_open())
		{
			TransferLog << TransferLoginLine << endl;
			TransferLog.close();
		}
	}

	static stTransferLog _ConvertTransferLogLineToSturct(string TransferLine , string Separator = "#//#")
	{
		vector <string> vTransferRecords = clsString::Split(TransferLine, Separator);

		stTransferLog sTransferInfo;
		sTransferInfo.DataTimeTransfer = vTransferRecords[0];
		sTransferInfo.SourceAccNum = vTransferRecords[1];
		sTransferInfo.DestinationAccNum = vTransferRecords[2];
		sTransferInfo.Amount = stod(vTransferRecords[3]);
		sTransferInfo.SourceBalance = stod(vTransferRecords[4]);
		sTransferInfo.DestinationBalance = stod(vTransferRecords[5]);
		sTransferInfo.UserName = vTransferRecords[6];

		return sTransferInfo;
	}

	static  vector <stTransferLog> _LoadTransferLogDataFromFile()
	{
		vector <stTransferLog> vTransferLog;
		
		fstream TransferLog;
		TransferLog.open("TransferLog.txt", ios::in);
		if (TransferLog.is_open())
		{
			string TransferLogRecord;
			while (getline(TransferLog, TransferLogRecord)) 
			{
				stTransferLog sTransferLogInfo =
					_ConvertTransferLogLineToSturct(TransferLogRecord);
				vTransferLog.push_back(sTransferLogInfo);
			}
			TransferLog.close();
		}
		return vTransferLog;
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

	struct stTransferLog
	{
		string SourceAccNum;
		string DestinationAccNum;
		string DataTimeTransfer;
		double Amount;
		string UserName;
		double SourceBalance;
		double DestinationBalance;
	};

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

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}
	 
	void Withdraw(double Amount)
	{
		_AccountBalance -= Amount;
		Save();
	}

	bool Transfer(double Amount , clsBankClient& Client2)
	{
		if (Amount > AccountBalance)
			return false;
		
		Withdraw(Amount);
		Client2.Deposit(Amount);
		_SaveTransferLogToFile(Amount , Client2);
		return true;
		
	}

	static vector <stTransferLog> GetTransferLogList()
	{
		return _LoadTransferLogDataFromFile();
	}
};

