#ifndef CONTAINER_DOT_H
#define CONTAINER_DOT_H

#pragma pack (push, 1)

#include <stdint.h>

template <typename T>
struct arr
{
	int count, available;
	
	T* ptr;
	
	int append (T next); // returns # of new elements allocated
	void allocate (int num);
	int expand (); // allocate 50% more space (returns # new elements)
	int shrink (); // deallocate all unused elements (returns # unused elements)
	void clear (); // deallocate all memory
	
	T& operator [] (int idx) {return ptr[idx];};
	operator T* () {return ptr;}
	arr () {count = 0; available = 0; ptr = 0;};
};

#include "container.cc.h"

#pragma pack (pop)

#endif
