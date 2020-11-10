#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;
void rec(int* mas, int* mas2, const int Low, const int Max, int i, int sum, int j)
{
	if (i < 20)
	{
		mas[i] = Low + rand() % (Max - Low + 1);
		cout << setw(3) << mas[i] << " ";
		if (mas[i] < 0 && mas[i] % 2 == 0)
		{
			sum += mas[i];
			++j;
			mas2[i] = 0;
		}
		else
			mas2[i] = mas[i];
		return rec(mas, mas2, Low, Max, ++i, sum, j);
	}
	else
	{
		cout << endl;
		cout << "________________________________________________________________________________" << endl;
		cout << "Сумма тих, які є парні та від'ємні: " << sum << endl;
		cout << "Кількість тих, які є парні та від'ємні: " << j << endl;
		cout << "________________________________________________________________________________" << endl;
	}
}
void print(int* mas2, int i)
{
	if (i < 20)
	{
		cout << setw(3) << mas2[i] << " ";
		return print(mas2, ++i);
	}
}
int main()
{
	srand((unsigned)time(NULL));
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int mas[20];
	int* mas2 = new int[20];
	cout << "Рекурсивний: " << endl;
	rec(mas, mas2, -24, 32, 0, 0, 0);
	print(mas2, 0);
	cout << endl;
	cout << "________________________________________________________________________________" << endl;
	delete[] mas2;
}

