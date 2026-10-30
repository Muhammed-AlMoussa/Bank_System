#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"

class clsTransferScreen : protected clsScreen
{
private:

	static void _PrintClientInfo(clsBankClient Client)
	{
		cout << "\nClient Card\n";
		cout << "--------------------------------\n\n";
		cout << "Full Name: " << Client.getFullName();
		cout << "\nAcc.Num: " << Client.getAccountNumber();
		cout << "\nBalance: " << Client.AccountBalance;
		cout << "\n--------------------------------\n\n";

	}

	static short _ReadAmount(clsBankClient SourceClient)
	{
		short Amount = 0;
		cout << "\nEnter Transfer Amount: ";
		Amount = clsInputValidate::
			ReadDblNumberBetween(0, SourceClient.AccountBalance,
				"Amout Exceeds the available Balance,Enter another Amount: ");
		return Amount;
	}

public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("Transfer Screen");

		cout << "\nEnter an Account Number To transfer From: ";
		string AccoutNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccoutNumber))
		{
			cout << "\nEnter an Account Number To transfer From: ";
			AccoutNumber = clsInputValidate::ReadString();
		}

		clsBankClient SourceClient = clsBankClient::Find(AccoutNumber);
		_PrintClientInfo(SourceClient);

		cout << "\nEnter an Account Number To transfer To: ";
		AccoutNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccoutNumber))
		{
			cout << "\nEnter an Account Number To transfer To: ";
			AccoutNumber = clsInputValidate::ReadString();
		}
		clsBankClient DestinationClient = clsBankClient::Find(AccoutNumber);
		_PrintClientInfo(DestinationClient);

		short Amount = _ReadAmount(SourceClient);

		char Accept = 'n';
		cout << "\nAre you sure you want to perform this operation?y/n: ";
		cin >> Accept;
		if(tolower(Accept) == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient)) 
{
				cout << "\nTransfer Complete Succefully :-)\n";
			}
			else
			{
				cout << "\nTransfer Faild :-(\n";
			}

		}
		
		_PrintClientInfo(SourceClient);
		_PrintClientInfo(DestinationClient);
	}

};

