#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
int Vvod(int** MS, int n_str, int s_stl)
{
	int i, j;
	if (!MS)                           // �������� �� ������� �� ���������
	{
		puts("������ ��� ������� (�������) �� ��������");
		return 1;
	}
	printf("\n���� ������� (�������)");
	for (i = 0; i < n_str; i++)        // ���� �� ������� �������(�������)
		for (j = 0; j < s_stl; j++)        // ���� �� ��������� ������ (��������) �������(�������)
		{
			printf("MS[ %d ][ %d ] = ", i, j);
			fflush(stdin); //rewind(stdin);        // ������ �������� ������
			if (!scanf_s("%d", *(MS + i) + j)) j--;  // �������� ������� �� �����
			// if (!scanf("%d", &MS[i][j]));       // ����� ������������ � MS[i][j] 
		}
	return 0;
}

void Print(int** MS, int n_str, int s_stl)
{
	int i, j;
	if (!MS)                              // �������� �� ������� �� ���������
	{
		puts("������ ��� ������� (�������) �� ��������");
		return;
	}
	printf("\n");
	for (i = 0; i < n_str; i++)           // ���� �� ������� �������(�������)
	{
		for (j = 0; j < s_stl; j++)       // ���� �� ��������� ������ (��������) �������(�������)
			printf("%4d", *(*(MS + i) + j));
		// printf("%4d", MS[i][j]);   // ����� ������������ � MS[i][j] 
		printf("\n");
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int** p = nullptr, n, s, i, j,k=0;
	float x;
	printf("������� x: ");
	scanf_s("%f", &x);
	do
	{
		printf("\n������� ���������� ����� �������: ");
		i = scanf_s("%d", &n);
		if (i < 1)
		{
			fflush(stdin);  // ������ ������� ���������� ��� ������ �����
			continue;       // ������ �����
		}
		s = 2 * n;             //���-�� ��������
		if (!(p = (int**)malloc(sizeof(int*) * n)))
			printf("\n������������ ��������� ������ \n��������� ����� ����� �������");
		for (i = 0; i < n; i++) // ���� ������ ��������� �� ������ �������
			if (!(*(p + i) = (int*)malloc(sizeof(int) * s))) // ��������� ������ ��� ������ �������
			{                                               // � ��������� �������� �� ������
				printf("\n������������ ��������� ������ \n���������� ����� ��-��� �������");
				for (j = 0; j < i; j++) free(*(p + j)); free(p); // ������������ ������ ��� ������
				p = nullptr;   // ����� ��������� ��� ������� �������� ��������� ������
				break;         // ����� �� ����� �� i (������ ��������� �� ������ �������)
			}
	} while (!p);
	Vvod(p, n, s);
	system("CLS");
	printf("\n��������� �������");
	Print(p, n, s);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < s; j++)        
		{
			k++;
			if (*(*(p + i) + j) <= x)
			{
				printf("b(%d) = 1, ", k);
			}
			else
			{
				printf("b(%d) = 0, ", k);
			}
		}
	}

       

	return 0;
}