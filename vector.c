#include "vector.h"

void vinit(vector * v) {
	(*v).data = malloc(2 * sizeof(int));
	(*v).maxCapacity = 2;
	(*v).numElements = 0;
}

int vadd(vector * v, int value) {
	// if it is full, 
	if ()
	
	// increase the number of elements by 1.
	(*v).numElements += 1;
}

int vrm(vector * v, int idx) {
	return -1;
}

void vcleanup(vector * v) {

}

int vget(vector v, int idx, int * result) {
	return -1;
}

int vset(vector v, int idx, int value) {
	return -1;
}

int vsize(vector v) {
	return v.numElements;
}

int vcapacity(vector v) {
	return v.maxCapacity;
}

