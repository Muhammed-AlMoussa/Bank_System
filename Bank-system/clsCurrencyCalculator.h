#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"
#include<string>

class clsCurrencyCalculator : protected clsScreen
{
private:

	static string _ReadCurrencyCode()
	{
		cout << "\nPlease Enter Currency Code: ";
		string CurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nPlease enter Currency Code: ";
			CurrencyCode = clsInputValidate::ReadString();

		}
		return CurrencyCode;
	}
	static float _ReadAmount()
	{
		float Amount;
		cout << "\nEnter Amount to Exchange: ";
		cin >> Amount;
		return Amount;
	}

	static void _PrintCurrency(clsCurrency cCurrency)
	{

		cout << "\n___________________";
		cout << "\nCountry    : " << cCurrency.getCountry();
		cout << "\nCode       : " << cCurrency.getCurrencyCode();
		cout << "\nName       : " << cCurrency.getCurrencyName();
		cout << "\nRate(1$) = : " << cCurrency.getRate();
		cout << "\n___________________\n";
	}

	static void _CalculateCurrencies( string FromCurrencyCode , string ToCurrencyCode)
	{
		float Amount = _ReadAmount();

		clsCurrency FromCurrency = clsCurrency::FindByCurrencyCode(FromCurrencyCode);
		clsCurrency ToCurrency = clsCurrency::FindByCurrencyCode(ToCurrencyCode);

		if (clsString::UpperAllString(ToCurrencyCode) == "USD")
		{
			cout << "\nConvert From: \n";

			_PrintCurrency(FromCurrency);
			cout << "\n" << Amount << " " << FromCurrencyCode << " = ";
			cout << clsCurrency::ToDollar(Amount, FromCurrency.getRate());

		}

		else if (clsString::UpperAllString(FromCurrencyCode) == "USD")
		{
			cout << "\nConvert To: \n";
			_PrintCurrency(ToCurrency);
			cout << "\n" << Amount << " " << ToCurrencyCode << " = ";
			cout << clsCurrency::FromDollar(Amount, ToCurrency.getRate());
		}

		else
		{
			cout << "\nConvert From: \n";

			_PrintCurrency(FromCurrency);
			cout << "\n" << Amount << " " << FromCurrencyCode << " = ";
			float Result = clsCurrency::ToDollar(Amount, FromCurrency.getRate());
			cout << Result;

			cout << "\n\nConvert To: \n";
			_PrintCurrency(ToCurrency);
			cout << "\n" << Amount << " " << ToCurrencyCode << " = ";
			cout << clsCurrency::FromDollar(Amount, ToCurrency.getRate());

		}
	}

public:
	static void ShowCurrencyCalculatorScreen()
	{
		char Answer = 'n';
		do
		{
			system("cls");
			_DrawScreenHeader("Currency Calculator Screen");

			string FromCurrencyCode = _ReadCurrencyCode();
			string ToCurrencyCode = _ReadCurrencyCode();

			_CalculateCurrencies(FromCurrencyCode, ToCurrencyCode);
			

			cout << "\n\nDo you want to perform another calculation? y/n? ";
			
			cin >> Answer;
		} while (tolower(Answer) == 'y');
	}

};

