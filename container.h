#ifndef CONTAINER_DOT_H
#define CONTAINER_DOT_H

#include "ints.h"

#define no !

#pragma pack (push, 1)

template <typename T>
struct array
{
	fast count, available;
	
	T* ptr;
	
	fast append (T next); // returns # of new elements allocated
	void allocate (fast num);
	fast expand (); // allocate 50% more space (returns # new elements)
	fast shrink (); // deallocate all unused elements (returns # unused elements)
	void clear (); // deallocate all memory
	
	T& operator [] (fast idx) {return ptr[idx];};
	operator T* () {return ptr;}
};

#include "container.cc.h"

#pragma pack (pop)

#endif
