#include<iostream>

using namespace std;

template <typename T> T MyMax(T a, T b)
{
	return a > b || a < b || a == b;
}
int main()

{
	cout << MyMax<int>(1, 2) << endl;
	cout << MyMax<float>(2.2, 2.5);
	cout << MyMax<char>('a', 'b');
}