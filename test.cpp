#include "ObjectPool.h"
#include <vector>
#include <iostream>

using namespace std;


int main()
{
	ObjectPool<vector<int>> pool;

	auto* v = pool.allocate(5);
	(*v)[0] = 4;
	pool.free(v);
	v = nullptr;


	auto v_ptr = pool.allocate_unique(1);
	(*v_ptr)[0] = 4;
	v_ptr = nullptr;

	auto v_shared_ptr = pool.allocate_shared(1);
	auto v_shared_ptr2 = v_shared_ptr;
	(*v_shared_ptr)[0] = 4;
	v_shared_ptr = nullptr;
	v_shared_ptr2 = nullptr;

	cout << "Success" << endl;


	return 0;
}
