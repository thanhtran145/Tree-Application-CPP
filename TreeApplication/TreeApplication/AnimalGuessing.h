#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool inquire(string prompt);
char inputChar(string prompt, char yes, char no);
string inputString(string prompt, bool spaces);
char inputChar(string prompt, string options);

template <class Item>
class AnimalGuessing
{
private:
    Item data_field;
    AnimalGuessing* left_field;
    AnimalGuessing* right_field;

    static string remove_brackets(const string& str);

    static AnimalGuessing<Item>* build_tree_from_file(ifstream& file);

public:
    // TYPEDEF
    typedef Item value_type;

    // CONSTRUCTOR
    AnimalGuessing(const Item& init_data = Item(), AnimalGuessing* init_left = nullptr, AnimalGuessing* init_right = nullptr);

    // MODIFICATION MEMBER FUNCTIONS
    Item& data();
    AnimalGuessing*& left();
    AnimalGuessing*& right();
    void set_data(const Item& new_data);
    void set_left(AnimalGuessing* new_left);
    void set_right(AnimalGuessing* new_right);

    // CONSTANT MEMBER FUNCTIONS
    const Item& data() const;
    const AnimalGuessing* left() const;
    const AnimalGuessing* right() const;
    bool is_leaf() const;

    // MEMBER FUNCTIONS
    void tree_clear(AnimalGuessing<Item>*& root_ptr);
    AnimalGuessing<Item>* tree_copy(const AnimalGuessing<Item>* root_ptr);
    static AnimalGuessing<Item>* beginning_tree(const string& file_name);
    void ask_and_move(AnimalGuessing<string>*& current_ptr);
    void learn(AnimalGuessing<string>* leaf_ptr);
    void play(AnimalGuessing<string>* current_ptr);
    void save_tree_to_file(const string& file_name);
    static void save_tree_to_file_recursive(ofstream& file, AnimalGuessing<string>* root);
    void menu();
};
