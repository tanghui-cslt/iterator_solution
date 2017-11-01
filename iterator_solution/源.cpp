#include <iostream>
#include "jacobi.h"
#include "gauss_seidel.h"
#include "sor.h"
using namespace std;

void scanf_data(double ** &A, double *&x, double *&b, int &n);
void solution(double ** A, double *x, double *b, const int n);

void main()
{
	double **A = NULL, *b = NULL, *x = NULL;
	int n = 0;

	//输入数据
	scanf_data(A, x, b, n);
	//选择求解方式
	solution(A, x, b, n);

	getchar();
	getchar();
}

void scanf_data(double ** &A, double *&x, double *&b, int &n)
{
	cout << "********请输入矩阵的维数*******:\n";
	cin >> n;

	A = new double *[n];
	x = new double[n];
	b = new double[n];
	cout << "*******请输入系数矩阵A********:\n";
	for (size_t i = 0; i < n; i++)
	{
		A[i] = new double[n];
		for (size_t j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}

	cout << "*******请输入x初值*********:\n";
	for (size_t i = 0; i < n; i++)
	{
		cin >> x[i];
	}

	cout << "*******请输入向量b**********:\n";
	for (size_t i = 0; i < n; i++)
	{
		cin >> b[i];
	}
}

void solution(double ** A, double *x, double *b, const int n)
{
	int temp = 0;
	cout << "\n\n请输入求解方式\n";
	cout << "\t1 -> Jacobi\n\t2 -> Gauss-seidel\n\t3 -> SOR\n : ";
	cin >> temp;

	if (1 == temp)
	{
		cout << "\n******雅可比求解结果********：\n";
		jacobi_soultion(A, x, b, n);
	}
	else if (2 == temp)
	{
		cout << "\n******高斯赛德尔求解结果*******：\n";
		gauss_seidel_solution(A, x, b, n);
	}
	else if (3 == temp)
	{
		
		sor_soultion(A, x, b, n);
	}
	else
	{
		cout << "\n输入错误，请再输一遍\n";
		solution(A, x, b, n);
	}
}