#include "sor.h"
#include <iostream>
using namespace std;

//������ֹ����
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

void sor_soultion(double ** A, double*x1, double *b, const int n)
{
	double *x = new double[n];
	int counts = 100;
	double w = 0;
	cout << "\n******������wϵ��***********\n";
	cout << "\tw := (0,2)" << endl;
	cin >> w;

	cout << "\n******SOR�����*******��\n\n";
	//�������
	do {
		counts--;
		if (counts == 0)
		{
			break;
		}


		//���µ�x1��ֵΪx
		for (size_t i = 0; i < n; i++)
		{
			x[i] = x1[i];
		}

		//����x1��ֵ
		for (size_t i = 0; i < n; i++)
		{
			double sum = 0;
			for (size_t j = 0; j < n; j++)
			{

				if (i < j)
				{
					sum += A[i][j] * x[j];
				}
				else if (i > j)
				{
					sum += A[i][j] * x1[j];
				}
			}
			x1[i] = (b[i] - sum) / A[i][i];
			// ����ϵ���������
			x1[i] = (1 - w)*x[i] + w * x1[i];
		}

	} while (!is_end(x, x1, n));
	cout << "\t�������� " << 100 - counts << endl;
	for (size_t i = 0; i < n; i++)
	{
		cout << "\tx[" << i << "]=" << x1[i] << "\t";
	}
	cout << endl;

}