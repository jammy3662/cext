#ifndef TRIE_DOT_H_HEADER_ONLY
#ifndef TRIE_DOT_H_IMPL
#define TRIE_DOT_H_IMPL

#include <stdlib.h>
#include <string.h>

#include "trie.h"

#define TrieC TrieN <KeyT, ValT>
#define TrieT <typename KeyT, typename ValT>

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
			if (no tree->next)
			{
				tree->next = (TrieN*) malloc (sizeof (TrieC));
				tree->next->key = *key;
			}
			tree = tree->next;
		}
		
		last = tree;
		
		if (no tree->match)
		{
			tree->match = (TrieN*) malloc (sizeof (TrieC));
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
	if (err) *err = 0; // default to success
	
	TrieC* tree = this;
	TrieC* last = this;
	
	while (*key != end)
	{
		// try to match the character at this level        
		while (*key != tree->key)
		{
			// no more characters to test against
			if (no tree->next)
			{
				if (err) *err = 2;
				return (ValT) {0};
			}			
			tree = tree->next;
		}
		
		last = tree;
		
		if (tree->match) tree = tree->match;
		key++;
	}
	
	if (not last->isleaf)
	{
		if (err) *err = 1;
		return (ValT) {0};
	}
	
	return last->val;
}

template TrieT
void Trie<KeyT,ValT>::insert (KeyT* key, KeyT stop, ValT val)
{
	root.insert (key, stop, val);
}

template TrieT
ValT Trie<KeyT,ValT>::find (KeyT* key, KeyT stop, int* err)
{
	ValT res = root.find (key, stop, err);
	return res;
}

template TrieT
void Trie<KeyT,ValT>::insert (KeyT* key, ValT val)
{
	KeyT zero = {0};
	root.insert (key, zero, val);
}

template TrieT
ValT Trie<KeyT,ValT>::find (KeyT* key, int* err)
{
	KeyT zero = {0};
	ValT res = root.find (key, zero, err);
	return res;
}

template TrieT
Trie<KeyT,ValT>::Trie()
{
	TrieC empty = {0};
	root = empty;
}

#endif
#endif
