#ifndef VECTOR_H
#define VECTOR_H

// Joseph Watts
// 10/9/18
// N.Eloe
// OS Project 1

#include <stdio.h>
#include <stdlib.h>

typedef struct vector {
	int maxCapacity;
	int numElements;
	int *data;
} vector;

void vinit(vector * v);
int vadd(vector * v, int value);
int vrm(vector * v, int idx);
void vcleanup(vector * v);
int vget(vector v, int idx, int * result);
int vset(vector v, int idx, int value);
int vsize(vector v);
int vcapacity(vector v);

ENDIF // VECTOR_H
