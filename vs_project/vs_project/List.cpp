#include "Hash.h"
#include "List.h"
#include <cmath>
#include <fstream>

List::List(int data_count) {
	pTree = new BST();
	pHash = new Hash(data_count);
}
// Need to implement remove function for BST and hash
bool List::remove(int id) {
	if (pHash->remove(id) && pTree->Delete(id)) return true;
}
void List::insert(Data* data) {
	pTree->BST_insert(data);
	pHash->insert(data);
}
void List::displaySorted() {
	pTree->BST_InorderTraverse();
}

void List::displayTree()
{
	pTree->BST_PrintTree();
}

void List::displayOne(int id) {
	pHash->search(id);
}

void List::displayHashStat(){
	pHash->displayHashStat();
};

bool List::outCSV()
{
	bool success = false;

	ofstream outputFile;
	outputFile.open("output.txt");
	if (pTree->BST_CSV_Out(outputFile)) success = true;
	outputFile.close();
	return success;
}
List::~List()
{
	delete pTree;
	delete pHash;
}