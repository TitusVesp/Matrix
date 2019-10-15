#include "Matrix.h"
void InitMatrix(int** matrix, int m, int n)
{
	srand(time(NULL));

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = rand() % 10;
}

void Matrix8()
{
	cout << " Дана матрица размера M × N и целое число K (1 ≤ K ≤ N). Вывести элементы K-го столбца данной матрицы." << endl;
	int n = 0, m = 0, k = 0;
	cout << "Input M: " << endl;
	cin >> m;
	cout << "Input N: " << endl;
	cin >> n;
	cout << "Input K: " << endl;
	cin >> k;
	if (!(1 <= n && 1 <= m && 1 <= k && k <= n)) { cout << "Incorrect input!" << endl; return; }

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++)
		matrix[i] = new int[n];
	InitMatrix(matrix, m, n);

	cout << endl << "Until: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

	cout << "After: " << endl;
	for (int i = 0; i < m; i++) cout << matrix[i][k] << " ";

	for (int i = 0; i < m; i++)
		delete[]matrix[i];
	delete[] matrix;
	cout << endl << endl;
}

void Matrix16()
{
	cout << "Дана квадратная матрица A порядка M (M — нечетное число). Начиная с элемента A1,1 и \n\
перемещаясь против часовой стрелки, вывести все ее элементы по спирали : первый столбец, \n\
последняя строка, последний столбец в обратном порядке, первая строка в обратном порядке, оставшиеся\n\
элементы второго столбца и т.д.; последним выводится центральный элемент матрицы. " << endl;
	int n = 0, m = 0;
	cout << "Input M: " << endl;
	cin >> m;
	n = m;
	if (!(1 <= n && 1 <= m && m % 2 != 0)) { cout << "Incorrect input!" << endl; return; }

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++)
		matrix[i] = new int[n];
	InitMatrix(matrix, m, n);

	cout << endl << "Until: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

	cout << "After: " << endl;
	for (int k = 0, j = 0, count = 0; k < m; k++, j++)
	{
		for (int i = k; i < m - k; i++)
		{
			cout << matrix[i][j] << " ";
			count++;
			if (count % 5 == 0 && count != 0) cout << endl;
		}
		for (int i = m - k - 1, g = k + 1; g < m - k; g++)
		{
			cout << matrix[i][g] << " ";
			count++;
			if (count % 5 == 0 && count != 0) cout << endl;
		}
		for (int i = m - k - 1, g = m - k - 2; g > k; g--)
		{
			cout << matrix[g][i] << " ";
			count++;
			if (count % 5 == 0 && count != 0) cout << endl;
		}
		for (int i = k, g = m - k - 1; g > k; g--)
		{
			cout << matrix[i][g] << " ";
			count++;
			if (count % 5 == 0 && count != 0) cout << endl;
		}
	}

	for (int i = 0; i < m; i++)
		delete[]matrix[i];
	delete[] matrix; cout << endl << endl;
}

void Matrix24()
{
	cout << "Дана матрица размера M × N. В каждом столбце матрицы найти максимальный элемент. " << endl;
	int n = 0, m = 0;
	cout << "Input M: " << endl;
	cin >> m;
	cout << "Input N: " << endl;
	cin >> n;
	if (!(1 <= n && 1 <= m)) { cout << "Incorrect input!" << endl; return; }

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++)
		matrix[i] = new int[n];
	InitMatrix(matrix, m, n);

	cout << endl << "Until: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

	cout << "After: " << endl;
	int max = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == 0) max = matrix[i][j];
			if (max < matrix[i][j])  max = matrix[i][j];;
		}
		cout << "Max number in row " << i + 1 << " = " << max << endl;
	}

	for (int i = 0; i < m; i++)
		delete[]matrix[i];
	delete[] matrix; cout << endl << endl;
}

void Matrix34()
{
	cout << "Дана целочисленная матрица размера M × N. Найти номер последней\n\
из ее строк, содержащих только четные числа.Если таких строк нет, то вывести 0" << endl;
	int n = 0, m = 0;
	cout << "Input M: " << endl;
	cin >> m;
	cout << "Input N: " << endl;
	cin >> n;
	if (!(1 <= n && 1 <= m)) { cout << "Incorrect input!" << endl; return; }

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++)
		matrix[i] = new int[n];
	InitMatrix(matrix, m, n);

	cout << endl << "Until: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

	cout << "After: " << endl;
	int count = 0;
	for (int i = m - 1; i > 0; i--)
	{
		count = 0;
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] % 2 == 0) count++;
		}
		if (count == n)
		{
			cout << "Num of row: " << i + 1 << endl;
			for (int i = 0; i < m; i++)
				delete[]matrix[i];
			delete[] matrix; cout << endl << endl;
			return;
		}
	}

	cout << "Num of row: " << 0 << endl;

	for (int i = 0; i < m; i++)
		delete[]matrix[i];
	delete[] matrix; cout << endl << endl;
}

void Matrix51()
{
	cout << "Дана матрица размера M × N. Поменять местами строки, содержащие\n\
минимальный и максимальный элементы матрицы." << endl;
	int n = 0, m = 0, num_max = 0, num_min = 0, max = 0, min = 0;
	cout << "Input M: " << endl;
	cin >> m;
	cout << "Input N: " << endl;
	cin >> n;
	if (!(1 <= n && 1 <= m)) { cout << "Incorrect input!" << endl; return; }

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++)
		matrix[i] = new int[n];
	InitMatrix(matrix, m, n);

	cout << endl << "Until: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 && j == 0) min = max = matrix[i][j];
			if (max < matrix[i][j]) { max = matrix[i][j]; num_max = i; }
			if (min > matrix[i][j]) { min = matrix[i][j]; num_min = i; }
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	int* temp = matrix[num_max];
	matrix[num_max] = matrix[num_min];
	matrix[num_min] = temp;

	cout << "After: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

	for (int i = 0; i < m; i++)
		delete[]matrix[i];
	delete[] matrix; cout << endl << endl;
}

void Matrix76()
{
	cout << "Дана матрица размера M × N. Упорядочить ее строки так, чтобы их\n\
первые элементы образовывали возрастающую последовательность. " << endl;
	int n = 0, m = 0, num_max = 0, num_min = 0, max = 0, min = 0;
	cout << "Input M: " << endl;
	cin >> m;
	cout << "Input N: " << endl;
	cin >> n;
	if (!(1 <= n && 1 <= m)) { cout << "Incorrect input!" << endl; return; }

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++)
		matrix[i] = new int[n];
	InitMatrix(matrix, m, n);

	cout << endl << "Until: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

	for (int k = 0; k < n; k++)
	{
			for (int j = 0; j < m - 1; j++)
			{
				if (matrix[j][0] > matrix[j + 1][0])
				{
					int* temp = matrix[j];
					matrix[j] = matrix[j+1];
					matrix[j+1] = temp;
				}
			}
			
	}
	cout << "After: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

	for (int i = 0; i < m; i++)
		delete[]matrix[i];
	delete[] matrix; cout << endl << endl;
}

void Matrix88()
{
	cout << "Дана квадратная матрица порядка M. Обнулить элементы матрицы,\n\
лежащие ниже главной диагонали.Условный оператор не использовать." << endl;
	int n = 0, m = 0;
	cout << "Input M: " << endl;
	cin >> m;
	n = m;
	if (!(1 <= n && 1 <= m)) { cout << "Incorrect input!" << endl; return; }

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++)
		matrix[i] = new int[n];
	InitMatrix(matrix, m, n);

	cout << endl << "Until: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

	for (int temp = 0, i = 0; temp < m; temp++, i++)
	{
		for (int j = 0; i > j; j++)
		{
			matrix[i][j] = 0;
		}
	}

	cout << "After: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}


	for (int i = 0; i < m; i++)
		delete[]matrix[i];
	delete[] matrix; cout << endl << endl;
}

void Matrix98()
{
	cout << "Дана квадратная матрица A порядка M. Повернуть ее на угол 180°\n\
(при этом элемент A1, 1 поменяется местами с AM, M, элемент A1, 2 — с AM, M–1\n\
и т.д.).Вспомогательную матрицу не использовать. " << endl;
	int n = 0, m = 0;
	cout << "Input M: " << endl;
	cin >> m;
	n = m;
	if (!(1 <= n && 1 <= m)) { cout << "Incorrect input!" << endl; return; }

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++)
		matrix[i] = new int[n];
	InitMatrix(matrix, m, n);

	cout << endl << "Until: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

	for (int i = 0, j = m - i - 1; i < m / 2 + 1; i++, j--)
	{
		for (int k = 0, g = n - 1; k < n; k++, g--)
		{
			int temp = matrix[i][k];
			int temp2 = matrix[j][g]; 
			matrix[i][k] = matrix[j][g];
			matrix[j][g] = temp;
			if (i == j && g == (n - 1) / 2) break;
		}
	}

	cout << "After: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

	for (int i = 0; i < m; i++)
		delete[]matrix[i];
	delete[] matrix; cout << endl << endl;
}
