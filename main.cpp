#include "TREE.h"

void print2DNode(node** nodess, int total)
{
    cout << "\n---------------------------------------\n\n";
 
    for(int i = 0; i < total; i++)
    {
        
        nodess[i]->data.print();
        cout << "\n---------------------------------------\n\n";
    }
}

int main(void)
{
    tree t1;

    inventory item;

    t1.insert(item);
    t1.insert(2, "cable", "HDMI", 50, 400);
    t1.insert(3, "cable", "Type-C", 50, 400);
    t1.CheckStockAvailability(t1.root->right->data.item_id);
    t1.updatePrice(2, 350);
    t1.updateQuantity(2, 100);
    t1.lowStockAlert(51, t1.root);
    cout << "_________________________________________" << endl;
    t1.restockItem(3, 5);
    t1.lowStockAlert(51, t1.root);

    cout << "_________________________________________" << endl;
    cout << "_________________________________________" << endl;
    cout << "_________________________________________" << endl;
    cout << "_________________________________________" << endl;

    int total_idx;
    node** inRange = t1.findInPrice(349,401, total_idx, t1.root);
    print2DNode(inRange, total_idx);
    delete[] inRange;

    cout << "_________________________________________" << endl;
    cout << "_________________________________________" << endl;
    cout << "_________________________________________" << endl;
    cout << "_________________________________________" << endl;

    cout << "______________Cheapest___________________" << endl;
    node* cheapest = t1.root;
    t1.isCheapest(cheapest, t1.root);
    cheapest->data.print();

    cout << "______________Expensive___________________" << endl;
    node* mostExpensive = t1.root;
    t1.isMostExpensive(mostExpensive, t1.root);
    mostExpensive->data.print();

    //t1.inOrder(t1.root);

    return 0;
}