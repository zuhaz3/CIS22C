#include"BST.h"
#include"Hash.h"
#include"List.h"
#include<sstream>

//void outputToFile(List* list);
Data* getValidData();
List* createListFromDataFile(fstream &inp);
int countElementsinFile(fstream &inp);
Hash* initHash(fstream &inp);
void showMenu();
int NearestPrime(double original);
bool IsPrime(int p);
int getValidInt();
string getValidString(int);
int main() {

	List* list;
	fstream inp;
	list = createListFromDataFile(inp);
	showMenu();
	char choice = ' ';
	

	while (choice != 'Q')
	{
		cout << "\noption choice: ";
		choice = toupper(getchar());
		switch (choice)
		{
		case 'A':
			//get user input
			list->insert(getValidData());
			break;
		case 'S':
			cout << "Enter target key: ";
			list->displayOne(getValidInt());
			break;
		case 'H':
			//display list
			//list->displayHashTable();
			break;
		case 'I':
			list->displaySorted();
			break;
		case 'T':
			list->displayHashStat();
			break;
		case 'P':
			list->displayTree();
			break;
		case 'R':
			//get user input
			cout << "Enter target key: ";
			if (list->remove(getValidInt()))
				cout << " *Delete successful*";
			else
				cout << " *Delete not successful*";
			break;
		case 'M':
			showMenu();
			break;
		case 'W':
			if(list->outCSV());
			break;
		case 'Q':
			break;
		default:
			cout << "*Invalid choice!*\n";
		}
	}

	return 0;
}
/*
void outputToFile(List* list) {
	ofstream out;
	out.open("save.txt");
	list->outCSV();
}
*/

Data* getValidData() {
	Data* newData = new Data();

	cout << " id: ";
	newData->id = getValidInt();
	cout << " user_id: ";
	newData->user_id = getValidString(24);
	cout << " target: ";
	newData->target = getValidString(24);
	cout << " content";
	cin >> newData->content;
	cout << " type: ";
	cin >> newData->type;

	cout << " is_read";
	string temp;
	cin >> temp;
	if (temp == "true" || temp == "1")
		newData->is_read = true;
	else
		newData->is_read = false;

	cout << " created_at";
	newData->created_at = getValidString(24);;
	cout << " updated_at";
	newData->updated_at = getValidString(24);;
	return newData;
}

List* createListFromDataFile(fstream &inp) {

	inp.open("save.txt");
	if (!inp.is_open()) {
		cout << "Couldn't find saved datafile - using default." << endl;
		inp.open("input.txt");
		if (!inp.is_open()) {
			cerr << "Error opening file!" << endl;
		}
	}
	else cout << "Reloading your list from last time..." << endl;

	List* newList = new List(countElementsinFile(inp));
	string line;
	while (getline(inp, line))
	{
		stringstream linestream(line);
		string value;

		Data* d;
		int count = 0;
		d = new Data();
		while (getline(linestream, value, ','))
		{
			if (count == 0)  {
				istringstream buffer(value);
				int val;
				buffer >> val;
				d->id = val;
			}
			else if (count == 1) d->user_id = value;
			else if (count == 2) d->target = value;
			else if (count == 3) d->content = value;
			else if (count == 4) d->type = value;
			else if (count == 5)  {
				istringstream is(value);
				bool b;
				is >> boolalpha >> b;
				d->is_read = b;
			}
			else if (count == 6) d->created_at = value;
			else if (count == 7) d->updated_at = value;
			count++;
		}
		newList->insert(d);
	}
	return newList;
}

// Displays menu to the user
void showMenu()
{
	cout << "\nSelect an option:\n\t"
		<< "A - Add a new notification.\n\t"
		<< "S - Search by a unique key.\n\t"
		<< "I - Display list sorted by ID.\n\t"
		<< "H - Display hash table.\n\t"
		<< "T - Display hash statistics.\n\t"
		<< "P - Print indented tree.\n\t"
		<< "R - Remove an element in the list by ID.\n\t"
		<< "M - Show menu.\n\t"
		<< "W - Save to file\n\t"
		<< "Q - Quit.\n";
}


//These functions are necessary for dynamic hash sizing
int countElementsinFile(fstream &inp) {
	string line;
	int line_count = 0;
	while (getline(inp, line)) {
		line_count++;
	}
	inp.close();
	inp.open("input.txt");
	return line_count;
}

int getValidInt()
 {
	int num;
	while (!(cin >> num))
	{
		cin.clear();
		cin.ignore();
		cout << "  *Invalid input!* \n Input again: ";
	}
	return num;
}

string getValidString(int length)
{
	string input;
	cin >> input;
	while (input.size() != length)
	{
		cin.clear();
		cin.ignore();
		cout << " Invalid input. Input have to be " << length << " characters long.\n Try again: ";
	}
	return input;
}