//Linked-list defintion of a Binary Search Tree: includes node, position, and the actual tree with methods for adding to and removing from the tree

#ifndef MY_BINARY_SEARCH_TREE
#define MY_BINARY_SEARCH_TREE

#include <string>
#include <iostream> // probably not necessary

//-----------------------------------------------------------------------//

//generic tree node tracking rank/key value, left, right, and parent values
template <typename TGen>
class TreeNode {
public:
	TreeNode();
	~TreeNode();

	int key; //key value for heiarchical assignment within the tree
	TreeNode<TGen>* left;
	TreeNode<TGen>* right;
	TreeNode<TGen>* parent;
};

TreeNode::TreeNode(){ //constructor
	key = 0;
	left = NULL;
	right = NULL;
	parent = NULL;
}

TreeNode::TreeNode(int k) { //overloaded constructor
	key = k;
	left = NULL;
	right = NULL;
	parent = NULL;
}

TreeNode::~TreeNode(){
	delete key;
	delete left;
	delete right;
	delete parent;
}

//------------------------------------------------//

typedef int Elem; //custom int type for readability
class LinkedBinaryTree {
protected: //struct because no methods being used
	struct Node {
		Elem ele; // element value, which is basicaly an int because we it made is so with a typedef (typename is for templates)
		Node* par; // parent node
		Node* left; // left child node
		Node* right; // right child node

		Node(): ele(), par(NULL), left(NULL), right(NULL) {} // constructor, with everything in one line
	};

public: // Put your Position class here for getting the position/different parts of a node, basically like an accessor for th enodes
	class Position {
	private:
		Node* v; // pointer to a node
	public:
		Position(Node* v = NULL): v(v) {} // constructor, not quite sure what this one does...
		Elem& operator *() // so you can get the element of a node at a position using *
			{return v->ele;}
		Position left() const // get left child node of a node
			{return Position(v->left);} 
		Position right() const // get right child node of a node
			{return Position(v->right);}
		Position parent() const // get parent node of a node
			{return Position(v->par);}
		bool isRoot() const // is the node the root of the whole tree?
			{return v->par == NULL;}
		bool isExternal() const // does this node have any left and right children?
			{return v->left == NULL && v->right == NULL;}
		friend class LinkedBinaryTree; // allow LinkedBinaryTree to use this classes methods
	};
		
public: //public class for abstraction and information sharing
	LinkedBinaryTree(); //constructor
	int size() const; //number of nodes
	bool empty() const; //is the tree empty?
	Position root() const; // get the root
	//PositionList positions() const; list of nodes, not needed now
	void addRoot(); // add root to an empty tree
	void expandExternal(const Position& p); // add two nodes to an external node
	Position removeAboveExternal(const Position& p); // remove node p and the node above it, then connect
	//need housekeeping functions
protected: // local utilities
	//void preorder(Node* v, PositionList& pl) const;
private:
	Node* _root; // pointer to root
	int n; // for keeping track of tree size

};
#endif
