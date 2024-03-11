#ifndef TRIE_DOT_H_HEADER_ONLY
#ifndef TRIE_DOT_H_IMPL
#define TRIE_DOT_H_IMPL

#include "trie.h"

#include <stdlib.h>
#include <string.h>

#define TrieC Trie <KeyT, ValT>
#define TrieT <typename KeyT, typename ValT>

template TrieT
TrieC::Trie ()
{
	next = 0;
	match = 0;
	isleaf = 0;
}

template TrieT
void TrieC::insert (KeyT* key, KeyT end, ValT val)
{
	TrieC* tree = this;
	TrieC* last = this;
	
	while (*key != end)
	{
		if (tree->key == end)
			tree->key = *key;
		
		while (*key != tree->key)
		{
			if (!tree->next)
			{
				tree->next = (Trie*) malloc (sizeof (TrieC));
				tree->next->key = *key;
			}
			tree = tree->next;
		}
		
		last = tree;
		
		if (!tree->match)
		{
			tree->match = (Trie*) malloc (sizeof (TrieC));
			tree->match->key = end;
		}
		tree = tree->match;
		
		key++;
	}
	
	last->val = val;
	last->isleaf = 1;
}

template TrieT
ValT TrieC::find (KeyT* key, KeyT end, int* err)
{
	ValT val; // careful, may return garbage data (check err)
	if (err) *err = 0; // default to success
	
	TrieC* tree = this;
	TrieC* last = this;
	
	while (*key != end)
	{
		// try to match the character at this level        
		while (*key != tree->key)
		{
			// no more characters to test against
			if (!tree->next)
			{
				if (err) *err = 2;
				return val;
			}			
			tree = tree->next;
		}
		
		last = tree;
		
		if (tree->match) tree = tree->match;
		key++;
	}
	
	if (!last->isleaf)
	{
		if (err) *err = 1;
	}
	else  val = last->val;
	
	return val;
}

template TrieT
inline
void TrieC::insert (KeyT* key, ValT val)
{
	KeyT zero = {0};
	insert (key, zero, val);
}

template TrieT
inline
ValT TrieC::find (KeyT* key, int* err)
{
	KeyT zero = {0};
	return find (key, zero, err);
}

#endif
#endif
