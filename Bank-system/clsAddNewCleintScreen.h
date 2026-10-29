#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"

class clsAddNewCleintScreen : protected clsScreen
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

public:

	static void ShowAddNewClientScreen()
	{
		if (!CheckUserPermissonsScreen(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}

		_DrawScreenHeader("Add New Client");

		cout << "Enter an AccountNumber : ";
		string AccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Exist,choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::GetNewClientObject(AccountNumber);

		_ReadClientInfo(Client);

		clsBankClient::enSaveResult SaveResult;

		SaveResult = Client.Save();

		switch (SaveResult)
		{
		case clsBankClient::enSaveResult::enSvSucceeded:
		{
			cout << "\nAccount Update it Successfuly\n";
			_Print(Client);
			break;
		}
		case clsBankClient::enSaveResult::enSvFailEmptyProject:
		{
			cout << "\nError account was not saved because it's Empty\n";
			break;
		}
		case clsBankClient::enSaveResult::enSvFailAccountNumberExist:
		{
			cout << "\nError account was not saved because the AccoutNumber Exist.\n";
			break;
		}
		}

	}
};

