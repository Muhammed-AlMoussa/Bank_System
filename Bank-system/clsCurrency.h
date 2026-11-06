#pragma once
#include<iostream>
#include<string>
#include"clsString.h"
#include<fstream>
#include<vector>

class clsCurrency
{
private:

	enum enMode { eEmptyMode = 0, eUpdateMode = 1 };

	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;
    static clsCurrency _ConvertLinetoCurrencyObject(string Line, string Seperator = "#//#")
    {
        vector<string> vCurrencyData;
        vCurrencyData = clsString::Split(Line, Seperator);

        return clsCurrency(enMode::eUpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2],
            stod(vCurrencyData[3]));

    }

    static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
    {

        string stCurrencyRecord = "";
        stCurrencyRecord += Currency.getCountry() + Seperator;
        stCurrencyRecord += Currency.getCurrencyCode() + Seperator;
        stCurrencyRecord += Currency.getCurrencyName() + Seperator;
        stCurrencyRecord += to_string(Currency.getRate());

        return stCurrencyRecord;

    }

    static  vector <clsCurrency> _LoadCurrencysDataFromFile()
    {

        vector <clsCurrency> vCurrencys;

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {

                clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);

                vCurrencys.push_back(Currency);
            }

            MyFile.close();

        }

        return vCurrencys;

    }

    static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencys)
    {

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsCurrency C : vCurrencys)
            {
                DataLine = _ConverCurrencyObjectToLine(C);
                MyFile << DataLine << endl;



            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsCurrency> _vCurrencys;
        _vCurrencys = _LoadCurrencysDataFromFile();

        for (clsCurrency& C : _vCurrencys)
        {
            if (C.getCurrencyCode() == getCurrencyCode())
            {
                C = *this;
                break;
            }

        }

        _SaveCurrencyDataToFile(_vCurrencys);

    }

    static clsCurrency _GetEmptyCurrencyObject()
    {
        return clsCurrency(enMode::eEmptyMode, "", "", "", 0);
    }

public:

	clsCurrency(enMode Mode, string Country, string CurrencyCode,
		string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	string getCurrencyName()
	{
		return _CurrencyName;
	}

	string getCurrencyCode()
	{
		return _CurrencyCode;
	}

	string getCountry()
	{
		return _Country;
	}

	void UpdateRate(float NewRate)
	{
        _Rate = NewRate;
		_Update();
	}

    float getRate()
    {
        return _Rate;
    }

    static clsCurrency FindByCountry(string Country)
    {
        Country = clsString::UpperFirstLetterOfEachWord(Country);

        vector <clsCurrency> Currency = _LoadCurrencysDataFromFile();

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);

        if (MyFile.is_open())
        {
            for (clsCurrency& C : Currency)
            {

                if (C.getCountry() == Country)
                {
                    MyFile.close();
                    return C;
                }
            }
            

        }
        MyFile.close();

        return _GetEmptyCurrencyObject();
    }

    static clsCurrency FindByCurrencyCode(string CurrencyCode)
    {
        CurrencyCode = clsString::UpperAllString(CurrencyCode);
        vector <clsCurrency> Currency = _LoadCurrencysDataFromFile();

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);

        if (MyFile.is_open())
        {
            for (clsCurrency& C : Currency)
            {

                if (C.getCurrencyCode() == CurrencyCode)
                {
                    MyFile.close();
                    return C;
                }
            }
            

        }
        MyFile.close();
        return _GetEmptyCurrencyObject();
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::eEmptyMode);
    }

    static bool IsCurrencyExist(string CurrencyName)
    {
        clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyName);

        return (!Currency.IsEmpty());
    }

    static vector <clsCurrency> GetCurrenciesList()
    {
        return _LoadCurrencysDataFromFile();
    }
};

