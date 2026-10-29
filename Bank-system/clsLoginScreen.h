#pragma once
#include<iostream>
using namespace std;
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsGlobal.h"
#include"clsMainScreen.h"

class clsLoginScreen : protected clsScreen
{
private :
	static bool _Login()
	{
		
		bool LoginFailed = false;
		short Trys = 3;
		do
		{
			if (LoginFailed)
			{
				cout << "\nLogin Failed!\n";
				cout << "You have only " << Trys << "time(s)\n";
			}
			if (Trys == 0)
			{
				cout << "\nyou are locked after 3 faild trails \n";
				return false;
			}
			cout << "\nEnter User Name: ";
			string UserName = clsInputValidate::ReadString();

			cout << "Enter Password: ";
			string Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);
			LoginFailed = CurrentUser.IsEmpty();
			
			Trys--;
		} while (LoginFailed);
		
		clsMainScreen::ShowMainMenue();
		return true;
	}

public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("Login Screen");
		return _Login();
	}

};

