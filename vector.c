// Joseph Watts
// 10/9/18
// Eloe 44550-01-f18
// project-1-JosephCW


#include "vector.h"

// Initialize our vector 
void vinit(vector * v) {
	(*v).data = malloc(2 * sizeof(int));
	(*v).maxCapacity = 2;
	(*v).numElements = 0;
}

// Add a value to our vector
int vadd(vector * v, int value) {
	// if it is full, double the size of the collection
	if ((*v).maxCapacity == (*v).numElements) {
		(*v).data = realloc((*v).data, 2 * (*v).maxCapacity * sizeof(int));
		// Increase the maxCapacity variable
		(*v).maxCapacity *= 2;
	}
	// Set the last value to be the newly inserted value.
	(*v).data[(*v).numElements] = value;
	// increase the number of taken elements by 1.
	(*v).numElements += 1;
	return 1;
}

int vrm(vector * v, int idx) {
	return 1;
}

void vcleanup(vector * v) {
	free((*v).data);
	(*v).maxCapacity = 0;
	(*v).numElements = 0;
	v = NULL;
}

int vget(vector v, int idx, int * result) {
	return 1;
}

int vset(vector v, int idx, int value) {
	return 1;
}

int vsize(vector v) {
	return v.numElements;
}

int vcapacity(vector v) {
	return v.maxCapacity;
}

