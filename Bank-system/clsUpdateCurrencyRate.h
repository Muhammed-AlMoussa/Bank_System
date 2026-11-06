#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsString.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"

class clsUpdateCurrencyRate : protected clsScreen
{
private:

	static float _ReadNewRate()
	{
		double NewRate;

		cout << "\nEnter New Rate: ";
		cin >> NewRate;
		return NewRate;
	}
	static void _PrintCurrencyCard(clsCurrency cCurrency)
	{
		cout << "\nCurrency Found :-)\n ";

		cout << "\nCorrency Card: \n";
		cout << "\n___________________";
		cout << "\nCountry    : " << cCurrency.getCountry();
		cout << "\nCode       : " << cCurrency.getCurrencyCode();
		cout << "\nName       : " << cCurrency.getCurrencyName();
		cout << "\nRate(1$) = : " << cCurrency.getRate();
		cout << "\n___________________\n";
	}
public:

	static void ShowUpdateCurrencyScreen()
	{
		_DrawScreenHeader("Update Currency Screen");

		cout << "\nPlease enter Currency Code: ";
		string CurrencyCode = clsInputValidate::ReadString();
		
		
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nPlease enter Currency Code: ";

			CurrencyCode = clsInputValidate::ReadString();
			
		}
		clsCurrency cCurrency = clsCurrency::FindByCurrencyCode(CurrencyCode);
		_PrintCurrencyCard(cCurrency);

			cout << "\nAre you sure you want ot update the rate of this currency y/n? ";
			char Answer = 'n';

			cin >> Answer;

			if (tolower(Answer) == 'y')
			{
				

				cCurrency.UpdateRate(_ReadNewRate());
				cout << "CurrencyUpdate it Successfully \n\n";
				_PrintCurrencyCard(cCurrency);

			}
	}
};

