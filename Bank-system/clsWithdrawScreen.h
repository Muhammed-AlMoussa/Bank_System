#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"

class clsWithdrawScreen :protected clsScreen
{

private :

    static void _PrintClient(clsBankClient Client)
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

	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("Withdraw Screen: ");

        cout << "\nEnter an AccountNumber: ";
        string AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist,Enter another one: \n";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        double Amount = 0;
        cout << "\nPlease enter a Withdraw amount? ";
        Amount = clsInputValidate::ReadDblNumberBetween(1 , Client1.AccountBalance,"Enter a valid Amount: ");

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            Client1.Withdraw(Amount);
            cout << "\nAmount Withdrawed Successfully.\n";
            cout << "\nNew Balance Is: " << Client1.AccountBalance;

        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }
	}


};

