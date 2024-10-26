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

    inventory (int id, string name, string des, int qty, float price)
    {
        item_id = id;
        item_name = name;
        item_description = des;
        quantity = qty;
        this->price = price;
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

class tree
{
public:
    node* root;

    tree()
    {
        root = 0;
    }

    void insert(int id, string name, string des, int qty, float price)
    {
        inventory d(id, name, des, qty, price);
        insert(d);
    }

    void insert(inventory d)
    {
        // new Node which will be inserted
        node* newNode = new node();
        newNode->data = d;

        node* temp = root;  // root track

        if (root)
        {
            while (temp)
            {          
                if (temp->data.item_id > d.item_id)
                {
                    if (temp -> left)
                        temp = temp->left;
                    else
                    {
                        temp -> left = newNode;
                        return;
                    }
                }

                else if (temp->data.item_id  < d.item_id)
                {
                    if (temp->right)
                        temp = temp -> right;
                    else
                    {
                        temp -> right = newNode;
                        return;
                    }
                }

                else    // same id
                {
                    delete newNode;
                    cout << "Cannot add inventory with same id !!!" << endl;
                    return;
                }
            }
            }
        else
        {
            root = newNode;
        }
    }

    void inOrder(node* nod)
    {
        if (nod)
        {
            inOrder(nod->left);
            cout << "\n---------------------------------------\n\n";
            nod->data.print();
            inOrder(nod->right);
        }
    }

    void preOrder(node* nod)
    {
        if (nod)
        {
            nod->data.print();
            cout << "\n---------------------------------------\n\n";
            preOrder(nod->left);
            preOrder(nod->right);
        }
    }

    void postOrder(node* nod)
    {
        if (nod)
        {
            postOrder(nod->left);
            postOrder(nod->right);
            nod->data.print();    
            cout << "\n---------------------------------------\n\n";
        }       
    }

};

#endif