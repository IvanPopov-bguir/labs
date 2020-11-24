#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
int Vvod(float** mas, int n_str, int s_stl)
{
	int i, j;
	if (!mas)                           // �������� �� ������� �� ���������
	{
		printf("������ ��� ������� (�������) �� ��������");
		return 1;
	}
	printf("\n���� ������� (�������)");
	for (i = 0; i < n_str; i++)        
		for (j = 0; j < s_stl; j++)        
		{
			printf("MS[ %d ][ %d ] = ", i, j);
			rewind(stdin); 
			if (!scanf_s("%f", *(mas + i) + j)) j--;  // �������� ������� �� �����
		}
	return 0;
}

void Print(float** mas, int n_str, int s_stl)
{
	int i, j;
	if (!mas)                     // �������� �� ������� �� ���������
	{
		printf("������ �� ��������");
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
	printf("������� x: ");
	scanf_s("%f", &x);
	do
	{
		printf("\n������� ���������� ����� �������: ");
		scanf_s("%d", &n);
		if (n < 1)
		{
			rewind(stdin);      // ������ ������� ���������� ��� ������ �����
			continue;           // ������ �����
		}
		s = 2 * n;              //���-�� ��������
		if (!(p = (float**)malloc(sizeof(float*) * n)))
			printf("\n������������ ��������� ������ ");
		for (i = 0; i < n; i++) // ���� ������ ��������� �� ������ �������
		{
			*(p + i) = (float*)malloc(sizeof(float) * s);

			if (!*(p + i))      // ��������� ������ ��� ������ ������� � ���������
			{
				for (j = 0; j < i; j++)
				{
					free(*(p + j));
					free(p);
					p = nullptr;// ����� ��������� ��� ������� �������� ��������� ������
					break;      // ����� �� ����� �� i (������ ��������� �� ������ �������)
				}
			}
		}
	} while (!p);
	Vvod(p, n, s);
	printf("\n��������� �������");
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