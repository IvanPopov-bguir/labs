#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
int Vvod(float** mas, int n_str, int s_stl)
{
	int i, j;
	if (!mas)                           // проверка не нулевой ли указатель
	{
		printf("память для массива (матрицы) не выделена");
		return 1;
	}
	printf("\nВвод массива (матрицы)");
	for (i = 0; i < n_str; i++)        
		for (j = 0; j < s_stl; j++)        
		{
			printf("MS[ %d ][ %d ] = ", i, j);
			rewind(stdin); 
			if (!scanf_s("%f", *(mas + i) + j)) j--;  // проверка введено ли число
		}
	return 0;
}

void Print(float** mas, int n_str, int s_stl)
{
	int i, j;
	if (!mas)                     // проверка не нулевой ли указатель
	{
		printf("Память не выделена");
		return;
	}
	printf("\n");
	for (i = 0; i < n_str; i++)           
	{
		for (j = 0; j < s_stl; j++)      
			printf("%4f ", *(*(mas + i) + j));
		    printf("\n");
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	float** p = nullptr;
	int n, s, i, j;
	float x;
	printf("Введите x: ");
	scanf_s("%f", &x);
	do
	{
		printf("\nВведите количество строк матрицы: ");
		scanf_s("%d", &n);
		if (n < 1)
		{
			rewind(stdin);      // чистка буффера клавиатуры при ошибке ввода
			continue;           // повтор цикла
		}
		s = 2 * n;              //кол-во столбцов
		if (!(p = (float**)malloc(sizeof(float*) * n)))
			printf("\nНедостаточно свободной памяти ");
		for (i = 0; i < n; i++) // цикл выбора указателя на строку матрицы
		{
			*(p + i) = (float*)malloc(sizeof(float) * s);

			if (!*(p + i))      // выделение памяти под строку матрицы с проверкой
			{
				for (j = 0; j < i; j++)
				{
					free(*(p + j));
					free(p);
					p = nullptr;// сброс указателя для повтора операции выделения памяти
					break;      // выход из цикла по i (выбора указателя на строку матрицы)
				}
			}
		}
	} while (!p);
	Vvod(p, n, s);
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