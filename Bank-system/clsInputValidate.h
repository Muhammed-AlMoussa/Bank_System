#pragma once
#include<iostream>
#include"clsDate.h"

using namespace std;

class clsInputValidate
{
public:

	static bool IsNumberBetween(short Number, short From, short To)
	{
		return ((Number >= From) && (Number <= To));
	}

	static bool IsNumberBetween(int Number, int From, int To)
	{
		return ((Number >= From) && (Number <= To));
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		return ((Number >= From) && (Number <= To));
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		return ((Number >= From) && (Number <= To));
	}

	static bool IsDateBetween(clsDate SystemDate, clsDate DateFrom, clsDate DateTo)
	{
		if ((clsDate::IsDate1AfterDate2(SystemDate, DateFrom) || clsDate::IsDate1EqualDate2(SystemDate, DateFrom)) &&
			(clsDate::IsDate1BeforeDate2(SystemDate, DateTo) || clsDate::IsDate1EqualDate2(SystemDate, DateTo)))
		{
			return true;
		}
		if ((clsDate::IsDate1AfterDate2(SystemDate, DateTo) || clsDate::IsDate1EqualDate2(SystemDate, DateTo)) &&
			(clsDate::IsDate1BeforeDate2(SystemDate, DateFrom) || clsDate::IsDate1EqualDate2(SystemDate, DateFrom)))
		{
			return true;
		}
		return false;
	}

	static int ReadIntNumber(string StringValidationMessage)
	{
		int Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << StringValidationMessage << endl;
		}
		return Number;
	}

	static short ReadShortNumber(string StringValidationMessage)
	{
		short Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << StringValidationMessage << endl;
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string StringValidationMessage)
	{
		int Number = ReadIntNumber(StringValidationMessage);
		while (!IsNumberBetween(Number, From, To))
		{
			cout << StringValidationMessage;
			Number = ReadIntNumber(StringValidationMessage);
		}
		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string StringValidationMessage)
	{
		double Number = ReadDblNumber(StringValidationMessage);
		while (!IsNumberBetween(Number, From, To))
		{
			cout << StringValidationMessage;
			Number = ReadDblNumber(StringValidationMessage);
		}
		return Number;
	}

	static int ReadShortNubmerBetween(short From, short To, string StringValidationMessage)
	{
		short Number = ReadShortNumber(StringValidationMessage);
		while (!IsNumberBetween(Number, From, To))
		{
			cout << StringValidationMessage;
			Number = ReadShortNumber(StringValidationMessage);
		}
		return Number;
	}


	static double ReadDblNumber(string Messge)
	{
		double Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Messge << endl;
		}
		return Number;
	}

	static bool IsValideDate(clsDate cDate)
	{
		return clsDate::IsValidDate(cDate);
	}

	static string ReadString()
	{
		string S1;
		getline(cin >> ws, S1);
		return S1;
	}
};
