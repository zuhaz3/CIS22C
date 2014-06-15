// Specification file for the BST class
#ifndef LIST_H
#define LIST_H
#include<string>
#include<stdlib.h>
#include "BST.h"
#include "Hash.h"
#include "Structs.h"
class List
{
private:
	int count;
	BST* pTree;
	Hash* pHash;

public:
    // Constructor
    List();
	List(int data_count);
    // Destructor
    ~List(); 

	void insert(Data*);
	void remove(int id);
	void displayOne(int id);
	void displayHash();
	void displaySorted();
	void displayTree();
	bool ouputToFile();
	void displayHashStat();

};
#endif
