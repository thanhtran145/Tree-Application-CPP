#include "Binary_Tree_Node.h"

//precondition: going to call the default constructor class
//postcondition: going to then initialize the privates 
template<class Item>
Binary_Tree_Node<Item>::Binary_Tree_Node() : data(" "), left(NULL), right(NULL) {}
//precondition: going to call the constructor class
//postcondition: going to then initialize the privates and data will now have newData
template<class Item>
Binary_Tree_Node<Item>::Binary_Tree_Node(const Item& init_data, Binary_Tree_Node* init_left, Binary_Tree_Node* init_right) {
	data = init_data;
	left = init_left;
	right = init_right;
}

//precondition: going to get the data 
//postcondition: going to return the private data (template class)
template<class Item>
Item& Binary_Tree_Node<Item>::getData() {
	return data;
}
//precondition: going to get the left 
//postcondition: going to return the private left (template class)
template<class Item>
Binary_Tree_Node<Item>*& Binary_Tree_Node<Item>::getLeft() {
	return left;
}
//precondition: going to get the right 
//postcondition: going to return the private right (template class)
template<class Item>
Binary_Tree_Node<Item>*& Binary_Tree_Node<Item>::getRight() {
	return right;
}

//precondition: going to get the new data
//postcondition: going to set the private data with the new data member (template class)
template<class Item>
void Binary_Tree_Node<Item>::setData(const Item& newData) {
	data = newData;
}
//precondition: going to get the new left
//postcondition: going to set the private left with the new left member (template class)
template<class Item>
void Binary_Tree_Node<Item>::setLeft(const Binary_Tree_Node* newLeft) {
	left = newLeft;
}
//precondition: going to get the new right
//postcondition: going to set the private right with the new right member (template class)
template<class Item>
void Binary_Tree_Node<Item>::setRight(const Binary_Tree_Node* newRight) {
	right = newRight;
}

//precondition: going to get the data (const)
//postcondition: going to return the private data (template class)
template<class Item>
const Item& Binary_Tree_Node<Item>::getData() const {
	return data;
}
//precondition: going to get the left (const)
//postcondition: going to return the private left (template class)
template<class Item>
const Binary_Tree_Node<Item>* Binary_Tree_Node<Item>::getLeft() const {
	return left;
}
//precondition: going to get the right (const)
//postcondition: going to return the private right (template class)
template<class Item>
const Binary_Tree_Node<Item>* Binary_Tree_Node<Item>::getRight() const {
	return right;
}

//precondition: going to get the left and right nodes
//postcondition: going to return true if they are NULL (empty) 
template<class Item>
bool Binary_Tree_Node<Item>::isLeaf() const {
	return (left == NULL && right == NULL);
}

