#include "Structs.h"

// Prints all information stored in the data.
void Data::print() {
		cout <<
			"Key: " << id << endl <<
			"User ID: " << user_id << endl <<
			"Target ID: " << target << endl <<
			"Content: " << content << endl <<
			"is_read: " << is_read << endl <<
			"created_at: " << created_at << endl <<
			"updated_at: " << updated_at << endl;
}



// Returns a pointer to the data at a given index.
Data* Bucket::getItem(int index) {
	Data* returnVal = dataPtr[index];
	return returnVal;
}

// Checks if the bucket has any valid elements.
bool Bucket::isEmpty() {
	for (int i = 0; i < item_num; i++) {
		if (dataPtr[i] != NULL) {
			return false;
		}
	}
	return true;
}

//Inserts the given data into the bucket via either - 
// a: direct access with index (if the bucket is not yet full) 
// or b: push_back vector method which will expand the bucket.
void Bucket::insert(Data* newData)
{
	if (item_num < 3) {
		dataPtr[item_num] = newData;
	}
	else {
		dataPtr.push_back(newData);
	}

	item_num++;


}

//not used in this program, but will remove an element from the bucket and
// fill the, now NULL, remaining index with the last element of the bucket.
void Bucket::remove(Data* remData)
{
	for (int i = 0; i<dataPtr.size(); i++)
	{
		if (dataPtr.at(i) == remData)
		{
			dataPtr[i] = NULL;
			item_num--;
			int replace = 0;
			for (i = 0; i >= dataPtr.size(); i++)
			{
				if (dataPtr[i] == NULL)
				{
					dataPtr.at(i) = dataPtr.back();
					dataPtr.pop_back();
				}
			}
		}
	}
}
// Prints only actual data in the bucket.
void Bucket::printValues() {
	for (int i = 0; i<item_num; i++)
	{
		if (dataPtr[i] != NULL) {
			cout << dataPtr[i]->id << endl;
		}
	}
}

// Prints the entire bucket, regardless of valid data or not.
void Bucket::printArray()
{
	for (int i = 0; i<dataPtr.size(); i++)
	{
		if (i != 0) cout << "\t";
		cout << "Location " << i << ": ";
		if (dataPtr[i] != NULL) {
			cout << dataPtr[i]->id;
		}
		cout << endl;

	}
}

// returns the number of valid items in the bucket.
int Bucket::getItemCount() {
	return item_num;
}