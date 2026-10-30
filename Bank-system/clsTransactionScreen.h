#pragma once
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"

class clsTransactionScreen :protected clsScreen
{
private :
    enum enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3, eShowMainMenue = 4
    };

    static short _ReadShortNumber()
    {
        short Number = clsInputValidate::
            ReadShortNumberBetween(1, 4, "Enter Number Between 1 & 4 : ");
        return Number;
    }

    static void _ShowDepositScreen()
    {
        //cout << "\n Deposit Screen will be here.\n";
        clsDepositScreen::DepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        //cout << "\n Withdraw Screen will be here.\n";
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        //cout << "\n Balances Screen will be here.\n";
        clsTotalBalancesScreen::ShowTotalBalancesScreen();
    }

    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowTransactionsMenue();

    }

    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }


        case enTransactionsMenueOptions::eShowMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }
    }

public:

	static void ShowTransactionsMenue()
	{
        if (!_CheckUserPermissonsScreen(clsUser::enPermissions::pTranactions))
        {
            return;
        }
        system("cls");
		_DrawScreenHeader("Transaction Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "Choose what do you want to do: ";

        _PerformTransactionsMenueOption((enTransactionsMenueOptions)_ReadShortNumber());
	}
};

