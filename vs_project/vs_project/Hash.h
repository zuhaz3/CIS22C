//Brian Sonnenberg

#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <fstream>
#include <vector>
#include "Structs.h"
using namespace std;

class Hash
{
	private:
		int count;
		int arySize;
		int bucketSize = 3;
		vector<Bucket*> ary;

		
	public:
		Hash(int data_count);
		//Hash(Data* newData, int data_count);
		
		bool remove(int id);
		void search(int id);
		void displayValues();
		void displayHashTable();
		void insert(Data*);
		void displayHashStat();
		int getNumFullBuckets();
		int getNumCollisions();


};


#endif