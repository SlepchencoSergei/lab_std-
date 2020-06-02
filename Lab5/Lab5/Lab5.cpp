#include <iostream>
using namespace std;

// заполнить массив случайными числами
void fill_matrix(int a[100][100], int n, int m)
{
	// заполним двумерный массив а случайными числами от 0 до 100
	for (int i = 0; i < n; i++)
	{
		// заполним случайными числами i строку 
		for (int j = 0; j < m; j++)
		{
			a[i][j] = rand() % 100;
		}
	}
}

// распечатать массив 
void print_matrix(int a[100][100], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}

// удалить строку массива
void delete_row(int a[100][100], int& n, int m, int row)
{
	for (int i = row; i < n - 1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = a[i + 1][j];
		}
	}

	for (int j = 0; j < m; j++)
	{
		a[n - 1][j] = 0;
	}

	//n--;
}

int main()
{
	// ввести переменные n и m 
	int n, m;
	cout << "n = ";
	cin >> n;
	cout << "m = ";
	cin >> m;

	int a[100][100];

	// заполнить массив случайными числами
	fill_matrix(a, n, m);
	
	// распечатать массив 
	print_matrix(a, n, m);

	int start, end;

	// вводим начальную строку для удаления
	cout << "a = ";
	cin >> start;

	// вводим конечную строку для удаления
	cout << "b = ";
	cin >> end;

	// удалим из массива a строки с начальной a по конечную b 
	for (int i = start; i <= end; i++)
	{
		delete_row(a, n, m, i);
	}

	// распечатать массив результат
	cout << "Result" << endl;
	print_matrix(a, n, m);
}
