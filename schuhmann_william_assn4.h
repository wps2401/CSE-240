#ifndef SCHUHMANN_WILLIAM_ASSN4_H
#define SCHUHMANN_WILLIAM_ASSN4_H
#include <string>
#include <iostream>
using namespace std;

class BST
{
    public:
        BST(); //Constructor: Makes empty tree with a NULL root pointer.
        ~BST(); //Deletes tree using postorder traversal using Clear().
        void insert(string); //Inserts and counts duplicates
        bool search(string); //Search
        bool deleteIt(string); //Delete
        void preorder() {preorder(root);}
        void inorder() {inorder(root);}
        void postorder() {postorder(root);}
	void readFromFile(ifstream& infile);

    protected:
        //Node class used only by BST and children
        class node
        {
            public:
                node(string s) {word = s; occurences = 1;right = left = NULL;} //Node Constructor
                void print() {cout<<"Word: "<<word<<" Occurences: "<<occurences<<endl;}
                //Node's variables are set to public because Node will only be used inside BST and its chidlren
                int occurences;
                string word;
                node* right;
                node* left;
                int height;
        };

        node* root;

        //Methods used only BST and children
        bool search(string, node*&, node*&); //Search #2
        void preorder(node*);
        void inorder(node*);
        void postorder(node*);
        void Clear(node*);
        void findMinOfRight(node*, node*&, node*&); //Finds Min
        bool deleteIt(node*, node*); //Delete #2

    private:

};

#endif // SCHUHMANN_WILLIAM_ASSN4_H

