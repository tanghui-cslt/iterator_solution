#include "gauss_seidel.h"
#include <iostream>
using namespace std;

#define E 1e-6
bool is_end(double *x, double *x1, int n)
{
	double max = 0.0;
	for (size_t i = 0; i < n; i++)
	{
		double diff = fabs(x[i] - x1[i]);
		max = diff > max ? diff : max;
	}
	if (max < E)
	{
		return true;
	}
	return false;
}

void gauss_seidel_solution(double ** A, double*x1, double *b, const int n)
{
	double *x = new double[n];
	double counts = 100;


	//迭代求解
	do {
		counts--;
		if (counts == 0)
		{
			break;
		}

		//将新的x1赋值为x
		for (size_t i = 0; i < n; i++)
		{
			x[i] = x1[i];
		}

		//计算x1的值
		for (size_t i = 0; i < n; i++)
		{
			double sum = 0;
			for (size_t j = 0; j < n; j++)
			{
				if (i < j)
				{
					sum += A[i][j] * x[j];
				}
				else if (i>j)
				{
					sum += A[i][j] * x1[j];
				}
			}
			x1[i] = (b[i] - sum) / A[i][i];
		}
	} while (!is_end(x, x1, n));

	cout << "\n\t迭代次数 :" << 100 - counts << endl;
	for (size_t i = 0; i < n; i++)
	{
		cout << "\tx[" << i << "]=" << x1[i] << "\t";
	}
	cout << endl;

}