#include "schuhmann_william_assn4.h"
#include<iostream>
#include<fstream>
using namespace std;

BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    Clear(root);
}

void BST::readFromFile(ifstream& infile)
{
	if(!infile)
	{
		cout<<"The File isn't Found!"<<endl;
	}else
	{
		while(infile.good() && !infile.eof())
		{
			
		}
	}
}

void BST::findMinOfRight(node* n, node* &m, node* &pm)
{
    node* prev_n = n;
    n = n->right;

    while(n->left)
    {
        prev_n = n;
        n = n->left;
    }

    m = n; //Minimum
    pm = prev_n; //Minimum of Height
}

void BST::Clear(node* n)
{
    if(!n)
        return;

    Clear(n->left);
    Clear(n->right);
    delete n;
}

void BST::insert(string s)
{
    if(root) 
    {
        node* n = root;
        node* prev_n = NULL;

        while(n)
        {
            prev_n = n;
            if(s > n->word)
                n = n->right;
            else
            {
                if(s < n->word) 
                    n = n->left;
                else
                {
                    n->occurences++;
                    return;
                }
            }
        }

        if(s > prev_n->word) //New Node
        {
            prev_n->right = new node(s);
            if(!prev_n->right)
                cout<<"Failed to Allocate Memory"<<endl;
        }
        else
        {
            prev_n->left = new node(s);
            if(!prev_n->left)
                cout<<"Failed to Allocate Memory"<<endl;
        }
    }
    else
    {
        root = new node(s);
        if(!root)
            cout<<"Failed to Allocate Memory"<<endl;
    }
}

bool BST::search(string s)
{
    node* n = root;

    while(n)
    {
        if(s > n->word)
            n = n->right;
        else
        {
            if(s < n->word) 
                n = n->left;
            else 
            {
                cout<<"Word: "<<n->word<<" Occurences: "<<n->occurences<<endl;
                return true;
            }
        }
    }
    return false;
}

bool BST::search(string s, node* &c, node* &p)
{
    node* n = root;
    node* prev_n = NULL;

    while(n)
    {
        if(s > n->word)
        {
            prev_n = n;
            n = n->right;
        }
        else
        {
            if(s < n->word)
            {
                prev_n = n;
                n = n->left;
            }
            else
            {
                c = n;
                p = prev_n;
                return true;
            }
         }
     }
     return false;
}

bool BST::deleteIt(string s)
{
    node* c = NULL;
    node* p = NULL;

    if(!(search(s, c, p)))
        return false;

    return deleteIt(c, p);
}

bool BST::deleteIt(node* c, node* p)
{

    bool flag = false; 
        if(p && p->right == c)
            flag = true;
    //Case 1
    if(!c->right && !c->left)
    {
        if(p) 
        {
            if(flag)
                p->right = NULL;
            else
                p->left = NULL;
            delete c;
        }
        else
        {
            delete root;
            root = NULL;
        }

        return true;
    }
    //Case 2
    if(c->right && !c->left)
    {
        if(p) 
        {
            if(flag)  
                p->right = c->right;
            else
                p->left = c->right;
            delete c;
        }
        else
        {
            node* temp = root->right;
            delete root;
            root = temp;
        }

        return true;
    }

    if(!c->right && c->left)
    {
        if(p)
        {
            if(flag)
                p->right = c->left;
            else
                p->left = c->left;

            delete c;
        }
        else
        {
            node* temp = root->left;
            delete root;
            root = temp;
        }

        return true;
    }
    //Case 3
    node* min_right;
    node* pmin_right;
    node* temp;

    if(p)
    {
        findMinOfRight(c, min_right, pmin_right);
        temp = new node(min_right->word);  
        temp->occurences = min_right->occurences;
        deleteIt(min_right, pmin_right); 
        temp->right = c->right; 
        temp->left = c->left;
        delete c;
      if(flag) 
            p->right = temp;
        else
            p->left = temp;
        return true;
    }
    else 
    {
        findMinOfRight(root, min_right, pmin_right);
        temp = new node(min_right->word);
        temp->occurences = min_right->occurences;
        deleteIt(min_right, pmin_right);
        temp->right = root->right;
        temp->left = root->left;
        delete root;
        root = temp;
        return true;
    }
    return false; 
}

void BST::preorder(node* n)
{
    if(!n){
        return;
	}
    n->print();
    preorder(n->left);
    preorder(n->right);
}

void BST::inorder(node* n)
{
    if(!n){
        return;
	}
    inorder(n->left);
    n->print();
    inorder(n->right);
}

void BST::postorder(node* n)
{
    if(!n){
        return;
	}
    postorder(n->left);
    postorder(n->right);
    n->print();
}

