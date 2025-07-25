#ifndef TRIE_DOT_H
#define TRIE_DOT_H

#define no !

#define TrieT <typename KeyT, typename ValT>

template TrieT
struct TrieN
{
	KeyT key;
	ValT val;
	char isleaf;
	
	TrieN* next;
	TrieN* match;
	
	// TODO: write a trie "compress" function that
	// groups sequential characters into a single node
	
	void insert (KeyT* key, KeyT stop, ValT val);
	ValT find (KeyT* key, KeyT stop, int*_err_= 0);
	
	void insert (KeyT* key, ValT val);
	ValT find (KeyT* key, int*_err_= 0);
};

template TrieT
struct Trie
{
	TrieN <KeyT, ValT> root;
	
	void insert (KeyT* key, KeyT stop, ValT val);
	ValT find (KeyT* key, KeyT stop, int* err = 0x0); // sets err to non-zero on fail
	
	void insert (KeyT* key, ValT val);
	ValT find (KeyT* key, int* err = 0x0);
	
	Trie();
};

#include "trie.cc.h"

#endif
