# Project 1: Memory Management and C Error Handling

## 44-550 Operating Systems

## 25 points

This project will serve as a way for you to practice memory management in C as well as experience how error states are handled in the C programming language.  You will be implementing a `vector` "class" (`struct`) and methods to perform common operations on your data.  You may also know of the `vector` as the `ArrayList`.

### Milestones

1. Create header (`.h`) and source (`.c`) file with enough code to compile and run (and fail) all the tests.  Your `.h` and `.c` files should contain an appropriate comment header as defined on the course webiste.
2. Implement the `vinit`, `vsize`, `vcapacity`, and `vcleanup` functions (passes `init` test)
3. Implement the `vadd` and `vget` functions (passes `add` test)
4. Implement the `vrm` function (passes `rm` and `rm_err` tests)
5. Implement the `vset` function (passes `set` and `set_err` tests)

### Grading

Milestone 1 is worth 4 points.  Each passing test is worth 2 points (12 total).  Each test running without memory leaks is worth 1 point (6 total).  The remaining 3 points will be allocated based on having well formatted code, following coding standards (such as having appropriate header guards).

### Milestone and Function Descriptions

#### Milestone 1
You must have both a `.h` file and a `.c` file that define your vector.  If you do not name your files `vector.h` and `vector.c`, you must make the following changes:

* In `vectest.c` change the `#include "vector.h"` to include your `.h` file.  This is the only change you may make to the `vectest.c` file.
* In the `Makefile`, change `vector.c` to the name of your file in the first line.  You may add other targets if you want to test your 

In your `.h` file, you must define your struct that contains your resizable array.  

```c
typedef struct vector {
	// put your member "variables" here
} vector;
```

Your struct must contain at least three pieces of information: the pointer to the array/data (`int*`), the current number of elements (`int`), and the capacity of the array (`int`).  You may have any other information you want in your struct

Additionally, you must define all function prototypes:
* `void vinit(vector * v);`
* `int vadd(vector * v, int value);`
* `int vrm(vector * v, int idx);`
* `void vcleanup(vector * v);`
* `int vget(vector v, int idx, int * result);`
* `int vset(vector v, int idx, int value);`
* `int vsize(vector v);`
* `int vcapacity(vector v);`

In your `.c` file, you must `#include` your header file and write definitions of the functions.  For now, have any `void` function have an empty body and any function that returns an `int` return `-1`.  At this point you should be able to run `make test` (on your Linux instance), then watch all the tests fail when you run `./test`.

You may name the parameters whatever you want, but you should maintain the types (pay special attention to which functions take poitners to vectors, and which just take the vectors)

#### `vinit`

This function should take a pointer to a vector, allocate enough space for `2` ints, set the capacity to 2, and the size to 0.

#### `vadd`

Welcome to your first interaction with error handling in C.  A common way of dealing with problem states in C is to have functions take pointers to data that needs to change (or to the "return" value) and return a value indicating if the operation was successful

`vadd` should do the following:

```c
if the vector is full (size == capacity):
    double the capacity
    if the malloc or realloc failed (returned NULL)
        return 0
put the value at the next available index in your vector
increment the size
return 1
```

Functions that call the `vadd` function would then check the return value to see if operations were successful or not.  Error handling has vastly improved since the introduction of the exception

#### `vrm`

This method should return 0 if the index specified is greater than the maximum index (which is size - 1).  Otherwise, remove the value at the specified index by shifting values left in the array (and decrementing size afterwords) and return 1.

#### `vcleanup`

Appropriately free the memory allocated in the vector, and set the pointer to NULL.  Additionally set the size and capacity to zero.

#### `vget`

If the specified index is allowed, set the value of the `result` parameter to be the value at the index and return 1.  Otherwise, return 0.

#### `vset`

If the specified index is allowed, set the value of the vector at the index to be value and return 1.  Otherwise, return 0.

#### `vsize`

Return the size (number of elements) of the vector.

#### `vcapacity`

Return the capacity (maximum number of elements) of the vector.