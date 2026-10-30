#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"

class clsAddNewUserScreen :protected clsScreen
{

private:
    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Permission: ";
        User.Permissions = _ReadPermissionsToSet();
    }

    static void _PrintUser(clsUser User)
    {

        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.getFullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {


            Permissions |= clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {
            Permissions |= clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {
            Permissions |= clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {
            Permissions |= clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {
            Permissions |= clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {
            Permissions |= clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {
            Permissions |= clsUser::enPermissions::pManageUsers;
        }

        cout << "\nShow Register List Screen? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {
            Permissions |= clsUser::enPermissions::pListLogInRegister;
        }
        return Permissions;

    }


public:

    static void AddNewUserScreen()
    {
        _DrawScreenHeader("Add New User Screen");

        cout << "\nEnter a User Name: ";
        string UserName = clsInputValidate::ReadString();
        while (clsUser::IsUserExistByUserName(UserName))
        {
            cout << "User Name Exist, Enter another User Name: ";
            UserName = clsInputValidate::ReadString();
        }
        clsUser NewUser = clsUser::GetNewUserObject(UserName);
        _ReadUserInfo(NewUser);

        clsUser::enSaveResult SaveResult;
        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case clsUser::enSaveResult::enSvSucceeded:
        {
            cout << "\nAccount Update it Successfuly\n";
            _PrintUser(NewUser);
            break;
        }
        case clsUser::enSaveResult::enSvFailEmptyProject:
        {
            cout << "\nError account was not saved because it's Empty\n";
            break;
        }
        case clsUser::enSaveResult::enSvFailAccountNumberExist:
        {
            cout << "\nError account was not saved because the AccoutNumber Exist.\n";
            break;
        }
        }
    }
};

