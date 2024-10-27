#include <iostream>
#include <string>
#include "tree.h"  // Assuming you have the necessary tree class header

using namespace std;

int main() {
    tree t1;
    int choice;
    bool running = true;

    while (running) {
        cout << "\nInventory Management System\n";
        cout << "1. Insert Item\n";
        cout << "2. Check Stock Availability\n";
        cout << "3. Update Price\n";
        cout << "4. Update Quantity\n";
        cout << "5. Low Stock Alert\n";
        cout << "6. Restock Item\n";
        cout << "7. Find Items in Price Range\n";
        cout << "8. Find Cheapest Item\n";
        cout << "9. Find Most Expensive Item\n";
        cout << "10. Bulk Insert/Update from CSV\n";
        cout << "11. Print Tree\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id, quantity, price;
                string name, des;

                cout << "Enter item ID: ";
                cin >> id;

                cout << "Enter item name: ";
                getline(cin, name);

                cout << "Enter description: ";
                getline(cin, des);

                cout << "Enter quantity: ";
                cin >> quantity;

                cout << "Enter price: ";;
                cin >> price;

                t1.insert(id, name, des, quantity, price);
                break;
            }
            case 2: {
                int id;
                cout << "Enter item ID to check stock availability: ";
                cin >> id;
                t1.CheckStockAvailability(id);
                break;
            }
            case 3: {
                int id, newPrice;
                cout << "Enter item ID and new price: ";
                cin >> id >> newPrice;
                t1.updatePrice(id, newPrice);
                break;
            }
            case 4: {
                int id, newQuantity;
                cout << "Enter item ID and new quantity: ";
                cin >> id >> newQuantity;
                t1.updateQuantity(id, newQuantity);
                break;
            }
            case 5: {
                int threshold;
                cout << "Enter quantity threshold for low stock alert: ";
                cin >> threshold;
                t1.lowStockAlert(threshold, t1.root);
                break;
            }
            case 6: {
                int id, quantity;
                cout << "Enter item ID and quantity to restock: ";
                cin >> id >> quantity;
                t1.restockItem(id, quantity);
                break;
            }
            case 7: {
                int minPrice, maxPrice;
                tree InRange;
                cout << "Enter minimum and maximum price range: ";
                cin >> minPrice >> maxPrice;
                t1.findInPrice(minPrice, maxPrice, InRange, t1.root);
                InRange.inOrder(InRange.root);
                break;
            }
            case 8: {
                node* cheapest = t1.root;
                t1.isCheapest(cheapest, t1.root);
                cheapest->data.print();
                break;
            }
            case 9: {
                node* mostExpensive = t1.root;
                t1.isMostExpensive(mostExpensive, t1.root);
                mostExpensive->data.print();
                break;
            }
            case 10: {
                string filename;
                cout << "Enter CSV filename: ";
                cin >> filename;
                t1.bulkInsertUpdate(filename);
                break;
            }
            case 11: { // Print Tree
                int printChoice;
                cout << "\nChoose Print Order:\n";
                cout << "1. In-Order\n";
                cout << "2. Pre-Order\n";
                cout << "3. Post-Order\n";
                cout << "Enter your choice: ";
                cin >> printChoice;

                switch (printChoice) {
                    case 1:
                        cout << "In-Order Traversal:\n";
                        t1.inOrder(t1.root);
                        break;
                    case 2:
                        cout << "Pre-Order Traversal:\n";
                        t1.preOrder(t1.root);
                        break;
                    case 3:
                        cout << "Post-Order Traversal:\n";
                        t1.postOrder(t1.root);
                        break;
                    default:
                        cout << "Invalid print choice!\n";
                        break;
                }
                break;
            }
            case 0: {
                running = false;
                break;
            }
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    }

    cout << "Exiting Inventory Management System.\n";
    return 0;
}
