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
	buf = (T*) realloc (buf, n * sizeof(T));
}

template <typename T>
int arr<T>::expand ()
{
	if (!available) allocate (1);
	
	int prev = available;
	// add 50% size of the current used elements
	available = roundNearest ((float)available * 1.5);
	
	buf = (T*) realloc (buf, available * sizeof(T));
	
	return available - prev;
}

template <typename T>
int arr<T>::append (T next)
{
	int added;
	
	if (count >= available)
		added = expand ();
	
	buf [count] = next;
	
	count++;
	return added;
}

template <typename T>
int arr<T>::shrink ()
{
	int unused = available - count;
	buf = (T*) realloc (buf, count * sizeof(T));
	available = count;
	return unused;
}

template <typename T>
void arr<T>::clear ()
{
	if (!buf) return;
	
	free (buf);
	arr<T> newarr;
	
	*this = newarr;
}

#endif
#endif
