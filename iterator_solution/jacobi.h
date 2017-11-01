#pragma once
#ifndef _JACOBI_H_
#define _JACOBI_H_

void jacobi_soultion(double ** A,double*x1, double *b, const int n);
inline bool is_end(double *x, double *x1, int n);
#endif