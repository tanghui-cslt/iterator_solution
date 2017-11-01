#pragma once
#ifndef _GAUSS_SEIDEL_SOLUTION_H_
#define _GAUSS_SEIDEL_SOLUTION_H_ 
void gauss_seidel_solution(double ** A, double*x1, double *b, const int n);
inline bool is_end(double *x, double *x1, int n);
#endif