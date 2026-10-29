#include<iostream>
#include"clsLoginScreen.h"

using namespace std;

int main()
{
	//clsMainScreen::ShowMainMenue();
	bool LoginFailed = false;
	while (!LoginFailed)
	{
		 LoginFailed = clsLoginScreen::ShowLoginScreen();
	}
	return 0;
}