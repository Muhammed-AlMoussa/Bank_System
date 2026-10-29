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
	static void _Login()
	{
		
		bool LoginFailed = false;
		do
		{
			if (LoginFailed)
			{
				cout << "Login Failed!\n";
			}
			cout << "\nEnter User Name: ";
			string UserName = clsInputValidate::ReadString();

			cout << "Enter Password: ";
			string Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);
			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		clsMainScreen::ShowMainMenue();
	}

public:
	static void ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("Login Screen");
		_Login();
	}

};

