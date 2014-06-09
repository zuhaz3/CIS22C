/**
 Project: Binary Search Tree

 This application manipulates a BST and uses the BST implementation file to call functions
 defined in the BST header file. This application traverses through the BST in all three forms
 and also uses a queue to traverse through using breadth first traversal. In addition, we can
 print this tree out and also print out a range of values based on a user input.

 NAME: Zuhayeer Musa
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <sstream>
#include "BST.h"

using namespace std;

void recursiveTraversals(BST &tree);
void searchByUniqueKey(BST &tree, int target);
void promptUserForRangeAndPrint(BST &tree);
void populateTree(BST &tree, ifstream &inp);
void showMenu();

int main( void )
{
   BST tree;
   int n = 10; // number of nodes
   int searchCount = n;

   srand(time(NULL));
   ifstream inp;
   string line;
   inp.open("input.txt");

   if (!inp.is_open())
	   cout << "\nError opening file!";

   populateTree(tree, inp);

   showMenu();

   char choice;

   choice = toupper(getchar());

   while (choice != 'Q')
   {
	   switch (choice)
	   {
		   case 'S':
			   cout << 401 << " ";
			   searchByUniqueKey(tree, 401);
			   cout << 70 << " ";
			   searchByUniqueKey(tree, 70);
			   cout << 100 << " ";
			   searchByUniqueKey(tree, 100);
			   cout << 221 << " ";
			   searchByUniqueKey(tree, 221);
			   cout << 80 << " ";
			   searchByUniqueKey(tree, 80);
			   break;
		   case 'B':
			   tree.BST_BreadthFirst();
			   break;
		   case 'T':
			   tree.BST_PrintTree();
			   break;
		   case 'D':
			   recursiveTraversals(tree);
			   break;
		   case 'R':
			   promptUserForRangeAndPrint(tree);
			   break;
		   case 'M':
			   showMenu();
			   break;
	   }
	   choice = toupper(getchar());
   }

   return 0;
}

void searchByUniqueKey(BST &tree, int target)
{
	Data data;
	if (tree.Search(target, data))
	{
		cout << " FOUND! Data contains: " << data.num << ", " << data.user_id << ", " << data.target << ", " << data.content  << ", " << data.type << ", " << data.is_read << endl;
	}
	else
		cout << " NOT FOUND!\n";
}

void populateTree(BST &tree, ifstream &inp)
{
	string line;
	while (getline(inp, line))
	{
		std::stringstream   linestream(line);
		std::string         value;

		Data d;
		int count = 0;

		while (getline(linestream, value, ','))
		{
			if (count == 0)
			{
				istringstream buffer(value);
				int val;
				buffer >> val;
				d.num = val;
			}
			if (count == 1)
			{
				d.user_id = value;
			}
			if (count == 2)
			{
				d.target = value;
			}
			if (count == 3)
			{
				d.content = value;
			}
			if (count == 4)
			{
				d.type = value;
			}
			if (count == 5)
			{
				std::istringstream is(value);
				bool b;
				is >> std::boolalpha >> b;
				d.is_read = b;
			}
			count++;
		}
		tree.BST_insert(d);
	}
}

void showMenu()
{
	cout << "\nWhat do you want to do?\n\t"
		<< "S - Search by a unique key\n\t"
		<< "D - Recursive Depth-First Traversals: inorder, preorder, postorder\n\t"
		<< "B - Tree Breadth-First Traversal\n\t"
		<< "T - Print tree as an indented list\n\t"
		<< "R - Print the numbers within a given range\n\t"
		<< "M - Show menu\n\t"
		<< "Q - Quit\n";
}

void promptUserForRangeAndPrint(BST &tree)
{
	int num1;
	int num2;

	//string line;
	//string::const_iterator it = line.begin();
	cout << "Please enter a number for the first range value (Min: " << tree.BST_FindMinimum().num << " , Max: " << tree.BST_FindMaximum().num << " ) : ";
	while (1) {
		if (cin >> num1) 
		{
			break;
		}
		else 
		{
			cout << "Invalid Input! Please input a numerical value (Min: " << tree.BST_FindMinimum().num << " , Max: " << tree.BST_FindMaximum().num << " ) : ";
			cin.clear();
			while (cin.get() != '\n'); // empty loop
		}
	}
	cout << "Please enter a number for the second range value (Min: " << tree.BST_FindMinimum().num << " , Max: " << tree.BST_FindMaximum().num << " ) : ";
	while (1) {
		if (cin >> num2)
		{
			break;
		}
		else
		{
			cout << "Invalid Input! Please input a numerical value (Min: " << tree.BST_FindMinimum().num << " , Max: " << tree.BST_FindMaximum().num << " ) : ";
			cin.clear();
			while (cin.get() != '\n'); // empty loop
		}
	}

	if (num1 > num2) cout << "The first range value is less than the second. No numbers can be in between!";
	else
		tree.BST_PrintRange(num1, num2);
	cout << endl << endl;
}

void recursiveTraversals(BST &tree)
{
	cout << "In Order: ";
	tree.BST_InorderTraverse();
	cout << endl;
	cout << "Pre Order: ";
	tree.BST_PreorderTraverse();
	cout << endl;
	cout << "Post Order: ";
	tree.BST_PostorderTraverse();
	cout << endl;
}