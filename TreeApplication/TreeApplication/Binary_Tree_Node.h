#pragma once
#include<iostream>
#include<string>
using namespace std;

//precondition: going to create a class that is a template container
//postcondition: going to create privates that get me the left and right child
template<class Item>
class Binary_Tree_Node {
private:
    //the type of nodes are going to be in a template containers
    Item data;
    //will keep track of the left child
    const Binary_Tree_Node* left;
    //will keep track of the right child
    const Binary_Tree_Node* right;
public:
    //default constructor
    Binary_Tree_Node();
    //constructor
    Binary_Tree_Node(const Item& init_data, Binary_Tree_Node* init_left = NULL, Binary_Tree_Node* init_right = NULL);

    //getters(accessors)
    Item& getData();
    Binary_Tree_Node*& getLeft();
    Binary_Tree_Node*& getRight();
    //setters(mutators)
    void setData(const Item& newData);
    void setLeft(const Binary_Tree_Node* newLeft);
    void setRight(const Binary_Tree_Node* newRight);

    //getters
    const Item& getData() const;
    const Binary_Tree_Node* getLeft() const;
    const Binary_Tree_Node* getRight() const;

    //check if its a leaf (no more subtree)
    bool isLeaf() const;
};

//precondition: going to create a parameter that is a leaf 
//postcondition: going to then do recursion that will delete each node and then we have to deallocate so it does not leak
template<class Item>
void delete_tree(const Binary_Tree_Node<Item>* leaf) { // Recursive
    if (leaf == NULL) {
        return;
    }

    /* first delete both subtrees */
    delete_tree(leaf->getLeft());
    delete_tree(leaf->getRight());

    /* then delete the node */
    cout << "\n\t\tDeleting: " << leaf->getData();
    delete leaf;
    leaf = NULL;
}

//precondition: going to pass in 5 parameters
//postcondition: going to then print each node, the root the childrens and so on
template<class Item>
void print_tree(const string& prefix, const Binary_Tree_Node<Item>* node, bool isLeft, bool root, bool last) {
    if (node != NULL) {
        cout << prefix;
        if (!root) {
            if (isLeft) {
                if (node->getLeft() == NULL && node->getRight() == NULL)
                    cout << char(192) << string(3, char(196));
                else
                    cout << char(195) << string(3, char(196));
            }
            else {
                if (last)
                    cout << char(192) << string(3, char(196));
                else
                    cout << char(195) << string(3, char(196));
            }
            cout << " " << node->getData() << '\n';
        }
        else
            cout << "    " << node->getData() << '\n';


        // enter the next tree level - left and right branch
        string s = "    ";
        s[0] = char(179);
        print_tree(prefix + (isLeft ? s : "    "), node->getLeft(), true, false, false);
        print_tree(prefix + (isLeft ? s : "    "), node->getRight(), false, false, true);
    }
}

