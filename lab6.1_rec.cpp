#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

void create(int* mas, const int Low, const int Max, int i);
void create2(int* mas, int* mas2, const int Low, const int Max, int i);
void print(int* mas, int i);
int sum1(int* mas, int i, int sum);
int count1(int* mas, int j, int i);
int unittest(int a[], int i, int sum);

int main()
{
	srand((unsigned)time(NULL));
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int mas[20];
	int* mas2 = new int[20];
	cout << "Рекурсивний: " << endl;
	create(mas, -24, 32, 0);
	print(mas, 0);
	cout << endl;
	create2(mas, mas2, -24, 32, 0);
	print(mas2, 0);
	cout << endl;
	cout << "Сумма тих, які є парні та від'ємні: " << sum1(mas, 0, 0) << endl;
	cout << "Кількість тих, які є парні та від'ємні: " << count1(mas, 0, 0) << endl;
	delete[] mas2;
	cout << "________________________________________________________________________________" << endl;
}
void create(int* mas, const int Low, const int Max, int i)
{
	if (i < 20)
	{
		mas[i] = Low + rand() % (Max - Low + 1);
		create(mas, Low, Max, ++i);
	}
}
void create2(int* mas, int* mas2, const int Low, const int Max, int i)
{
	if (i<=19)
	{
		if (mas[i] < 0 && mas[i] % 2 == 0)
		{
			mas2[i] = 0;
		}
		else
			mas2[i] = mas[i];
		create2(mas, mas2, Low, Max, ++i);
	}

}
void print(int* mas, int i)
{
	if (i <= 19)
	{
		cout << setw(3) << mas[i] << " ";
		print(mas, ++i);
	}
}
int sum1(int* mas, int i, int sum)
{
	if (i <= 19)
	{
		if (mas[i] < 0 && mas[i] % 2 == 0)
			sum += mas[i];
		sum1(mas, ++i, sum);
	}
	else
	return sum;
}
int count1(int* mas, int j, int i)
{
	if (i <= 19)
	{
		if (mas[i] < 0 && mas[i] % 2 == 0)
			++j;
		count1(mas, j, ++i);
	}
	else
	return j;
}
