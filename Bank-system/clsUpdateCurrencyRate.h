#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsString.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"

class clsUpdateCurrencyRate : protected clsScreen
{
private:
	static void _PrintCurrencyCard(clsCurrency cCurrency)
	{
		cout << "\nCorrency Card: \n";
		cout << "\n___________________";
		cout << "\nCountry    : " << cCurrency.getCountry();
		cout << "\nCode       : " << cCurrency.getCurrencyCode();
		cout << "\nName       : " << cCurrency.getCurrencyName();
		cout << "\nRate(1$) = : " << cCurrency.getRate();
		cout << "\n___________________\n";
	}

	static void _ShowResult(clsCurrency cCurrency)
	{
		if (!cCurrency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n ";
			_PrintCurrencyCard(cCurrency);
		}

		else
		{
			cout << "\nCourrecy Did not found\n";
			return;
		}
	}

public:

	static void ShowUpdateCurrencyScreen()
	{
		_DrawScreenHeader("Update Currency Screen");

		cout << "\nPlease enter Currency Code: ";
		string CurrencyCode = clsInputValidate::ReadString();
		clsCurrency cCurrency = clsCurrency::FindByCurrencyCode(CurrencyCode);
		if(!cCurrency.IsEmpty())
		{

			cout << "\nCurrency Found :-)\n ";
			_PrintCurrencyCard(cCurrency);

			cout << "\nAre you sure you want ot update the rate of this currency y/n? ";
			char Answer = 'n';

			cin >> Answer;

			if (tolower(Answer) == 'y')
			{
				double NewRate;

				cout << "\nEnter New Rate: ";
				cin >> NewRate;

				cout << "CurrencyUpdate it Successfully \n\n";
				cCurrency.UpdateRate(NewRate);
				_ShowResult(cCurrency);
			}
		}
		else
		{
			cout << "\nCourrecy Did not found\n";
			
		}
	}
};

