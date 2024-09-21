// Tree Console Application

#include<iostream>
#include"input.h"
#include"BTree.cpp"
#include"Binary_Tree_Node.cpp"
#include"AnimalGuessing.cpp"
using namespace std;

//prototype
int menuOption();
void challenge1();
void challenge2();
void challenge3();

//precondition: NA
//postcondition: display main menu
int main()
{
	do {
		switch (menuOption()) {
		case 0: exit(1); break;
		case 1: challenge1(); break;
		case 2: challenge2(); break;
		case 3: system("cls"); challenge3(); break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return EXIT_SUCCESS;
}

//precondition: return options
//postcondition: it will return an int (the choice of the menu)
int menuOption() {
	system("cls");
	cout << "\n\tTrees by Thanh Tran";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t1> Trees of strings";
	cout << "\n\t\t2> Trees container of integers";
	cout << "\n\t\t3> Animal Guessing Game";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t0> Exit";
	cout << "\n\t" << string(100, char(205));
	//calling the input.h and we are inputting c1 from 0 through 3
	return inputInteger("\n\t\tOption: ", 0, 3);
}

//precondition: going to call the Binary_Tree_Node class and then pass in a template that is a string
//postcondition: 
void challenge1() {
	system("cls");
	//will hold all the root
	Binary_Tree_Node<string>* tree = new Binary_Tree_Node<string>;
	tree->setData("trunk");
	cout << "\n\t1> Tree of strings";
	cout << "\n\t" << string(82, char(205));
	cout << "\n\n\tA> Created root (" << tree->getData() << ") with no leaf.";
	//call the print function
	print_tree<string>("\n\n\t\t", tree, false, true, true);
	//create two branches (which are our subtrees) for branch #1 and branch #2
	Binary_Tree_Node<string>* branch1 = new Binary_Tree_Node<string>;
	Binary_Tree_Node<string>* branch2 = new Binary_Tree_Node<string>;
	branch1->setData("branch #1");
	branch2->setData("branch #2");
	cout << "\n\tB> Root (" << tree->getData() << ") grows two branches : " << branch1->getData() << " and " << branch2->getData() << ".";
	cout << "\n\t\tA branch of (" << branch1->getData() << ") grows left of the root.";
	cout << "\n\t\tA branch of (" << branch1->getData() << ") grows right of the root.";
	//now set them to tree (which is our root), left subtree (branch1) and right subtree (branch2)
	tree->setLeft(branch1);
	tree->setRight(branch2);
	cout << "\n\n";
	//call the print function
	print_tree<string>("\t\t", tree, false, true, true);
	cout << "\n\tC> Branches grows leaves.";
	cout << "\n\n\t\tLeft branch (of branch #1) grows two leaves: leaf #1 and leaf #2.";
	Binary_Tree_Node<string>* leaf1 = new Binary_Tree_Node<string>;
	Binary_Tree_Node<string>* leaf2 = new Binary_Tree_Node<string>;
	leaf1->setData("leaf #1");
	leaf2->setData("leaf #2");
	//now set them to branch1 (branch1 is our ancestor (parent) basically with children's which are the leaf1 and leaf2)
	branch1->setLeft(leaf1);
	branch1->setRight(leaf2);
	cout << "\n\n";
	print_tree<string>("\t\t", tree, false, true, true);
	cout << "\n\t\tRight branch of (branch #2) grows two leaves: leaf #3 and leaf #4.";
	//now same thing but now branch2 will have another subtree with 2 leaves which are the children's 
	Binary_Tree_Node<string>* leaf3 = new Binary_Tree_Node<string>;
	Binary_Tree_Node<string>* leaf4 = new Binary_Tree_Node<string>;
	leaf3->setData("leaf #3");
	leaf4->setData("leaf #4");
	//now set left and right to branch2, now branch2 who is the parent will have children's that are leaf3 and leaf4
	branch2->setLeft(leaf3);
	branch2->setRight(leaf4);
	cout << "\n\n";
	print_tree<string>("\t\t", tree, false, true, true);
	cout << "\n\tD> Left leaf sprouts and yields a fruit (apple).";
	Binary_Tree_Node<string>* fruit = new Binary_Tree_Node<string>;
	fruit->setData("apple");
	//now set the left leaf#1 which is our ancestor ancestors to have a children fruit apple
	leaf1->setLeft(fruit);
	cout << "\n\n";
	print_tree<string>("\t\t", tree, false, true, true);
	cout << "\n\tE> Right leaf sprouts and yields two fruits (orange coconut).";
	Binary_Tree_Node<string>* fruit1 = new Binary_Tree_Node<string>;
	Binary_Tree_Node<string>* fruit2 = new Binary_Tree_Node<string>;
	fruit1->setData("orange");
	fruit2->setData("coconut");
	//now going to the parent leaf#3 to have children's which are orange and coconut (they are siblings now) 
	leaf3->setLeft(fruit1);
	leaf3->setRight(fruit2);
	cout << "\n\n";
	print_tree<string>("\t\t", tree, false, true, true);
	cout << "\n\tF> Delete tree.";
	delete_tree<string>(tree);
	cout << "\n";
}

//precondition: NA
//postcondition: BTree Menu
void challenge2() {
	BTree<int> menu;
	menu.mainInformation();
}
//precondition: 
//postcondition: going to then call my mainMenuInformation function that will have all the information and the menus as well 
void challenge3()
{
	AnimalGuessing<string> node;

	node.menu();
}