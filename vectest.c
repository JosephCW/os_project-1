#include "vector.h"
#include "acutest.h"
#include <time.h>
#include <stdlib.h>

void test_init(void)
{
	vector v;
	vinit(&v);
	TEST_CHECK(vsize(v) == 0);
	TEST_CHECK(vcapacity(v) == 2);
	vcleanup(&v);
}

void test_add_good(void)
{
	int val;
	vector v;
	vinit (&v);
	vadd(&v, 10);
	TEST_CHECK(vget(v, 0, &val));
	TEST_CHECK(val == 10);
	TEST_CHECK(vsize(v) == 1);

	vadd(&v, 1);
	TEST_CHECK(vget(v, 1, &val));
	TEST_CHECK(val == 1);
	TEST_CHECK(vsize(v) == 2);
	
	vadd(&v, 2);
	TEST_CHECK(vget(v, 2, &val));
	TEST_CHECK(val == 2);
	TEST_CHECK(vsize(v) == 3);
	// capacity should be increased now
	TEST_CHECK(vcapacity(v) == 4);

	for (int i=0; i<60; i++)
		vadd(&v, i);
	TEST_CHECK(vcapacity(v) == 64);
	TEST_CHECK(vsize(v) == 63);
	vcleanup(&v);
}

void test_rm_good(void)
{
	int val;
	vector v;
	vinit(&v);
	for (int i=0; i<10; i++)
		vadd(&v, i);
	TEST_CHECK(vsize(v) == 10);
	for (int i=0; i<10; i++)
	{
		TEST_CHECK(vget(v, 0, &val));
		TEST_CHECK(i == val);
		TEST_CHECK(vsize(v) == 10 - i);
		TEST_CHECK(vrm(&v, 0));
	}
	TEST_CHECK(vsize(v) == 0);
	vcleanup(&v);
}


void test_rm_bad(void)
{
	vector v;
	vinit(&v);
	TEST_CHECK(vrm(&v, 0) == 0);
	vadd(&v, 5);
	TEST_CHECK(vrm(&v, 10) == 0);

	vcleanup(&v);
}

void test_set(void)
{
	srand(time(NULL));
	int num, got;
	vector v;
	vinit(&v);

	for (int i=0; i<10; i++)
		vadd(&v, i);

	num = rand() % 1000;
	for (int i=0; i<10; i++)
	{
		num = rand() % 1000;
		vset(v, i, num);
		vget(v, i, &got);
		TEST_CHECK(num == got);
	}

	vcleanup(&v);
}

void test_set_bad(void)
{
	vector v;
	vinit(&v);
	TEST_CHECK(!vset(v, 0, 10));
	for (int i=0; i<5; i++)
		TEST_CHECK(!vset(v, rand() % 10 + 1, 10));
	vcleanup(&v);
}

TEST_LIST = {
	{"init", test_init},
	{"add", test_add_good},
	{"rm", test_rm_good},
	{"rm_err", test_rm_bad},
	{"set", test_set},
	{"set_err", test_set_bad},


	{NULL, NULL}
};
