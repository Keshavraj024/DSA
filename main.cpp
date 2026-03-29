#include <algorithm>
#include <iostream>

#include <ranges>
#include <vector>

#include "LinkedList/LinkedList.h"

int main()
{
    SinglyLinkedList linkedList;

    linkedList.appendNode(new Node(1, 10));
    linkedList.appendNode(new Node(2, 20));
    linkedList.appendNode(new Node(3, 30));
    linkedList.appendNode(new Node(4, 40));

    linkedList.prependNode(new Node(5, 50));

    linkedList.insertNodeAfter(5, new Node(6, 60));

    linkedList.deleteNode(5);

    linkedList.printLinkedList();

    return 0;
}
