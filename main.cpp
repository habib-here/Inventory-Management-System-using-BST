#include "TREE.h"

int main(void)
{
    tree t1;

    inventory item;

    t1.insert(item);
    t1.insert(2, "cable", "HDMI", 50, 400);
    t1.insert(2, "cable", "HDMI", 50, 400);
    t1.inOrder(t1.root);

    return 0;
}