#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrenciesExchangeList.h"
#include"clsFindCurrencyScreen.h"

class clsCurrencyScreen : protected clsScreen
{
private:
	enum enCurrencyMainMenuOption {eListCurrencies = 1 , eFindCurrency = 2 , 
	eUpdateRate = 3 , eCurrencyCalculator = 4 , eMainMenu = 5};

	static short _ReadCurrencyExchangeOption()
	{
		 
		cout << setw(37) << left << "" <<
		"Enter Number between 1 and 5: ";

		short Number = clsInputValidate::
			ReadShortNumberBetween(1, 5, "Enter Number between 1 and 5: ");
		return Number;
	}

	static void _GoBackToCurrecnyExchangeMenu()
	{
		cout << "\npress any key to go back to Currecy Exchange\n";

		system("pause>0");
		
		ShowCurrencyScreen();	
	}

	static void _ShowCurrenciesList()
	{

		//cout << "Currencies List would be here\n";
		clsCurrenciesExchangeList::ShowCurrenciesExchangeListScreen();
	}


	static void _ShowFindCurrencyScreen()
	{
		//cout << "Find Currency Screen would be here\n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		cout << "Update Rate screen would be here\n";
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		cout << "Currency Calculator screen would be here";
	}

	static void enPerformCurrencyMainMenuOption(enCurrencyMainMenuOption CurrencyOption)
	{
		switch (CurrencyOption)
		{
		case enCurrencyMainMenuOption::eListCurrencies:
		{
			system("cls");
			_ShowCurrenciesList();
			_GoBackToCurrecnyExchangeMenu();
			break;
		}

		case enCurrencyMainMenuOption::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrecnyExchangeMenu();
			break;
		}

		case enCurrencyMainMenuOption::eUpdateRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrecnyExchangeMenu();
			break;
		}

		case enCurrencyMainMenuOption::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrecnyExchangeMenu();
			break;
		}

		case enCurrencyMainMenuOption::eMainMenu:
		{

		}
		};
	};
public:


	static void ShowCurrencyScreen()
	{
		system("cls");
		_DrawScreenHeader("Currency Exchange");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t   Currency Exchange Main Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		enPerformCurrencyMainMenuOption((enCurrencyMainMenuOption)_ReadCurrencyExchangeOption());
	}
};

