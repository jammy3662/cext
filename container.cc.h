#ifndef CONTAINER_DOT_H_HEADER_ONLY
#ifndef CONTAINER_DOT_H_IMPL
#define CONTAINER_DOT_H_IMPL

#include "container.h"

#include <stdlib.h>
#include <string.h>

/*

heres a block comment with many lines
*/

static int roundNearest (float f)
{
	return (int) (f + 0.5);
}

template <typename T>
void arr<T>::allocate (int n)
{
	clear ();
	count = 0;
	available = n;
	ptr = (T*) realloc (ptr, n * sizeof(T));
	memset (ptr, 0, n *	sizeof (T));
}

template <typename T>
int arr<T>::expand ()
{
	if (not available) allocate (1);
	
	int prev = available;
	// add 50% size of the current used elements
	available = roundNearest ((float)available * 1.5);
	
	if (no ptr) allocate (1);
	
	T* oldptr = ptr;
	ptr = (T*) realloc (ptr, available * sizeof(T));
	memset (oldptr, 0, (oldptr - ptr) * sizeof(T));
	
	return available - prev;
}

template <typename T>
int arr<T>::append (T next)
{
	int added;
	
	if (count >= available)
		added = expand ();
	
	ptr [count] = next;
	
	count++;
	return added;
}

template <typename T>
int arr<T>::shrink ()
{
	int unused = available - count;
	ptr = (T*) realloc (ptr, count * sizeof(T));
	available = count;
	return unused;
}

template <typename T>
void arr<T>::clear ()
{
	if (no ptr) return;
	
	free (ptr);
	arr<T> newarr;
	
	*this = newarr;
}

#endif
#endif
