#pragma once
#include<iostream>
#include"clsGlobal.h"
#include"clsUser.h"
#include"clsScreen.h"
#include"clsLoginScreen.h"

class clsLogout : protected clsScreen
{
private :
	//static void _GoBackToLoginScreen()
	//{
	//	cout << "\nPress any key to go back to login Screen\n";
	//	system("pause");
	//	clsLoginScreen::ShowLoginScreen();
	//}
public:
	static void Logout()
	{
		CurrentUser = clsUser::Find("", "");
		//_GoBackToLoginScreen();
	}
};

