#pragma once
#include<iostream>
#include"clsDate.h"
using namespace std;

class clsUtil
{
public:


	enum enPrimeOrNot { Prime = 1, NotPrime = 2 };
	enum enPalindromeNumOrNot { Plaindrome = 1, NotPlaindrome = 2 };
	enum enCharType { CapitalLetter = 1, SmallLetter = 2, Digit = 3, SpecialChar = 4, MixChar = 5 };

	static enPrimeOrNot CheckPrimeNumber(int Number)
	{
		int M = round(Number / 2);

		for (int i = 2; i <= M; i++)
		{
			if (Number % i == 0)
				return enPrimeOrNot::NotPrime;

		}
		return enPrimeOrNot::Prime;

	}

	static void Srand()
	{
		srand(unsigned(time(NULL)));
	}

	static int ReadNumber()
	{
		int Number;

		do
		{
			cout << "\nPLease enter a number : ";
			cin >> Number;

		} while (Number < 0);

		return Number;
	}

	static void PrintPrimeNumbers(int Number)
	{
		cout << "Prime Numbers from " << 1 << " to " << Number << " are : \n";

		for (int i = 1; i <= Number; i++)
		{
			if (CheckPrimeNumber(i) == enPrimeOrNot::Prime)
				cout << i << endl;
		}
	}

	static bool CheckPerfectNumber(int Num)
	{
		int SumOfTheDivisors = 0;

		for (int i = 1; i < Num; i++)
		{
			if (Num % i == 0)
				SumOfTheDivisors += i;

		}
		return Num == SumOfTheDivisors;
	}

	static void PrintPerfectNumberOrNot(int Number)
	{
		if (CheckPerfectNumber(Number))
		{
			cout << "is a Perfect Number\n";
		}
		else
			cout << "is not a Perfect Number\n";

	}

	static void PrintDivisorsFrom1ToN(int Number)
	{
		for (int Counter = 1; Counter <= Number; Counter++)
		{
			if (CheckPerfectNumber(Counter))
				cout << Counter << endl;
		}
	}

	static void PrintDigitsReversed(int Number)
	{
		int Remainder = 0;

		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			cout << Remainder << endl;
		}
	}

	static int SumOfNumbersAfterSeparate(int Number)
	{
		int Remainder = 0, Sum = 0;

		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			Sum += Remainder;
		}

		return Sum;
	}

	static int ReversedNumber(int Number)
	{
		int Remainder = 0;
		int Reversed = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;

			Reversed = Reversed * 10 + Remainder;
		}
		return Reversed;
	}

	static int CountDigitFrequency(int Number, int NumberForSearch)
	{
		int Remainder = 0, Counter = 0;

		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;

			if (Remainder == NumberForSearch)
				Counter++;
		}

		return Counter;
	}

	static void PrintAllDigitsFrequency(int Number)
	{

		for (int i = 0; i < 10; i++)
		{
			short DigitFrequncy = CountDigitFrequency(Number, i);
			if (DigitFrequncy > 0)
			{
				cout << "Digit " << i << " Frequency is " << CountDigitFrequency(Number, i) << " Times\n";
			}
		}

	}

	static void PrintDigits(int Number)
	{
		Number = ReversedNumber(Number);
		int Remainder = 0;

		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			cout << Remainder << endl;

		}
	}

	static bool IsPalindromeNumber(int Number)
	{
		return ReversedNumber(Number) == Number;

	}

	static bool IsPalindromeArr(int Arr1[100], int Arr2[100], int Size)
	{
		for (int i = 0; i < Size; i++)
		{
			if (Arr1[i] != Arr2[i])
			{
				return false;
			}
		}
		return true;
	}

	static void PrintInvertedPattern(int Number)
	{
		for (int i = Number; i >= 1; i--)
		{
			for (int j = 1; j <= i; j++)
			{
				cout << i;
			}
			cout << endl;
		}
	}

	static void PrintNumberPattern(int Number)
	{
		cout << endl;

		for (int i = 1; i <= Number; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				cout << i;
			}
			cout << endl;
		}
	}

	static void PrintInvertedLetterPattern(int Number)
	{
		//char Letter = 65 + Number -1 ;
		int Counter = Number;
		cout << "\n";

		for (int i = 65 + Number - 1; i >= 65; i--)
		{
			for (int j = 1; j <= Number - (65 + Number - 1 - i); j++)
			{
				cout << char(i);
			}
			//Letter--;
			Counter--;
			cout << endl;
		}
	}

	static void PrintLetterPattern(int Number)
	{
		cout << endl;
		for (int i = 65; i <= 65 + Number - 1; i++)
		{
			for (int j = 1; j <= i - 65 + 1; j++)
			{
				cout << (char)i;
			}
			cout << "\n";
		}
	}

	static void LetterFromAAAToZZZ()
	{
		string Word = "";

		cout << endl;

		for (int i = 65; i <= 90; i++)
		{
			for (int j = 65; j <= 90; j++)
			{
				for (int z = 65; z <= 90; z++)
				{
					Word = Word + (char)i;
					Word = Word + (char)j;
					Word = Word + (char)z;

					cout << Word << endl;

					Word = "";
				}
			}
		}
	}

	static bool GuessPassword(string Password)
	{
		string Word = "";
		int Counter = 0;


		for (int i = 65; i <= 90; i++)
		{
			for (int j = 65; j <= 90; j++)
			{
				for (int k = 65; k <= 90; k++)
				{
					Counter++;


					Word = Word + (char)i;
					Word = Word + (char)j;
					Word = Word + (char)k;

					cout << "Trial [" << Counter << "] : " << Word << endl;


					if (Word == Password)
					{
						cout << "\nPassword is " << Word << endl << "Found after " << Counter << " Trials\n";
						return true;

					}
					Word = "";


				}
			}
		}
		return false;
	}

	static string EncryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = (char)((int)Text[i] + EncryptionKey);
		}
		return Text;
	}

	static string DecryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = (char)((int)Text[i] - EncryptionKey);
		}
		return Text;
	}

	static int RandomNumber(int From, int To)
	{
		int Number = From + rand() % (To - From + 1);
		return  Number;
	}

	static char GetRandomCharecter(enCharType CharType)
	{
		switch (CharType)
		{

		case enCharType::SmallLetter:
		{
			return (char)RandomNumber(97, 122);
			break;
		}
		case  enCharType::CapitalLetter:
		{
			return (char)RandomNumber(65, 90);
			break;
		}
		case enCharType::SpecialChar:
		{
			return (char)RandomNumber(33, 47);
			break;
		}
		case enCharType::Digit:
		{
			return (char)RandomNumber(48, 57);
			break;
		}
		default:
			return GetRandomCharecter((enCharType)RandomNumber(1, 3));
		}
	}

	static string GenerateWord(enCharType CharType, int Length)
	{
		string Word;
		for (int i = 0; i < Length; i++)
		{
			Word = Word + GetRandomCharecter(CharType);
		}
		return Word;
	}

	static string GenerateKey(enCharType CharType)
	{
		string Key;

		Key = Key + GenerateWord(CharType, 4) + '-';
		Key = Key + GenerateWord(CharType, 4) + '-';
		Key = Key + GenerateWord(CharType, 4) + '-';
		Key = Key + GenerateWord(CharType, 4);

		return Key;
	}

	static void GenerateKeys(int NumberOfKeys, enCharType CharType)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Key [" << i << "] : ";
			cout << GenerateKey(CharType) << endl;
		}
	}

	static void ReadArray(int Arr[100], int& Size)
	{
		cout << "\nEnter Number Of elements : \n";
		cin >> Size;

		cout << "\nEnter array elements:\n";
		for (int i = 0; i < Size; i++)
		{
			cout << "Element[" << i + 1 << "] : ";
			cin >> Arr[i];
		}
		cout << "\n";
	}

	static void PrintArrElements(int Arr[], int Size)
	{
		for (int i = 0; i < Size; i++)
		{
			cout << Arr[i] << "  ";
		}
		cout << endl;
	}

	static int NumberOfTimesNumberRepeatedInArr(int NumberToSearch, int Arr[], int Size)
	{
		int Counter = 0;
		for (int i = 0; i < Size; i++)
		{
			if (Arr[i] == NumberToSearch)
				Counter++;

		}
		return Counter;
	}

	static void FillArrayWithRandomNumber(int Arr[100], int& Size)
	{
		cout << "\nEnter Number Of elements : \n";
		cin >> Size;

		for (int i = 0; i < Size; i++)
		{
			Arr[i] = RandomNumber(1, 100);
		}
		cout << "\n";
	}

	static int MaxNumberInArray(int Arr[100], int Size)
	{
		int Max = 0;
		for (int i = 0; i < Size; i++)
		{
			if (Max <= Arr[i])
				Max = Arr[i];
		}
		return Max;
	}

	static int MinimumNumberInArray(int Arr[100], int Size)
	{
		int Min = Arr[0];
		for (int i = 0; i < Size; i++)
		{
			if (Min > Arr[i])
				Min = Arr[i];
		}
		return Min;
	}

	static int SumOfRandArrayNum(int Arr[100], int& Size)
	{
		int Sum = 0;
		for (int i = 0; i < Size; i++)
		{
			Sum += Arr[i];
		}
		return Sum;
	}

	static float ArrayAverage(int Arr[100], int Size)
	{
		return (float)SumOfRandArrayNum(Arr, Size) / Size;
	}

	static void CopyArray(int Arr1[100], int Arr2[100], int Size)
	{
		for (int i = 0; i < Size; i++)
		{
			Arr2[i] = Arr1[i];
		}

		cout << endl;
	}

	static void CopyOnlyPrimeNumbers(int Arr1[100], int Arr2[100], int Size1, int& Size2)
	{
		int Counter = 0;
		for (int i = 0; i < Size1; i++)
		{
			if (CheckPrimeNumber(Arr1[i]) == enPrimeOrNot::Prime)
			{
				Arr2[Counter] = Arr1[i];
				Counter++;
			}
		}
		Size2 = Counter;
		cout << endl;
	}

	static void SumOf2Array(int Arr1[100], int Arr2[100], int SumArr[100], int Size)
	{
		int Sum = 0;
		for (int i = 0; i < Size; i++)
		{
			SumArr[i] = Arr1[i] + Arr2[i];

		}
	}

	static void Swap(int& A, int& B)
	{
		int temp;

		temp = A;
		A = B;
		B = temp;
	}

	static void ShuffleArray(int Arr[100], int Size)
	{
		for (int i = 0; i < Size; i++)
		{
			Swap(Arr[RandomNumber(1, Size) - 1], Arr[RandomNumber(1, Size) - 1]);
		}
	}

	static void SwapArray(int Arr[100], int Size)
	{
		for (int i = 0; i <= floor(Size / 2); i++)
		{
			Swap(Arr[i], Arr[Size - i - 1]);
		}

	}

	static void CopyArrayInReversedOrder(int Arr1[100], int Arr2[100], int Size)
	{
		for (int i = 0; i < Size; i++)
		{
			Arr2[i] = Arr1[Size - i - 1];
		}
	}

	static void FillArrayWithKeys(string Arr1[100], int Size, enCharType CharType)
	{
		for (int i = 0; i < Size; i++)
		{
			Arr1[i] = GenerateKey(CharType);
		}
	}

	static int FindNumberPositionInArray(int Arr[100], int NumberToCheck, int Size)
	{

		for (int i = 0; i < Size; i++)
		{
			if (NumberToCheck == Arr[i])
				return i;
		}
		return -1;
	}

	static void PrintFoundOrNot(int Arr[100], int NumberToCheck, int Size)
	{
		int NumberPosition = FindNumberPositionInArray(Arr, NumberToCheck, Size);
		cout << "\nNumber you are lookung for is : " << NumberToCheck;

		if (NumberPosition != -1)
		{
			cout << "\nThe number found at position : " << NumberPosition;
			cout << "\nThe number found its order : " << NumberPosition + 1 << endl;
		}
		else
		{
			cout << "\nThe number is not found :-(\n";
		}
	}

	static bool IsNumberInArray(int Arr[100], int NumberPosition, int Size)
	{
		return FindNumberPositionInArray(Arr, NumberPosition, Size) != -1;
	}

	static void AddArrayElement(int Number, int Arr[100], int& Size)
	{
		Size++;
		Arr[Size - 1] = Number;
	}

	static void InputUserNumbersInArray(int Arr[100], int& Size)
	{

		bool MoreNumbers = true;
		do
		{
			AddArrayElement(ReadNumber(), Arr, Size);
			cout << "\nDo you want to add more numbers?[0]No , [1]Yes? ";
			cin >> MoreNumbers;
		} while (MoreNumbers);
	}

	static void CopyArrayUsingAddArrayElement(int Arr1[100], int Arr2[100], int Size1, int& Size2)
	{
		for (int i = 0; i < Size1; i++)
		{
			AddArrayElement(Arr1[i], Arr2, Size2);
		}
	}

	static void CopyOnlyOddNumberInArr(int Arr1[100], int Arr2[100], int Size1, int& Size2)
	{
		for (int i = 0; i < Size1; i++)
		{
			if (Arr1[i] % 2 != 0)
				AddArrayElement(Arr1[i], Arr2, Size2);

		}
	}

	static void CopyPrimeNumbersInArr(int Arr1[100], int Arr2[100], int Size1, int& Size2)
	{
		for (int i = 0; i < Size1; i++)
		{
			if (CheckPrimeNumber(Arr1[i]) == enPrimeOrNot::Prime)
				AddArrayElement(Arr1[i], Arr2, Size2);

		}
	}

	static void CopyDistinctNumber(int Arr1[100], int Arr2[100], int Size1, int& Size2)
	{
		for (int i = 0; i < Size1; i++)
		{
			if (!IsNumberInArray(Arr2, Arr1[i], Size2))
				AddArrayElement(Arr1[i], Arr2, Size2);
		}
	}

	static void PrintArrayPalindromeResult(int Arr1[100], int Arr2[100], int Size)
	{
		if (!IsPalindromeArr(Arr1, Arr2, Size))
		{
			cout << "\nNo,array is not palindrome ";
		}
		else
			cout << "\nYes array is Palindrome ";
	}

	static int NumberOfOddNumberInArray(int Arr1[100], int Size1)
	{
		int Counter = 0;
		for (int i = 0; i < Size1; i++)
		{
			if (Arr1[i] % 2 != 0)
			{
				Counter++;
			}
		}
		return Counter;
	}

	static int NumberOfEvenNumberInArray(int Arr[100], int Size)
	{
		int Counter = 0;

		for (int i = 0; i < Size; i++)
		{
			if (Arr[i] % 2 == 0)
			{
				Counter++;
			}
		}
		return Counter;
	}

	static int PositiveNumbersCount(int Arr[100], int Size)
	{
		int Counter = 0;
		for (int i = 0; i < Size; i++)
		{
			if (Arr[i] >= 0)
				Counter++;
		}
		return Counter;
	}

	static int NegativeNumbersCount(int Arr[100], int Size)
	{
		int Counter = 0;
		for (int i = 0; i < Size; i++)
		{
			if (Arr[i] < 0)
			{
				Counter++;
			}
		}
		return Counter;
	}

	static  void Swap(double& A, double& B)
	{
		double Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(bool& A, bool& B)
	{
		bool Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(char& A, char& B)
	{
		char Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(string& A, string& B)
	{
		string Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(clsDate& A, clsDate& B)
	{
		clsDate::SwapDates(A, B);

	}

	static string NumberToText(long long Number)
	{
		if (Number == 0)
			return "";
		if (Number >= 1 && Number <= 10)
		{
			string arr[] = { "" , "One" , "Two" ,"Three" , "Four" , "Five" , "Six" , "Seven" , "Eight" , "Nine"
			,"Ten" };
			return arr[Number];
		}

		if (Number >= 11 && Number <= 19)
		{
			string arr[] = { " " ,"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
					"Sixteen", "Seventeen", "Eighteen", "Nineteen" };
			return arr[Number % 10];
		}
		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { " " , " " ,"Twenty" , "Thirty" , "Forty" ,"Fifty" , "Sixty" , "Seventy" , "Eighty" , "Ninety" };
			return arr[Number / 10] + " " + NumberToText(Number % 10);
		}
		if (Number >= 100 && Number <= 199)
		{
			return NumberToText(Number / 100) + " Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return NumberToText(Number / 1000) + "Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return NumberToText(Number / 1000000) + "Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return NumberToText(Number / 1000000000) + "billion " + NumberToText(Number % 1000000000);
		}

		if (Number >= 2000000000 && Number <= 999999999999)
		{
			return NumberToText(Number / 1000000000) + "billions " + NumberToText(Number % 1000000000);
		}
	}

};



