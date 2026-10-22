#pragma once
#include<iostream>
#include<iomanip>

using namespace std;

class clsScreen
{

public :

	static void _DrawScreenHeader(string ScreenName)
	{
		cout << "\n\n";
		cout << setw(90)  << "----------------------------------------------------\n\n";
		cout << setw(70)  << ScreenName << endl;
		cout << setw(90)  << "---------------------------------------------------\n\n\n";

	}

};

