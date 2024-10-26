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
        cout << "Item ID            :  " << item_id << endl;
        cout << "Item Name          :  " << item_name << endl;
        cout << "Item Description   :  " << item_description << endl;
        cout << "Quantity           :  " << quantity << endl;
        cout << "Price              :  " << price << endl;
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

    node* search (int id)
    {
        node* temp = root;  // keep track of root

        while (temp)
        {
            if (temp->data.item_id < id)
            {
                if (temp -> right)
                    temp = temp -> right;
                else
                {
                    cout << "Item Not found" << endl;
                    return 0;
                }
            }

            else if (temp->data.item_id > id)
            {
                if (temp -> left)
                    temp = temp -> left;
                else
                {
                    cout << "Item Not found" << endl;
                    return 0;
                }
            }

            else
            {
                return temp;
            }
        }
    }

    void updateQuantity(int item_id, int qty)
    {
        node* temp = search(item_id);   // retrive node for crossponding item_id...

        //  if node exists, then update quantity
        if (temp)
            temp->data.quantity = qty;
    }

    void updatePrice(int item_id, float price)
    {
        node* temp = search(item_id);   // retrive node for crossponding item_id...
        
        //  if node exists, then update price
        if (temp)
            temp->data.price = price;
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

    ////////////////////////////////////////////////////////////////
    // --------------      Task 2      ---------------------------//
    ////////////////////////////////////////////////////////////////

    void CheckStockAvailability(int id)
    {
        node* temp = search(id);

        // if available
        if (temp)
        {
            cout << "Quantity of " << temp->data.item_name << " is " << temp->data.quantity << endl;
        }
    }

    void lowStockAlert(int threshold, node* nod)
    {
        // using inOrder
        if (nod)
        {
            lowStockAlert(threshold, nod->left);
            if (nod->data.quantity < threshold)
            {
                cout << "\n---------------------------------------\n\n";
                nod->data.print();
            }
            lowStockAlert(threshold ,nod->right);
        }
    }

    void restockItem(int id, int qty)
    {
        node* temp = search(id);

        // if available
        if (temp)
        {
            temp->data.quantity += qty;
        }
    }

    ////////////////////////////////////////////////////////////////
    // --------------      Task 2      ---------------------------//
    ////////////////////////////////////////////////////////////////

};

#endif