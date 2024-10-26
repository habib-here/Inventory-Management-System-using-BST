#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;

class inventory
{
public:
    int item_id;
    string item_name;
    string item_description;
    int quantity;
    float price;

    inventory()
    {
        item_id = -1;
        item_name = "itemName";
        item_description = "itemDescription";
        quantity = -1;
        price = -1.1;
    }

    void print()
    {
        cout << "Item ID    :  " << item_id << endl;
        cout << "Item Name  :  " << item_name << endl;
        cout << "Quantity   :  " << quantity << endl;
        cout << "Price      :  " << price << endl;
    }
};

class node
{
public:
    inventory data;
    node* left;
    node* right;

    node()
    {
        left = right = NULL;
    }    
};

#endif