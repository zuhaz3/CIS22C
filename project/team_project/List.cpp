#include "Hash.h"
#include "List.h"
#include <cmath>


List::List(int data_count) {
	pTree = new BST();
	pHash = new Hash(data_count);
}
// Need to implement remove function for BST and hash
void List::remove(int id) {
	// call remove for BST
	// pHash->remove(id);
}
void List::insert(Data* data) {
	pTree->BST_insert(data);
	pHash->insert(data);
}
void List::displaySorted() {
	pTree->BST_InorderTraverse();
}

void List::displayHashStat() {
	pHash->displayHashStat();
}

void List::displayOne(int id) {
	pHash->search(id);
}