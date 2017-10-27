#include <iostream>
#include"jacobi.h"
#include "gauss_seidel.h"
using namespace std;

void scanf_data(double ** &A, double *&x, double *&b, int &n);
void solution(double ** A, double *x, double *b, const int n);

void main()
{
	double **A = NULL, *b = NULL, *x = NULL;
	int n = 0;

	//��������
	scanf_data(A, x, b, n);
	//ѡ����ⷽʽ
	solution(A, x, b, n);

	getchar();
}

void scanf_data(double ** &A, double *&x, double *&b, int &n)
{
	cout << "����������ά��:\n";
	cin >> n;

	A = new double *[n];
	x = new double[n];
	b = new double[n];
	cout << "������ϵ������A:\n";
	for (size_t i = 0; i < n; i++)
	{
		A[i] = new double[n];
		for (size_t j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}

	cout << "������x��ֵ:\n";
	for (size_t i = 0; i < n; i++)
	{
		cin >> x[i];
	}

	cout << "����������b:\n";
	for (size_t i = 0; i < n; i++)
	{
		cin >> b[i];
	}
}

void solution(double ** A, double *x, double *b, const int n)
{
	int temp = 0;
	cout << "\n\n��������ⷽʽ��1��Jacobi�� 2:Gauss-seidel; 3:SOR��\n:";
	cin >> temp;

	if (1 == temp)
	{
		cout << "\n�ſɱ��������\n";
		jacobi_soultion(A, x, b, n);
	}
	else if (2 == temp)
	{
		gauss_seidel_solution(A, x, b, n);
	}
	else if (3 == temp)
	{

	}
	else
	{
		cout << "�������������һ��\n";
		solution(A, x, b, n);
	}
}