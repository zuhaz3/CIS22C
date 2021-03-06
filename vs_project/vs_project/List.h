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
	List(int data_count);
    // Destructor
    ~List(); 

	void insert(Data*);
	bool remove(int id);
	void displayOne(int id);
	void displayHashTable();
	void displaySorted();
	void displayTree();
	//bool ouputToFile();
	void displayHashStat();
	bool outCSV();

};
#endif
