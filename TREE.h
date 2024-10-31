#ifndef TREE_H
#define TREE_H

#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

// ANSI color codes
const string RESET = "\033[0m"; // Reset to default
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";

// Forward declerations
class tree;
void bulkInsert(string, tree&);

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

void print() {
    cout << "=============================================\n";
    cout << "|            Inventory Item Details         |\n";
    cout << "=============================================\n";
    cout << "| Item ID       :  " << RED << setw(24) << left << item_id << RESET << " |\n";
    cout << "| Item Name     :  " << GREEN << setw(24) << left << item_name << RESET << " |\n";
    cout << "| Description   :  " << YELLOW << setw(24) << left << item_description << RESET << " |\n";
    cout << "| Quantity      :  " << BLUE << setw(24) << left << quantity << RESET << " |\n";
    cout << "| Price         :  " << MAGENTA << setw(24) << left << price << RESET << " |\n";
    cout << "=============================================\n";
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

    tree(string file)
    {
        root = 0;
        bulkInsert(file, *this);
    }

    void bulkInsertUpdate(string file)
    {
        bulkInsert(file, *this);
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

        // inserting in tree
        insert(newNode);
    }

    void insert(node* newNode)
    {
        node* temp = root;  // root track

        if (root)
        {
            while (temp)
            {          
                if (temp->data.item_id > newNode->data.item_id)
                {
                    if (temp -> left)
                        temp = temp->left;
                    else
                    {
                        temp -> left = newNode;
                        return;
                    }
                }

                else if (temp->data.item_id  < newNode->data.item_id)
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


    void insertUpdate(int id, string name, string des, int qty, float price)
    {
        inventory d(id, name, des, qty, price);
        insertUpdate(d);
    }

    void insertUpdate(inventory d)
    {
        // new Node which will be inserted
        node* newNode = new node();
        newNode->data = d;

        // inserting in tree
        insertUpdate(newNode);
    }

    void insertUpdate(node* newNode)
    {
        node* temp = root;  // root track

        if (root)
        {
            while (temp)
            {          
                if (temp->data.item_id > newNode->data.item_id)
                {
                    if (temp -> left)
                        temp = temp->left;
                    else
                    {
                        temp -> left = newNode;
                        return;
                    }
                }

                else if (temp->data.item_id  < newNode->data.item_id)
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
                    // Updating quantity
                    temp ->data.quantity = newNode->data.quantity;
                    
                    // Updating price
                    temp->data.price = newNode->data.price;
                    
                    cout << "Found item with same id. Updated quantity and Price" << endl;
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
                    return nullptr;
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
    return 0;
    }

void deleteNode(int num, node *&nodePtr)
{

if (nodePtr == NULL) // node does not exist in the tree
cout << num <<" not found.\n";

else if (num < nodePtr->data.item_id)

deleteNode(num, nodePtr->left); // find in left subtree

else if (num > nodePtr->data.item_id)
deleteNode(num, nodePtr->right); // find in right subtree

else // num == nodePtr->value i.e. node is found
makeDeletion(nodePtr); // actually deletes node from BST

}

void makeDeletion(node *&nodePtr) {
node *tempNodePtr; // Temperary pointer

if (nodePtr->right == NULL) { // case for leaf and one (left) child
tempNodePtr = nodePtr;
nodePtr = nodePtr->left; // Reattach the left child
delete tempNodePtr;
}

else if (nodePtr->left == NULL) { // case for one (right) child
tempNodePtr = nodePtr;
nodePtr = nodePtr->right; // Reattach the right child
delete tempNodePtr;
}

else { // case for two children.
tempNodePtr = nodePtr->right; // Move one node to the right
while (tempNodePtr->left) { // Go to the extreme left node
tempNodePtr = tempNodePtr->left;

}

tempNodePtr->left = nodePtr->left; // Reattach the left subtree
tempNodePtr = nodePtr;
nodePtr = nodePtr->right; // Reattach the right subtree
delete tempNodePtr;

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

    void print(node* nod)
    {
        // Print current node's data in table format with colors
        cout << "| " << RED << setw(10) << left << nod->data.item_id 
            << RESET << " | " 
            << GREEN << setw(15) << left << nod->data.item_name 
            << RESET << " | " 
            << YELLOW << setw(24) << left << nod->data.item_description 
            << RESET << " | " 
            << BLUE << setw(10) << left << nod->data.quantity 
            << RESET << " | " 
            << MAGENTA << setw(9) << left << nod->data.price 
            << RESET << " |\n";

        // Aligning the separator line
        cout << "------------------------------------------------------------------------------------\n";

    }

    void printHeader(node* nod)
    {
        // // Print only once, at the beginning
        // static bool isHeaderPrinted = false;
        // if (!isHeaderPrinted) {
        //     cout << "====================================================================================\n";
        //     cout << "|   Item ID  |    Item Name    |       Description        |  Quantity  |   Price   |\n";
        //     cout << "====================================================================================\n";
        //     isHeaderPrinted = true;
        // }
        // Print only once, at the beginning
        if (nod == root) {
            cout << "====================================================================================\n";
            cout << "|   Item ID  |    Item Name    |       Description        |  Quantity  |   Price   |\n";
            cout << "====================================================================================\n";
        }
    }

    void inOrder(node* nod)
    {
        if (nod) 
        {
            printHeader(nod);
            inOrder(nod->left);
            print(nod);
            inOrder(nod->right);
        }
    }


    void preOrder(node* nod)
    {
        if (nod)
        {
            printHeader(nod);
            print(nod);
            preOrder(nod->left);
            preOrder(nod->right);
        }
    }

    void postOrder(node* nod)
    {
        if (nod)
        {
            printHeader(nod);
            postOrder(nod->left);
            postOrder(nod->right);
            print(nod);
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
    // --------------      Task 3      ---------------------------//
    ////////////////////////////////////////////////////////////////
    
    void findNumRange(int min_price, int max_price, int& num, node* nod)
    {
        if (nod)
        {
            if ((nod->data.price < max_price) && (nod->data.price > min_price))
            {
                num++;
            }
            findNumRange(min_price, max_price, num, nod->left);
            findNumRange(min_price, max_price, num, nod->right);
        }
    }

    void findNodesRange(int min_price, int max_price, node**& nodess, int idx, node* nod)
    {
        if (nod)
        {
            if ((nod->data.price < max_price) && (nod->data.price > min_price))
            {
                *(nodess + idx) = nod;
                idx++;
            }
            findNodesRange(min_price, max_price, nodess, idx, nod->left);
            findNodesRange(min_price, max_price, nodess, idx, nod->right);
        }     
    }

    node** findInPrice(int min_price, int max_price, int&idx, node* nod)
    {
        // Calculated how many are present for DMA
        idx = 0;
        findNumRange(349, 401, idx, this->root);

        // DMA to store nodes within min_price and max_price
        node** nodess = new node*[idx];
        findNodesRange(min_price, max_price, nodess, 0, nod);

        // Now let retun
        return nodess;
    }

    void findInPrice(int min_price, int max_price, tree& InRange, node* nod)
    {
        if (nod)
        {
            if ((nod->data.price < max_price) && (nod->data.price > min_price))
            {
                // Avoid shallow copying
                node* newNode = new node();
                newNode->data = nod->data;

                // Now inserting
                InRange.insert(newNode);
            }
            findInPrice(min_price, max_price, InRange, nod->left);
            findInPrice(min_price, max_price, InRange, nod->right);
        }            
    }

/*
    tree findInPrice(int min_price, int max_price)
    {
        tree InRange;
        addInRange(min_price, max_price, InRange, InRange.root);
        return InRange;
    }
*/

    void isCheapest(node*& min, node* nod)
    {
        if (nod)
        {
            if (min->data.price > nod->data.price)
            {
                min = nod;
            }
            isCheapest(min, nod->left);
            isCheapest(min, nod->right);
        }
    }

    void isMostExpensive(node*& max, node* nod)
    {
        if (nod)
        {
            if (max->data.price < nod->data.price)
            {
                max = nod;
            }
            isMostExpensive(max, nod->left);
            isMostExpensive(max, nod->right);
        }
    }
};

    ////////////////////////////////////////////////////////////////
    // --------------      Task 4      ---------------------------//
    ////////////////////////////////////////////////////////////////
    void bulkInsert(string fileName, tree& t1)
    {
        // f"{item_id},{item_description},{quantity},{price}
        // Define variables to store data as per the format: {int}, {string}, {int}, {float}
        int item_id;
        string item_name, item_description;
        int quantity;
        float price;

        // Open file stream
        ifstream file(fileName);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            // Create a string stream from the line
            stringstream ss(line);

            // Read and parse each value based on the format
            char delimiter;
            ss >> item_id >> delimiter;
            getline(ss, item_name, ',');
            getline(ss, item_description, ',');
            ss >> quantity >> delimiter >> price;

            // // Output the data (for testing)
            // cout << "Item ID: " << item_id << endl;
            // cout << "item_name: " << item_name << endl;
            // cout << "Description: " << item_description << endl;
            // cout << "Quantity: " << quantity << endl;
            // cout << "Price: " << price << endl << endl;

            // Insert to Tree
            t1.insertUpdate(item_id, item_name, item_description, quantity, price);
        }

        // Close file stream
        file.close();
        return;
    }

    void print2DNode(node** nodess, int total)
    {
        for (int i = 0; i < total; i++)
        {
            nodess[i]->data.print();
        }
    }

#endif