// Implementation file for the BST class
#include <iostream>  // For cout and NULL
#include <string>
#include <iomanip>

#include "Queue.h"
#include "BST.h"

using namespace std;

/**~*~*
   Constructor
*~**/
BST::BST()
{
    root = NULL;
    count = 0;
}

/**~*~*
   This function calls a recursive function to traverse the
   tree in inorder
*~**/
void BST::BST_InorderTraverse() const
{
    _BST_InorderTraverse(root);
}

/**~*~*
	This function calls a recursive function to traverse the
	tree in preorder
*~**/
void BST::BST_PreorderTraverse() const
{
	_BST_PreorderTraverse(root);
}

/**~*~*
	This function calls a recursive function to traverse the
	tree in postorder
*~**/
void BST::BST_PostorderTraverse() const
{
	_BST_PostorderTraverse(root);
}

/**~*~*
	This function calls the recursively defined function for printing a tree
*~**/
void BST::BST_PrintTree() const
{
	_BST_PrintTree(root, 0, 1);
}

/**~*~*
	This function calls the breadth first traversal function
*~**/
void BST::BST_BreadthFirst() const
{
	_BST_BreadthFirst(root);
}

Data BST::BST_FindMinimum() const
{
	return _BST_FindMinimum(root);
}

Data BST::BST_FindMaximum() const
{
	return _BST_FindMaximum(root);
}

/**~*~*
	This function finds and returns the minimum value in the BST
*~**/
Data BST::_BST_FindMinimum(BST_Node *root) const
{
	if (root == NULL)
		return root->data;
	if (root->left)
		return _BST_FindMinimum(root->left);
	else
		return root->data;
}

/**~*~*
	This function finds and returns the maximum value in the BST
*~**/
Data BST::_BST_FindMaximum(BST_Node *root) const
{
	if (root == NULL)
		return root->data;
	if (root->right)
		return _BST_FindMinimum(root->right);
	else
		return root->data;
}

/**~*~*
	This function calls the print range function with the two numbers
	that define the range
*~**/
void BST::BST_PrintRange(int n1, int n2) const
{
	_BST_PrintRange(root, n1, n2);
}

/**~*~*
   Inorder Traversal of the Binary Tree:
   Left-Root-Right
*~**/
void BST::_BST_InorderTraverse(BST_Node *root) const
{
    if (root)
    {
        _BST_InorderTraverse(root->left);
        cout << root->data.num << " ";
        _BST_InorderTraverse(root->right);
    }
}

/**~*~*
	Preorder Traversal of the Binary Tree:
	Root-Left-Right
*~**/
void BST::_BST_PreorderTraverse(BST_Node *root) const
{
	if (root)
	{
		cout << root->data.num << " ";
		_BST_PreorderTraverse(root->left);
		_BST_PreorderTraverse(root->right);
	}
}

/**~*~*
	Postorder Traversal of the Binary Tree:
	Left-Right-Root
*~**/
void BST::_BST_PostorderTraverse(BST_Node *root) const
{
	if (root)
	{
		_BST_PostorderTraverse(root->left);
		_BST_PostorderTraverse(root->right);
		cout << root->data.num << " ";
	}
}

/**~*~*
	Print tree recursively in order
*~**/
void BST::_BST_PrintTree(BST_Node *p, int indent, int count) const
{
	if (p != NULL) 
	{
		string s = to_string(p->data.num);
		if (p->right && count == 1) _BST_PrintTree(p->right, indent + 7 + s.length(), count + 1);
		else if (p->right) _BST_PrintTree(p->right, indent + 4 + s.length(), count+1);
		if (indent) 
		{
			cout << setw(indent - s.length()) << ' ';
		}
		cout << count << ". ";
		cout << p->data.num << "\n ";
		if (p->left && count == 1) _BST_PrintTree(p->left, indent + 7 + s.length(), count + 1);
		else if (p->left) _BST_PrintTree(p->left, indent + 4 + s.length(), count+1);
	}
}

/**~*~*
	Traverse through the BST using breadth first traversal
	with a queue
*~**/
void BST::_BST_BreadthFirst(BST_Node *p) const
{
	Queue<BST_Node *> *queue = new Queue<BST_Node *>;
	if (p == NULL)
		return;
	queue->enqueue(root);
	cout << p->data.num << " ";
	while (!queue->isEmpty())
	{
		BST_Node *temp;
		queue->dequeue(temp);
		if (temp->left)
		{
			queue->enqueue(temp->left);
			cout << temp->left->data.num << " ";
		}
		if (temp->right)
		{
			queue->enqueue(temp->right);
			cout << temp->right->data.num << " ";
		}
	}
	cout << endl;
}

/**~*~*
	This function prints all the values within a range [num1 to num2].
	It recursively goes through the binary tree.
*~**/
void BST::_BST_PrintRange(BST_Node *root, int num1, int num2) const
{
	if (num2 < num1)
		return;

	if (root == NULL)
		return;

	if (num1 < root->data.num)
		_BST_PrintRange(root->left, num1, num2);

	if (num1 <= root->data.num && num2 >= root->data.num)
		cout << root->data.num << " ";

	if (num2 > root->data.num)
		_BST_PrintRange(root->right, num1, num2);
}

/**~*~*
   Insert data into a BST
*~**/
void BST::BST_insert(Data dataIn)
{
    BST_Node *newNode;
    BST_Node *pWalk;
    BST_Node *parent;

    // allocate the new node
    newNode = new BST_Node;
    newNode->data  = dataIn;
    newNode->left  = NULL;
    newNode->right = NULL;

	parent = root;

    if (!root) // tree is empty
        root = newNode;
    else
    {
        pWalk = root;
        while( pWalk )
        {
            parent = pWalk;
            if( dataIn.num < pWalk->data.num )
                pWalk = pWalk->left;
            else
                pWalk = pWalk->right;
        }

        // insert the new node
		if (parent)
		{
			if (dataIn.num < (parent->data).num) // no left child
				parent->left = newNode;
			else
				parent->right = newNode;
		}
    }

    count++;
}


/**~*~*
   Destructor
   This function calls a recursive function to delete all nodes in the binary tree
*~**/
BST::~BST()
{
    if (root)
        _BST_Destroy(root);
}

/**~*~*
   This function traverses the binary tree in postorder and deletes every node
*~**/
void BST::_BST_Destroy(BST_Node *root)
{
    if (root)
    {
        _BST_Destroy(root->left);
        _BST_Destroy(root->right);
        delete root;
    }
    return;
}

/**~*~*
   Search a BST for a given target: if found, returns true and passes back
   data, otherwise returns false. It calls the private _search to locate the node.
*~**/
bool BST::Search(int target, Data &data)
{
    BST_Node *found = _search(target);
    if (found)
    {
        data = found->data;
        return true;
    }
    return false;
}

bool BST::Delete(int target)
{
	BST_Node *found = _search(target);
	if (found)
	{
		_delete(root, target);
		return true;
	}
	return false;
}

BST:: BST_Node * BST::_delete(BST_Node *root, int target)
{
	if (root == NULL)
		return NULL;
	else if (root->data.num == target)
	{
		if (root->right == NULL)
		{
			return root->left;
		}
		else if (root->left == NULL)
		{
			return root->right;
		}
		else if (root->left->right == NULL)
		{
			root->data = root->left->data;
			root->left = root->left->left;
			return root;
		}
		else
		{
			BST_Node * marker = root->left;
			while (marker->right->right != NULL)
			{
				marker = marker->right;
			}
			root->data = marker->right->data;
			marker->right = marker->right->left;
			return root;
		}
	}
	else if (root->data.num >= target)
	{
		root->left = _delete(root->left, target);
		return root;
	}
	else
	{
		root->right = _delete(root->right, target);
		return root;
	}
}

/**~*~*
   Locates the node that contains a given target in a BST:
   - if found returns a pointer to that node
   - if not found returns NULL
*~**/
BST::BST_Node * BST::_search(int target)
{
    if (!root) // tree is empty
        return NULL;

    // tree is not empty
    BST_Node *pWalk = root;
    while( pWalk )
    {
        if( target < pWalk->data.num )
            pWalk = pWalk->left;
        else
            if( target > pWalk->data.num )
                pWalk = pWalk->right;
            else
                return pWalk; // found
    }

    return NULL; // not found
}


