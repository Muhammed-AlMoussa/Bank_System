#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"

class clsFindCurrencyScreen : protected clsScreen
{
private:
	enum enFindCurrncy {eCode = 1 , eCountry = 2};


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
		}
	}
public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("Find Currency Screen");

		cout << "\nFind By: [1] Code or [2] Country ? ";
		enFindCurrncy FindOption = (enFindCurrncy)clsInputValidate
			::ReadShortNumberBetween(1, 2, "Find By: [1] Code or [2] Country ? ");

		if (FindOption == enFindCurrncy::eCode)
		{
			cout << "\nPlease enter CurrencCode : ";
			string CurrencyCode = clsInputValidate::ReadString();

			clsCurrency cCurrency= clsCurrency::FindByCurrencyCode(CurrencyCode);
			_ShowResult(cCurrency);
		}

		else
		{
			cout << "\nPlease enter Country Name : ";
			string CountryName = clsInputValidate::ReadString();

			clsCurrency cCurrency = clsCurrency::FindByCountry(CountryName);
			_ShowResult(cCurrency);
		}
	}
};

