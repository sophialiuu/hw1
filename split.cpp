/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#define nullptr 0
//#include <cstdlib>

/* Add a prototype for a helper function here if you need */

//assume list is already sorted 

void split(Node*& in, Node*& odds, Node*& evens)
{
  //base case: list is empty/at end of list, return 
  if(in == nullptr){
    return;
  }
  else{
    split(in->next,odds,evens);
    //otherwise, if element is even, add it to even list 
    if(in->value % 2 == 0){
      in->next = evens; //connect previous evens link to current pointer 
      evens = in;  //update evens to even pointer 
      in = nullptr;
    }
    //otherwise, if element is odd, add it to odds list 
    else if(in->value % 2 != 0){
      in->next = odds; //connect previous odds link to current pointer 
      odds = in; //update odds to current pointer 
      in = nullptr;
    } 
  }
}

/* If you needed a helper function, write it here */
