#include "List.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int getCount();
int getValidInt();
void insert(List *);
void displayMenu();
void set(List* dataList);
int main()
{
	List dataList(getCount());
	set(&dataList);

	int choice = 10;
	displayMenu();
	while (choice != 0)
	{
		cout << "\nInput: ";
		choice = getValidInt();
		switch (choice)
		{
		case 1:
			insert(&dataList);
			break;
		case 2:
			cout << "Search key: ";
			dataList.remove(getValidInt());
			break;
		case 3:
			cout << "Search key: ";
			dataList.displayOne(getValidInt());
			break;
		case 4:
			dataList.displayHash();
			break;
		case 5:
			dataList.displaySorted();
			break;
		case 6:
			dataList.displayTree();
			break;
		case 7:
			//dataList.ouputToFile();
			break;
		case 8:
			//dataList.displayHashStat();
			break;
		case 9:
			displayMenu();
			break;
		case 0:
			break;
		default:
			cout << "Invalid input!\n";
			break;
		}
	}

	return 0;
}
int getCount()
{
	int count = 0;
	ifstream inp;
	inp.open("input.txt");

	string line;


	while (getline(inp, line))
	{
		std::stringstream linestream(line);
		std::string value;

		Data* d = new Data; 
		int num = 0;

		while (getline(linestream, value, ','))
			num++;
		count++;
	}
	inp.close();
	return count;
}

int getValidInt()
{
	int num;
	while (!(cin >> num))
	{
		cin.clear();
		cin.ignore();
		cout << "\nInvalid choice! \nInput: ";
	}
	return num;
}

void displayMenu()
{
	cout << "\n (1) Add new data"
		<< "\n (2) Delete data"
		<< "\n (3) Find and display one element with a unique key"
		<< "\n (4) List data in hash table sequence"
		<< "\n (5) List data in key sequence(sorted)"
		<< "\n (6) Print indented tree"
		<< "\n (7) Write data to a file."
		<< "\n (8) Hash statistics."
		<< "\n (9) Display this menu again."
		<< "\n (0) Quit program.";
}

void set(List* dataList)
{
	ifstream inp;
	inp.open("input.txt");

	string line;

	//reads data from txt file 
	while (getline(inp, line))
	{
		std::stringstream linestream(line);
		std::string value;

		Data* d = new Data; //initialize new Data object
		int count = 0;

		// sets the data to their corresponding fields
		while (getline(linestream, value, ','))
		{
			if (count == 0)
			{
				istringstream buffer(value);
				int val;
				buffer >> val;
				d->id = val;
			}
			if (count == 1)
			{
				d->user_id = value.substr(1);
			}
			if (count == 2)
			{
				d->target = value.substr(1);
			}
			if (count == 3)
			{
				d->content = value.substr(1);
			}
			if (count == 4)
			{
				d->type = value.substr(1);
			}
			if (count == 5)
			{
				std::istringstream is(value);
				bool b;
				is >> std::boolalpha >> b;
				d->is_read = b;
			}
			if (count == 6)
			{
				d->created_at = value.substr(1);
			}
			if (count == 7)
			{
				d->updated_at = value.substr(1);
			}
			count++;
		}
		dataList->insert(d); //insert data object into hash table
	}
	inp.close();
}

void insert(List * dataList)
{
	Data * newData = new Data;
	
	cout << "user_id: ";
	newData->user_id = getValidInt();
	cout << "target: ";
	cin >> newData->target;
	cout << "content";
	cin >> newData->content;
	cout << "type: ";
	cin >> newData->type;
	
	cout << "is_read";
	string temp;
	cin >> temp;
	if (temp == "true" || temp == "1")
		newData->is_read = true;
	else
		newData->is_read = false;

	cout << "created_at";
	cin >> newData->created_at;
	cout << "updated_at";
	cin >> newData->updated_at;

	dataList->insert(newData);
}