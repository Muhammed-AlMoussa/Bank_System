#pragma warning(disable : 4996)	
#pragma once
#include<iostream>
#include<iomanip>
#include"clsUser.h"
#include"clsGlobal.h"
#include<ctime>
#include"clsDate.h"

using namespace std;

class clsScreen
{
private :

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
		cout << setw(37) << left << "" <<"---------------------------------------------------\n";

		cout << setw(37) << left << "" << "User: " << CurrentUser.GetUserName() << endl;
		cout << setw(37) << left << "" << "Date: " << clsDate::DateToString(clsDate()) << endl;
	}

	static bool _CheckUserPermissonsScreen(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.CheckUserPermissions(Permission))
		{
			
			system("cls");
			cout << "\t\t\t\t\t______________________________________";
			cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
			cout << "\n\t\t\t\t\t______________________________________\n\n";
			return false;

		}
		else
			return true;
	}
};

