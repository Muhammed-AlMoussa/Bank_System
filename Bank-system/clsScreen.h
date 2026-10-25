#pragma once
#include<iostream>
#include<iomanip>

using namespace std;

class clsScreen
{

public :

	static void _DrawScreenHeader(string ScreenName , string Subtitle = "")
	{
		cout << "\n\n";
		cout << setw(37) << left << "" << "----------------------------------------------------\n\n";
		cout << setw(58) << left << "" << ScreenName <<"\n\n";
		if (Subtitle != "")
		{
			cout << setw(58) << left << "" << Subtitle <<"\n";
		}
		cout << setw(37) << left << "" <<"---------------------------------------------------\n\n\n";

	}

};

