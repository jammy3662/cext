#ifndef TRIE_DOT_H
#define TRIE_DOT_H

#pragma pack (push, 1)

#define TrieT <typename KeyT, typename ValT>

template TrieT
struct Trie
{
	KeyT key;
	ValT val;
	char isleaf;
	
	Trie* next;
	Trie* match;
	
	// TODO: write a trie "compress" function that
	// groups sequential characters into a single node
	
	void insert (KeyT* key, KeyT stop, ValT val);
	ValT find (KeyT* key, KeyT stop, int*_err_= 0);
	
	void insert (KeyT* key, ValT val);
	ValT find (KeyT* key, int*_err_= 0);
	
	Trie();
};

#include "trie.cc.h"

#pragma pack (pop)

#endif
