// Specification file for the BST class
#ifndef BST_H
#define BST_H
#include "Structs.h";
using namespace std;

class BST
{
private:
    struct BST_Node
    {
        Data data;         // The value in this node
        BST_Node *left;    // To point to the left node
        BST_Node *right;   // To point to the right node
    } ;

    BST_Node *root;       // root of the tree
    int count;            // number of nodes in the tree

public:
    // Constructor
    BST();

    // Destructor
    ~BST();

    // Binary Tree operations
    void BST_insert(Data* dataIn);
    bool Search(int target, Data &data);
    bool Delete(int target);
    void BST_InorderTraverse() const;
	void BST_PreorderTraverse() const;
	void BST_PostorderTraverse() const;
	void BST_PrintTree() const;
	void BST_BreadthFirst() const;
	void BST_PrintRange(int n1, int n2) const;
	Data BST_FindMinimum() const;
	Data BST_FindMaximum() const;
	bool BST_CSV_Out(ofstream &outfile) const;

private:
    BST_Node *_search(int target);
    BST_Node *_delete(BST_Node *root, int target);
    void _BST_InorderTraverse( BST_Node *root ) const;
	void _BST_PreorderTraverse(BST_Node *root) const;
	void _BST_PostorderTraverse(BST_Node *root) const;
	void _BST_PrintTree(BST_Node *p, int indent, int count) const;
	void _BST_BreadthFirst(BST_Node *p) const;
	void _BST_PrintRange(BST_Node *root, int num1, int num2) const;
	Data _BST_FindMinimum(BST_Node *root) const;
	Data _BST_FindMaximum(BST_Node *root) const;
    void _BST_Destroy(BST_Node *root);
	bool _BST_CSV_Out(BST_Node *p, ofstream &outfile) const;
};
#endif
