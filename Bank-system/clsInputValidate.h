#pragma once
#include<iostream>
#include"clsDate.h"

using namespace std;

class clsInputValidate
{
public:

	 template <typename T> static bool IsNumberBetween(T Number, T From, T To)
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

	template <typename T> static T ReadNumber(string StringValidationMessage)
	{
		T Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << StringValidationMessage << endl;
		}
		return Number;
	}

	template <typename T> static T ReadNumberBetween(T From, T To, string StringValidationMessage)
	{
		T Number = ReadNumber<T>(StringValidationMessage);
		while (!IsNumberBetween(Number, From, To))
		{
			cout << StringValidationMessage;
			Number = ReadNumber<T>(StringValidationMessage);
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
