#pragma once
#include<iostream>
#include"clsScreen.h"
#include<string>
#include"clsUser.h"

class clsRegisterLoginScreen : protected clsScreen
{
private:
    static void _PrintUserRegisterLine(clsUser::stLoginRegisterRecord RegisterLogIn)
    {
        cout << setw(8) << left << "" << "| " << left << setw(35) << RegisterLogIn._LoginRegistDate;
        cout << "| " << left << setw(20) << RegisterLogIn.UserName;
        cout << "| " << left << setw(20) << RegisterLogIn.Password;
        cout << "| " << left << setw(10) << RegisterLogIn.Permissions;
    }
public:

	static void ShowRegisterScreen()
	{

        if (!_CheckUserPermissonsScreen(clsUser::enPermissions::pListLogInRegister)) 
        {
            return;
        }

		vector <clsUser::stLoginRegisterRecord> vRegisterLogIn = clsUser::GetLoginRegisterList();


		string Title = "Login Register List Screen";
		string Subtitle = ("(" + to_string(vRegisterLogIn.size()) + ") Clients");
		_DrawScreenHeader(Title , Subtitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Register Date";
        cout << "| " << left << setw(20) << "User Name";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vRegisterLogIn.size() == 0)
            cout << "No Logins Available In the System!\n";

        for (clsUser::stLoginRegisterRecord& S : vRegisterLogIn)
        {
            _PrintUserRegisterLine(S);
            cout << "\n";
        }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

	}

};

