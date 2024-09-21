#include "AnimalGuessing.h"
#include <algorithm>

// Helper function to remove brackets from a string
// Precondition: 'str' is a valid string.
// Postcondition: Returns 'str' with brackets removed.
template <class Item>
string AnimalGuessing<Item>::remove_brackets(const string& str)
{
    string result = str;
    result.erase(remove(result.begin(), result.end(), '['), result.end());
    result.erase(remove(result.begin(), result.end(), ']'), result.end());
    result.erase(remove(result.begin(), result.end(), '('), result.end());
    result.erase(remove(result.begin(), result.end(), ')'), result.end());
    return result;
}

// Helper function to build the tree from a file
// Precondition: 'file' is a valid input file stream.
// Postcondition: Returns a pointer to the root of the tree built from the file.
template <class Item>
AnimalGuessing<Item>* AnimalGuessing<Item>::build_tree_from_file(ifstream& file)
{
    string line;
    getline(file, line);

    if (line.empty())
    {
        return nullptr;
    }

    AnimalGuessing<Item>* root = new AnimalGuessing<Item>(remove_brackets(line));

    // Check if the node is a question or a leaf node
    if (line.front() == '[')
    {
        // Recursive call for left and right children (questions)
        root->left() = build_tree_from_file(file);
        root->right() = build_tree_from_file(file);
    }

    return root;
}

// Constructor
// Precondition: None.
// Postcondition: Creates a new instance of AnimalGuessing with given data, left, and right pointers.
template <class Item>
AnimalGuessing<Item>::AnimalGuessing(const Item& init_data, AnimalGuessing* init_left, AnimalGuessing* init_right)
{
    data_field = init_data;
    left_field = init_left;
    right_field = init_right;
}

// MODIFICATION MEMBER FUNCTIONS

// Precondition: None.
// Postcondition: Returns a reference to the data.
template <class Item>
Item& AnimalGuessing<Item>::data()
{
    return data_field;
}

// Precondition: None.
// Postcondition: Returns a reference to the left pointer.
template <class Item>
AnimalGuessing<Item>*& AnimalGuessing<Item>::left()
{
    return left_field;
}

// Precondition: None.
// Postcondition: Returns a reference to the right pointer.
template <class Item>
AnimalGuessing<Item>*& AnimalGuessing<Item>::right()
{
    return right_field;
}

// Precondition: None.
// Postcondition: Sets the data to the new value.
template <class Item>
void AnimalGuessing<Item>::set_data(const Item& new_data)
{
    data_field = new_data;
}

// Precondition: None.
// Postcondition: Sets the left pointer to the new value.
template <class Item>
void AnimalGuessing<Item>::set_left(AnimalGuessing* new_left)
{
    left_field = new_left;
}

// Precondition: None.
// Postcondition: Sets the right pointer to the new value.
template <class Item>
void AnimalGuessing<Item>::set_right(AnimalGuessing* new_right)
{
    right_field = new_right;
}

// CONSTANT MEMBER FUNCTIONS
// Precondition: None.
// Postcondition: Returns a const reference to the data.
template <class Item>
const Item& AnimalGuessing<Item>::data() const
{
    return data_field;
}

// Precondition: None.
// Postcondition: Returns a const pointer to the left node.
template <class Item>
const AnimalGuessing<Item>* AnimalGuessing<Item>::left() const
{
    return left_field;
}

// Precondition: None.
// Postcondition: Returns a const pointer to the right node.
template <class Item>
const AnimalGuessing<Item>* AnimalGuessing<Item>::right() const
{
    return right_field;
}

// Precondition: None.
// Postcondition: Returns true if the node is a leaf (has no children), false otherwise.
template <class Item>
bool AnimalGuessing<Item>::is_leaf() const
{
    return (left_field == nullptr) && (right_field == nullptr);
}

// MEMBER FUNCTIONS

// Precondition: None.
// Postcondition: Clears the tree rooted at root_ptr.
template <class Item>
void AnimalGuessing<Item>::tree_clear(AnimalGuessing<Item>*& root_ptr)
{
    AnimalGuessing<Item>* child;
    if (root_ptr != nullptr)
    {
        child = root_ptr->left();
        tree_clear(child);
        child = root_ptr->right();
        tree_clear(child);
        delete root_ptr;
        root_ptr = nullptr;
    }
}

// Precondition: None.
// Postcondition: Creates and returns a copy of the tree rooted at root_ptr.
template <class Item>
AnimalGuessing<Item>* AnimalGuessing<Item>::tree_copy(const AnimalGuessing<Item>* root_ptr)
{
    AnimalGuessing<Item>* l_ptr;
    AnimalGuessing<Item>* r_ptr;
    if (root_ptr == nullptr)
        return nullptr;
    else
    {
        l_ptr = tree_copy(root_ptr->left());
        r_ptr = tree_copy(root_ptr->right());
        return new AnimalGuessing<Item>(root_ptr->data(), l_ptr, r_ptr);
    }
}

// Precondition: None.
// Postcondition: Attempts to open the file 'file_name' and builds a tree from its contents.
// Returns a pointer to the root of the tree, or nullptr if the file cannot be opened.
template <class Item>
AnimalGuessing<Item>* AnimalGuessing<Item>::beginning_tree(const string& file_name)
{
    ifstream file(file_name);

    if (file.fail())
    {
        return nullptr;
    }

    // Call a helper function to recursively build the tree
    return build_tree_from_file(file);
}

// Precondition: 'current_ptr' points to a valid AnimalGuessing node.
// Postcondition: Prints the data of the current node, asks the user a yes/no question, and moves 'current_ptr' accordingly.
template <class Item>
void AnimalGuessing<Item>::ask_and_move(AnimalGuessing<string>*& current_ptr)
{
    cout << "\n\t\t\t" << current_ptr->data();
    if (inquire(" (Y-yes/N-no) "))
        current_ptr = current_ptr->left();
    else
        current_ptr = current_ptr->right();
}

// Precondition: 'leaf_ptr' points to a leaf node.
// Postcondition: Prompts the user to provide a new question and two new animals.
// Updates the current leaf node with the new question and animals based on user input.
template <class Item>
void AnimalGuessing<Item>::learn(AnimalGuessing<string>* leaf_ptr)
{
    string guess_animal; // The animal that was just guessed
    string correct_animal; // The animal that the user was thinking of
    string new_question; // A question to distinguish the two animals
    // Set strings for the guessed animal, correct animal, and a new question.
    guess_animal = leaf_ptr->data();

    correct_animal = inputString("\n\t\t\tI give up. What are you ? ", false);

    cout << "\n\t\t\tPlease type a yes/no question that will distinguish a " << correct_animal << " from a " << guess_animal << ".";

    new_question = inputString("\n\t\t\tYour question: ", true);

    // Put the new question in the current node, and add two new children.
    leaf_ptr->set_data(new_question);
    cout << "\n\t\t\tAs a " << correct_animal << ", " << new_question;
    if (inquire(" (Y-yes/N-no) "))
    {
        leaf_ptr->set_left(new AnimalGuessing<string>(correct_animal));
        leaf_ptr->set_right(new AnimalGuessing<string>(guess_animal));
    }
    else
    {
        leaf_ptr->set_left(new AnimalGuessing<string>(guess_animal));
        leaf_ptr->set_right(new AnimalGuessing<string>(correct_animal));
    }
}

// Precondition: 'current_ptr' points to the root of the AnimalGuessing tree.
// Postcondition: Plays the game, making guesses and learning if necessary based on user input.
template <class Item>
void AnimalGuessing<Item>::play(AnimalGuessing<string>* current_ptr)
{
    cout << "\n\t\t\tThink of an animal, then ";
    system("pause");
    while (!current_ptr->is_leaf())
        ask_and_move(current_ptr);
    cout << "\n\t\t\tMy guess is " << current_ptr->data();
    if (!inquire(". Am I right? "))
        learn(current_ptr);
    else
        cout << "\n\t\t\tI knew it all along!\n";
}

// Precondition: None.
// Postcondition: Saves the current AnimalGuessing tree to the file with the given name.
template <class Item>
void AnimalGuessing<Item>::save_tree_to_file(const string& file_name)
{
    ofstream file(file_name);

    if (file.fail())
    {
        cout << "\n\t " + file_name + " can not be opened";
        return;
    }

    save_tree_to_file_recursive(file, this); // Start with an initial indentation level of 0
    cout << "\n\t\tGame has been saved to " + file_name << "\n\n";
}

// Precondition: 'file' is a valid output file stream. 'root' points to a valid AnimalGuessing node.
// Postcondition: Recursively saves the AnimalGuessing tree to the file with proper formatting.
template <class Item>
void AnimalGuessing<Item>::save_tree_to_file_recursive(ofstream& file, AnimalGuessing<string>* root)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->is_leaf())
    {
        file << "(" << root->data() << ")\n";     
    }
    else
    {
        file << "[" << root->data() << "]\n";

        // Recursive calls for left and right children with increased indentation level
        save_tree_to_file_recursive(file, root->left());
        save_tree_to_file_recursive(file, root->right());
    }
}

// Precondition: NA
// Postcondition: Display the menu
template <class Item>
void AnimalGuessing<Item>::menu()
{
    AnimalGuessing<string>* taxonomy_root_ptr;

    // Use the correct function name: beginning_tree
    taxonomy_root_ptr = AnimalGuessing<string>::beginning_tree("animal.txt");

    if (taxonomy_root_ptr == nullptr)
    {
        cout << "\n\tanimal.txt can not be opened\n";
        return;
    }

    char choice;

    do {
        system("cls");
        cout << "\n\t3> Animal Guessing Game";
        cout << "\n\t" << string(82, char(205));
        cout << "\n\n\tA game tree for a simple game of 'animal' twenty questions would look like: \n";

        cout << "\n\t\t\t\t[ Is it a mammal? ]\n";
        cout << "\t\t                    /         \\" << endl;
        cout << "\t\t                   /           \\" << endl;
        cout << "\t\t [ Does it have stripes? ]     [ Is it a bird? ]" << endl;
        cout << "\t\t         /       \\                  /       \\" << endl;
        cout << "\t\t        /         \\                /         \\" << endl;
        cout << "\t\t  ( Zebra )    ( Lion )    [ Does it fly? ]  ( Gila monster )" << endl;
        cout << "\t\t                             /       \\" << endl;
        cout << "\t\t                            /         \\" << endl;
        cout << "\t\t                     ( Eagle )     ( Penguin )" << endl;

        cout << "\n\n\tA learning version of twenty questions: one that not only plays the game but learns new\n\tobjects when it loses.\n";
        cout << "\n\n\tWelcome to Animal Guessing Game";
        cout << "\n\t" << string(82, char(205));
        cout << "\n\t\tA> Play the game";
        cout << "\n\t\tB> Save the game file";
        cout << "\n\t" << string(82, char(205));
        cout << "\n\t\t0> return";
        cout << "\n\t" << string(82, char(205)) << "\n";
        choice = inputChar("\t\tOption: ", static_cast<string>("AB0"));

        switch (toupper(choice)) {
        case 'A': {
            system("cls");
            do
                play(taxonomy_root_ptr);
            while (inquire("\n\t\t\tShall we play again? "));

            cout << "\n\t\t\tThanks for teaching me a thing or two.\n";
        }
                break;
        case 'B': {
            save_tree_to_file("animal.txt");
            system("pause");
        }
                break;
        case '0': {
            return;
        }
        }
    } while (true);
}
