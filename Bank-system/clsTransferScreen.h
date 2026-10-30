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

		clsBankClient Client1 = clsBankClient::Find(AccoutNumber);
		_PrintClientInfo(Client1);

		cout << "\nEnter an Account Number To transfer To: ";
		AccoutNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccoutNumber))
		{
			cout << "\nEnter an Account Number To transfer To: ";
			AccoutNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client2 = clsBankClient::Find(AccoutNumber);
		_PrintClientInfo(Client2);

		short Amount = 0;
		cout << "\nEnter Transfer Amount: ";
		Amount = clsInputValidate::
			ReadDblNumberBetween(0 , Client1.AccountBalance ,
				"Amout Exceeds the available Balance,Enter another Amount: ");

		char Accept = 'n';
		cout << "\nAre you sure you want to perform this operation?y/n: ";
		cin >> Accept;
		if(tolower(Accept) == 'y')
		{
			Client1.Withdraw(Amount);
			Client2.Deposit(Amount);

			_PrintClientInfo(Client1);
			_PrintClientInfo(Client2);
		}
		
	}

};

