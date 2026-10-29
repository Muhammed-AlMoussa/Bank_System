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
		short Trials = 3;
		do
		{
			if (LoginFailed)
			{
				cout << "\nLogin Failed!\n";
				cout << "You have only " << Trials << "trial(s)\n";
			}
			if (Trials == 0)
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
			
			Trials--;
		} while (LoginFailed);
		CurrentUser.SaveLoginRegister();

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

