//William Schuhmann
//main.cpp
//

#include<iostream>
#include"schuhmann_william_assn4.h"
#include<fstream>

int main()
{
	cout<<"Welcome to CSE240 Assignment 2!"<<endl;
	ifstream infile("Wellington's Men.txt");
	BST my;
	my.readFromFile(infile);
	return 0;	
}
