//Brian Sonnenberg
#ifndef STRUCTS_H
#define STRUCTS_H
#include <iostream>
#include<string>
#include<vector>
using namespace std;

struct Data
{
	int id;
	string user_id;
	string target;
	string content;
	string type;
	bool is_read;
	string created_at;
	string updated_at;
	void print();
};

struct Bucket
{
private:
	int item_num = 0;
	vector<Data *> dataPtr;

public:
	Bucket() {
		dataPtr.resize(3);
		item_num = 0;
	}
	int getItemCount();
	Data* getItem(int index);
	void printArray();
	void printValues();
	void insert(Data*);
	void remove(Data*);
	bool isEmpty();
};

#endif