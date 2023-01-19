/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <vector>
#include <cstdlib>
#include <iostream>


int main(int argc, char* argv[])
{
Node * node = new Node(1,NULL);
    node->next = new Node(2,NULL);
    node->next->next = new Node(5,NULL);
    node->next->next->next = new Node(4,NULL);
    node->next->next->next->next = new Node(5,NULL);

    Node * odds = NULL;
    Node * evens = NULL;

    Node * firstEven = evens;
    Node * firstOdd = odds;

    
    split(node, odds, evens);

    std::cout << "odd list after splitting input list: ";
    Node * temp = odds;
    while(temp)
    {
        std::cout << temp->value << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

    std::cout << "even list after splitting input list: ";
    temp = evens;
    while(temp)
    {
        std::cout << temp->value << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

    while(evens)
    {
        Node * temp = evens->next;
        delete evens;
        evens = temp;
    }
    std::cout << std::endl;
    while(odds)
    {
        Node * temp = odds->next;
        delete odds;
        odds = temp;
    }
    std::cout << std::endl;


    return 0;


}
