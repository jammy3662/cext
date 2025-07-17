#ifndef TRIE_DOT_H
#define TRIE_DOT_H

#define no !
<<<<<<< HEAD

#pragma pack (push, 1)
=======
>>>>>>> 3d06389 (new containers added; various bugs addressed)

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
	ValT& find (KeyT* key, KeyT stop, int*_err_= 0);
	
	void insert (KeyT* key, ValT val);
<<<<<<< HEAD
	ValT& find (KeyT* key, int*_err_= 0);
=======
	ValT find (KeyT* key, int*_err_= 0);
>>>>>>> 3d06389 (new containers added; various bugs addressed)
};

template TrieT
struct Trie
{
	TrieN <KeyT, ValT> root;
	
	void insert (KeyT* key, KeyT stop, ValT val);
<<<<<<< HEAD
	ValT& find (KeyT* key, KeyT stop, int* ercc = 0x0);
	
	void insert (KeyT* key, ValT val);
	ValT& find (KeyT* key, int* errc = 0x0);
=======
	ValT find (KeyT* key, KeyT stop, int* err = 0x0); // sets err to non-zero on fail
	
	void insert (KeyT* key, ValT val);
	ValT find (KeyT* key, int* errc = 0x0);
>>>>>>> 3d06389 (new containers added; various bugs addressed)
	
	Trie();
};

#include "trie.cc.h"

#endif
