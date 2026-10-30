#pragma once
#include"clsPerson.h"
#include<vector>
#include<fstream>
#include<string>
#include"clsString.h"
#include"clsDate.h"

class clsUser :public clsPerson
{
private:
	struct stLoginRegisterRecord;

	string _UserName;
	string _Password;
	bool _MarkUserToDelete = false;
	short _Permissions;

	enum enMode { eEmptyMode = 0, eUpdateMode = 1, eAddMode = 2 };
	enMode _Mode;

	static vector <clsUser> _LoadUsersDataFromFile()
	{
		fstream User;
		vector <clsUser> vUser;

		User.open("Users.txt", ios::in);
		if (User.is_open())
		{
			string UserInfo;
			while (getline(User, UserInfo))
			{
				clsUser sUser = _ConvertLineToUserObject(UserInfo);
				vUser.push_back(sUser);
			}
			User.close();
		}
		return vUser;
	}

	string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#")
	{
		string UserRecord = "";
		UserRecord += User.FirstName + Seperator;
		UserRecord += User.LastName + Seperator;
		UserRecord += User.Email + Seperator;
		UserRecord += User.Phone + Seperator;
		UserRecord += User.UserName + Seperator;
		UserRecord += User.Password + Seperator;
		UserRecord += to_string(User.Permissions);

		return UserRecord;

	}

	void _SaveUsersDataToFile(vector <clsUser>& vUser)
	{
		fstream User;
		User.open("Users.txt", ios::out);
		if (User.is_open())
		{
			string UserData;
			for (clsUser s : vUser)
			{
				if (s._MarkUserToDelete == false)
				{
					UserData = _ConvertUserObjectToLine(s, "#//#");
					User << UserData << endl;
				}
			}
			User.close();
		}
	}

	static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#")
	{
		vector<string> vUserData;
		vUserData = clsString::Split(Line, Seperator);

		return clsUser(enMode::eUpdateMode, vUserData[0], vUserData[1], vUserData[2],
			vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));

	}

	static clsUser _GetEmptyUser()
	{
		return clsUser(enMode::eEmptyMode, "", "", "", "", "", "", 0);
	}

	void  _AddNewUser()
	{
		_AddUser(_ConvertUserObjectToLine(*this));
	}

	void _AddUser(string UserData)
	{
		fstream User;
		User.open("Users.txt", ios::app);
		if (User.is_open())
		{

			User << UserData << endl;

			User.close();
		}
	}

	void _Update()
	{
		vector <clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : _vUsers)
		{
			if (U.UserName == UserName)
			{
				U = *this;
				break;
			}

		}

		_SaveUsersDataToFile(_vUsers);

	}

	string _PrepareRegisterLogIn(clsUser User , string Seprator = "#//#")
	{
		string UserRegisterInfo = "";

		UserRegisterInfo += clsDate::GetSystemDateTimeString() + Seprator;
		UserRegisterInfo += User.UserName + Seprator;
		UserRegisterInfo += User.Password + Seprator;
		UserRegisterInfo += to_string(User.Permissions);

		return UserRegisterInfo;
	}

	void _SaveUsersLoginRegisterToFile()
	{
		string UserLogin = _PrepareRegisterLogIn(*this);

		fstream UsersLoginFile;
		UsersLoginFile.open("LoginRegister.txt", ios::app);

		if (UsersLoginFile.is_open())
		{
			UsersLoginFile << UserLogin << endl;

			UsersLoginFile.close();
		}
	}

	static stLoginRegisterRecord _UserRegisterLineToObj(string UserRegisterLine , string Separator = "#//#")
	{

		vector <string> vRegister = clsString::Split(UserRegisterLine, Separator);
		stLoginRegisterRecord sLoginRegister;

		sLoginRegister._LoginRegistDate = vRegister[0];
		sLoginRegister.UserName = vRegister[1];
		sLoginRegister.Password = vRegister[2];
		sLoginRegister.Permissions = stoi(vRegister[3]);

		return sLoginRegister;
	}

	static vector <stLoginRegisterRecord> _LoadUserRegisterDataFromFile()
	{
		vector<stLoginRegisterRecord> vUserRegister;

		fstream UserRegister;

		UserRegister.open("LoginRegister.txt", ios::in);
		if (UserRegister.is_open())
		{
			string RegisterLine;
			while (getline(UserRegister, RegisterLine))
			{
				stLoginRegisterRecord cUser = _UserRegisterLineToObj(RegisterLine);
				vUserRegister.push_back(cUser);
			}

			UserRegister.close();
		}
		return vUserRegister;
	}

public:

	enum enPermissions {
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64 ,
		pListLogInRegister = 128
	};

	struct stLoginRegisterRecord
	{
		string UserName;
		string Password;
		string _LoginRegistDate;
		short Permissions;
	};

	clsUser(enMode Mode, string FirstName, string LastName,
		string Phone, string Email,  string UserName, string Password,
		int Permissions) :
		clsPerson(FirstName, LastName, Email, Phone)

	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	string GetUserName()
	{
		return _UserName;
	}

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	void SetPassword(string Password)
	{
		_Password = Password;
	}

	string GetPassword()
	{
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermissions(short Permissions)
	{
		_Permissions = Permissions;
	}

	short GetPermissions()
	{
		return _Permissions;
	}
	__declspec(property(get = GetPermissions, put = SetPermissions)) short Permissions;

	bool IsEmpty()
	{
		return (_Mode == enMode::eEmptyMode);
	}

	static bool IsUserExistByUserName(string UserName)
	{
		vector <clsUser> vUser = _LoadUsersDataFromFile();
		for (clsUser& s : vUser)
		{
			if (UserName == s._UserName)
				return true;
		}
		return false;
	}

	static bool IsUserExistByPassowrdAndUserName(string UserName , string Password)
	{
		vector <clsUser> vUser = _LoadUsersDataFromFile();
		for (clsUser& s : vUser)
		{
			if (UserName == s._UserName && Password == s._Password)
			{
				return true;
			}
		}
		return false;
	}

	static clsUser Find(string UserName)
	{
		vector <clsUser> vUsers = _LoadUsersDataFromFile();

		for (clsUser& S : vUsers)
		{
			if (S._UserName == UserName)
			{
				S._Mode = enMode::eUpdateMode;
				return S;
			}
		}
		return _GetEmptyUser();
	}

	static clsUser Find(string UserName, string Password)
	{
		clsUser User = Find(UserName);

		if (User.IsEmpty())
		{
			return _GetEmptyUser();
		}
		
		if (UserName == User._UserName && Password == User._Password)
			return User;
		else
			return _GetEmptyUser();
	}

	bool Delete()
	{
		vector <clsUser> vUser = _LoadUsersDataFromFile();
		for (clsUser& C : vUser)
		{
			if (C._UserName == UserName)
			{
				C._MarkUserToDelete = true;
				_SaveUsersDataToFile(vUser);

				*this = _GetEmptyUser();
				return true;
			}
		}
		return false;
	}

	static clsUser GetNewUserObject(string UserName)
	{
		return clsUser(enMode::eAddMode, "", "", "", "", UserName, "", 0);
	}

	static vector<clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	enum enSaveResult { enSvFailEmptyProject = 0, enSvSucceeded = 1, enSvFailAccountNumberExist = 2 };

	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::eEmptyMode:
		{
			return enSaveResult::enSvFailEmptyProject;
			break;
		}
		case enMode::eUpdateMode:
		{
			_Update();

			return enSaveResult::enSvSucceeded;
			break;
		}
		case enMode::eAddMode:
		{
			if (IsUserExistByUserName(_UserName))
				return enSaveResult::enSvFailAccountNumberExist;

			else
			{
				_AddNewUser();
				_Mode = enMode::eUpdateMode;
				return enSaveResult::enSvSucceeded;
			}

		}

		}


	}

	bool CheckUserPermissions(enPermissions Permission)
	{
		if (this->Permissions== enPermissions::eAll)
			return true;
		if ((this->Permissions & Permission) == Permission)
			return true;
		else
			return false;
	}

	void RegisterLogin()
	{
		_SaveUsersLoginRegisterToFile();
	}

	static vector <stLoginRegisterRecord> GetLoginRegisterList()
	{
		return _LoadUserRegisterDataFromFile();
	}
};

