#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"

class clsDeleteClientScreen :protected clsScreen
{
private :
	static void _Print(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.getFullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.getAccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

public :
	static void ShowDeleteClientScreen()
	{
		if (!_CheckUserPermissonsScreen(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}

		_DrawScreenHeader("Delete Client");
		char Accept = 'n';
		cout << "\nEnter an Account Number: ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccountNumber does not exist, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_Print(Client);

		cout << "\nAre you sure? y/n";
		cin >> Accept;
		if (tolower(Accept) == 'y')
		{
			if (Client.Delete())
			{
				cout << "\nClient Delete Successfuly\n";
				_Print(Client);
			}
			else
				cout << "\nError, Client does not delete,Try again!.\n";;
		}

	}
};

