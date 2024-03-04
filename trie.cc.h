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
int TrieC::find (KeyT* key, KeyT end, ValT* val)
{
	TrieC* tree = this;
	TrieC* last = this;
	
	while (*key != end)
	{
		// try to match the character at this level        
		while (*key != tree->key)
		{
			// no more characters to test against
			if (!tree->next)
				return 0;
			
			tree = tree->next;
		}
		
		last = tree;
		
		if (tree->match) tree = tree->match;
		key++;
	}
	
	if (!last->isleaf) return 0;
	
	if (val) *val = last->val;
	return 1;
}

#endif
#endif
