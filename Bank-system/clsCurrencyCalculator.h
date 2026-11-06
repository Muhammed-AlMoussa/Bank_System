#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"
#include<string>

class clsCurrencyCalculator : protected clsScreen
{
private:

	static clsCurrency _ReadCurrencyCode(string Message)
	{
		cout << Message << endl;
		string CurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << Message << endl;
			CurrencyCode = clsInputValidate::ReadString();

		}
		clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);

		return Currency;
	}
	static float _ReadAmount()
	{
		float Amount;
		cout << "\nEnter Amount to Exchange: ";
		cin >> Amount;
		return Amount;
	}

	static void _PrintCurrencyCard(clsCurrency cCurrency , string Title)
	{
		cout << Title << endl;
		cout << "\n___________________";
		cout << "\nCountry    : " << cCurrency.getCountry();
		cout << "\nCode       : " << cCurrency.getCurrencyCode();
		cout << "\nName       : " << cCurrency.getCurrencyName();
		cout << "\nRate(1$) = : " << cCurrency.getRate();
		cout << "\n___________________\n";
	}

	static void _PrintCalculationResult(clsCurrency Currency1, clsCurrency Currency2, float Amount)
	{
		float USDAmount = Currency1.CurrencyToDollar(Amount);

		_PrintCurrencyCard(Currency1, "\nConvert From: \n");
		cout << Amount << " " << Currency1.getCurrencyCode() << " = " <<
			USDAmount << endl;

		if (Currency1.getCurrencyCode() == "USD")
		{
			return;
		}
	
		_PrintCurrencyCard(Currency2, "Convert To: \n");
		float AmountCurrency2 = Currency1.ConvertToOtherCurrecny(Amount, Currency2);
		cout << USDAmount << " " << Currency2.getCurrencyCode() << " = " <<
			AmountCurrency2 << endl;
	}
	
public:
	static void ShowCurrencyCalculatorScreen()
	{
		char Answer = 'n';
		do
		{
			system("cls");
			_DrawScreenHeader("Currency Calculator Screen");

			
			clsCurrency CurrencyFrom = _ReadCurrencyCode("\nPlease Enter Currency From Code: ");
			clsCurrency CurrencyTo = _ReadCurrencyCode("\nPlease Enter Currency To Code: ");

			float Amount = _ReadAmount();

			_PrintCalculationResult(CurrencyFrom, CurrencyTo , Amount);
			

			cout << "\n\nDo you want to perform another calculation? y/n? ";
			
			cin >> Answer;
		} while (tolower(Answer) == 'y');
	}

};

