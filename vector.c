// Joseph Watts
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
	// If the index is too high return 0.
	if (idx >= (*v).numElements) {
		return 0;
	}
	// Remove value at specified index by shifting values down
	for (int i = idx; i < (*v).numElements - 1; i++) {
		(*v).data[i] = (*v).data[i+1];
	}
	// decrement the current number of held values
	(*v).numElements -= 1;
}

void vcleanup(vector * v) {
	// I think free(v) is all you need but not sure
//	free((*v).data);
//	free(&((*v).maxCapacity));
//	free(&((*v).numElements));
//	free(v);
}

int vget(vector v, int idx, int * result) {
	// If index is allowed set value of reslt paramater
	// to be the value at the index and return 1.
	// otherwise return 0.
	if (idx >= v.numElements) {
		return 0;
	}
	*result = v.data[idx];
	return 1;
}

int vset(vector v, int idx, int value) {
	// If the index is too large, return 0
	if (idx >= v.numElements) {
		return 0;
	}
	v.data[idx] = value;
}

int vsize(vector v) {
	return v.numElements;
}

int vcapacity(vector v) {
	return v.maxCapacity;
}

