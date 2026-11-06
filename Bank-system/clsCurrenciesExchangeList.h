#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include<vector>

class clsCurrenciesExchangeList : protected clsScreen
{
private:

    static void _PrintCurrencies(clsCurrency vCurrency) 
    {
        cout << setw(8) << left << "" << "| " << left << setw(35) << vCurrency.getCountry();
        cout << "| " << left << setw(12) << vCurrency.getCurrencyCode();
        cout << "| " << left << setw(40) << vCurrency.getCurrencyName();
        cout << "| " << left << setw(10) << vCurrency.getRate();

    }
	static void _PrintCurrencyExchangeHeader()
	{
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Country";
        cout << "| " << left << setw(12) << "Code";
        cout << "| " << left << setw(40) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________________\n" << endl;

	}
public:

    static void ShowCurrenciesExchangeListScreen()
    {
        vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currency.";

        _DrawScreenHeader(Title, SubTitle);


        _PrintCurrencyExchangeHeader();

        if (vCurrencies.empty())
        {
            cout << "Currencies list is empty\n";
            return;
        }

        for (clsCurrency& C : vCurrencies)
        {
            _PrintCurrencies(C);
            cout << endl;
        }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________________\n" << endl;
    }
	
};

