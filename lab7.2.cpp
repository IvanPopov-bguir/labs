#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
int Vvod(int** MS, int n_str, int s_stl)
{
	int i, j;
	if (!MS)                           // проверка не нулевой ли указатель
	{
		puts("память для массива (матрицы) не выделена");
		return 1;
	}
	printf("\nВвод массива (матрицы)");
	for (i = 0; i < n_str; i++)        // цикл по строкам массива(матрицы)
		for (j = 0; j < s_stl; j++)        // цикл по элементам строки (столбцам) массива(матрицы)
		{
			printf("MS[ %d ][ %d ] = ", i, j);
			rewind(stdin); 
			if (!scanf_s("%d", *(MS + i) + j)) j--;  // проверка введено ли число
		}
	return 0;
}

void Print(int** MS, int n_str, int s_stl)
{
	int i, j;
	if (!MS)                              // проверка не нулевой ли указатель
	{
		puts("память для массива (матрицы) не выделена");
		return;
	}
	printf("\n");
	for (i = 0; i < n_str; i++)           // цикл по строкам массива(матрицы)
	{
		for (j = 0; j < s_stl; j++)       // цикл по элементам строки (столбцам) массива(матрицы)
			printf("%4d", *(*(MS + i) + j));
		    printf("\n");
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int** p = nullptr, n, s, i, j,k=0;
	float x;
	printf("Введите x: ");
	scanf_s("%f", &x);
	do
	{
		printf("\nВведите количество строк матрицы: ");
		i = scanf_s("%d", &n);
		if (i < 1)
		{
			fflush(stdin);  // чистка буффера клавиатуры при ошибке ввода
			continue;       // повтор цикла
		}
		s = 2 * n;             //кол-во столбцов
		if (!(p = (int**)malloc(sizeof(int*) * n)))
			printf("\nНедостаточно свободной памяти \nУменьшите число строк матрицы");
		for (i = 0; i < n; i++) // цикл выбора указателя на строку матрицы
			*(p + i) = (int*)malloc(sizeof(int) * s);
			if (!*(p + i)) // выделение памяти под строку матрицы
			{                                               // с проверкой выделена ли память
				printf("\nНедостаточно свободной памяти \nУуменьшите число ст-цов матрицы");
				for (j = 0; j < i; j++) free(*(p + j)); free(p); // освобождение памяти при ошибке
				p = nullptr;   // сброс указателя для повтора операции выделения памяти
				break;         // выход из цикла по i (выбора указателя на строку матрицы)
			}
	} while (!p);
	Vvod(p, n, s);
	system("CLS");
	printf("\nВведенная матрица");
	Print(p, n, s);
	printf("\n");
	int check = 1;
	for (i = 0; i < n; i++)
	{
		check = 1;
		for (j = 0; j < s; j++)
		{   
			if (*(*(p + i) + j) > x)
			{
				check = 0;
				break;
			}

		}
		printf("b(%d) = %d ", i, check);
	}
	return 0;
}

//for i in each row
//	check_row(i)
//  print result
