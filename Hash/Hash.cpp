// Brian Sonnenberg
#include "Hash.h"
#include <fstream>
#include <sstream>


Hash::Hash(int data_count) {
	count = 0;
	ary.resize(data_count);
	arySize = data_count;
}
// Allocates the hash memory, then reads through the input file,
// builds a new data piece and inserts that data piece
// into the hash line by line.
Hash::Hash(fstream &inp, int data_count) {
	ary.resize(data_count);
	arySize = data_count;
	string line;
	while (getline(inp, line))
	{
		stringstream linestream(line);
		string value;

		Data* d;
		int data_piece = 0;

		d = new Data();
		while (getline(linestream, value, ','))
		{
			if (data_piece == 0)
			{
				istringstream buffer(value);
				int val;
				buffer >> val;
				d->id = val;
			}
			else if (data_piece == 1)
			{
				d->user_id = value;
			}
			else if (data_piece == 2)
			{
				d->target = value;
			}
			else if (data_piece == 3)
			{
				d->content = value;
			}
			else if (data_piece == 4)
			{
				d->type = value;
			}
			else if (data_piece == 5)
			{
				istringstream is(value);
				bool b;
				is >> boolalpha >> b;
				d->is_read = b;
			}
			else if (data_piece == 6)
			{
				d->created_at = value;
			}
			else if (data_piece == 7) {
				d->updated_at = value;
			}
			data_piece++;
		}
		insert(d);


	}
}

bool Hash::remove(int id) {
	bool found = false;
	int index = id%arySize;
	if (index < ary.size() - 1) {
		if (ary[index] != NULL) {
			if (ary[index]->remove(id)) {
				found = true;
				cout << "ID removed!" << endl << endl;
			}
		}
	}
	if(!found) cout << "ID not found!" << endl << endl;
	
	return found;
}

// Runs the given id through hashing function to find the corresponding index, and iterates through the bucket
// - tells the user if the ID is found.
void Hash::search(int id) {
	bool found = false;
	int index = id%arySize;
	if (ary[index] != NULL) {
		for (int i = 0; i < ary[index]->getItemCount(); i++) {
			if (ary[index]->getItem(i)->id == id) {
				found = true;
				cout << "ID found:" << endl << endl;
				ary[index]->getItem(i)->print();
			}
		}
	   if(!found) cout << "ID not found!" << endl << endl;
	}

	else cout << "ID not found!" << endl << endl;
}

// Iterates through the hash, tallying the number of collisions (the number of elements in each bucket after the first)
// and returns the value
int Hash::getNumCollisions() {
	int returnVal = 0;
	for (int i = 0; i < arySize; i++)
	{
		if (ary[i] != NULL) {
			returnVal += ary[i]->getItemCount() - 1;
		}

	}
	return returnVal;
}

// Iterates through the hash tallying the number of buckets which contain 
// greater than 3 elements - at which point they are considered "full"
int Hash::getNumFullBuckets() {
	int returnVal = 0;
	for (int i = 0; i < arySize; i++)
	{
		if (ary[i] != NULL) {
			if (ary[i]->getItemCount() >= 3) {
				returnVal++;
			}
		}

	}
	return returnVal;
}

// Displays the load factor, the number of collisions, and number of
// full buckets to the user
void Hash::displayHashStat() {
	cout << "Load factor: " << count << "/" << arySize << endl;
	cout << "Number of collisions: " << getNumCollisions() << endl;
	cout << "Number of full buckets: " << getNumFullBuckets() << endl;
}

// Runs the given data's id through the hash formula and, if 
// the resulting index's bucket is not yet allocated in the
// hash, it allocates the memory for it, then inserts the 
// value into the bucket.
void Hash::insert(Data* inData) {
	int index = inData->id % arySize;
	if (ary[index] == NULL) {
		ary[index] = new Bucket();
	}
	ary.at(index)->insert(inData);
	count++;
}

// Iterates through the hash and prints each ID,
// making sure to skip over any empty values or buckets.
void Hash::displayValues() {
	for (int i = 0; i < arySize; i++)
	{
		if (ary[i] != NULL) {
			if (!(ary[i]->isEmpty())) {
				ary[i]->printValues();
			}
			else
				cout << "EMPTY";
		}

	}
}
// Iterates over the hash and prints each bucket. 
// If the bucket is empty it simply prints EMPTY.
// If the bucket has any elements, it display each
// element of the bucket, including empty elements.
void Hash::displayHashTable()
{
	for (int i = 0; i<arySize; i++)
	{
		cout << "Bucket " << i << ": ";
		if (!(ary[i] == NULL)) {
			if (!(ary[i]->isEmpty())) {
				ary[i]->printArray();
			}
			else
				cout << "EMPTY";
		}
		else {
			cout << "EMPTY" << endl;
		}
		cout << endl;
	}
}
