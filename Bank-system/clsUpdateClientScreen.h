#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsUpdateClientScreen : protected clsScreen
{

private :
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter FirstName: ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter PinCode: ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter AccountBalance: ";
		Client.AccountBalance = clsInputValidate::ReadDblNumber("Invalide,Enter another one: ");
	}

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
	
	static void UpdateClientScreen()
	{
		if (!_CheckUserPermissonsScreen(clsUser::enPermissions::pUpdateClients))
		{
			return;
		}
		_DrawScreenHeader("Update Client");

		string AccountNumber = "";
		char Accept = 'n';
		cout << "\nEnter an AccountNumber: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!(clsBankClient::IsClientExist(AccountNumber)))
		{
			cout << "\nClient Account Number is not found , Enter another one: ";
			AccountNumber = clsInputValidate::ReadString();

		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_Print(Client1);

		cout << "\nUpdate Client Info:\n";
		cout << "\n----------------------\n";
		_ReadClientInfo(Client1);

		clsBankClient::enSaveResult SaveResult;
		cout << "\nAre you sure y/n? ";
		cin >> Accept;
		if (tolower(Accept) == 'y')
		{
			SaveResult = Client1.Save();

			switch (SaveResult)
			{

			case clsBankClient::enSaveResult::enSvSucceeded:
			{
				cout << "\nAccount Update it Successfuly\n";
				_Print(Client1);
				break;
			}

			case clsBankClient::enSaveResult::enSvFailEmptyProject:
			{
				cout << "\nError account was not saved because it's Empty\n";
				break;
			}
			}
		}
		else
			cout << "\nYour Changes didn't save!";
	}
	
};

