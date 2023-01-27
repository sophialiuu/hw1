#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    //1: push operations on empty list 

    //1.1 push back into empty list 
    ULListStr list1;

	list1.push_back("1");
	list1.push_back("2");
    list1.push_back("3");
    
    std::cout << std::endl;

    std::cout << "Pushing back into an empty list1. Expecting: 1 2 3 " << std::endl;
    for(int i = 0; i < list1.size(); i++){
        std::cout << list1.get(i) << " ";
    } 

   // std::cout << std::endl;

    //1.2 push front into an empty list
    ULListStr list2;
    
    list2.push_front("1");
    list2.push_front("2");
    list2.push_front("3");
    std::cout << std::endl;


    std::cout << "Pushing front into an empty list2. Expecting: 3 2 1 " << std::endl;
    for(int i = 0; i < list2.size(); i++){
        std::cout << list2.get(i) << " ";
    } 
    std::cout << std::endl;
    //2. pop operations 

    //pop back 
    std::cout << std::endl;

    list1.pop_back();
    std::cout << "list1 after popping back 1 time:" ;
    for(int i = 0; i < list1.size(); i++){
        std::cout << list1.get(i) << " ";
    } 

  
    std::cout << std::endl;

    //pop front 
   
    std::cout << "list2 after popping front 1 time: " ;
    list2.pop_front();

    for(int i = 0; i < list2.size(); i++){
        std::cout << list2.get(i) << " ";
    } 
    std::cout << std::endl;

    //3. mixing front and back push functions 
    ULListStr list3;
    list3.push_back("A");
    list3.push_front("B");
    list3.push_back("C");

    std::cout << "list3 insertions: back, front, back of A B C: " ;

    for(int i = 0; i < list3.size(); i++){
        std::cout << list3.get(i) << " ";
    } 
    std::cout << std::endl;

    //4. mixing front and back pop functions

    list3.pop_back();
    list3.pop_front();

    std::cout << "list3 removals: back, front of BAC: " ;

    for(int i = 0; i < list3.size(); i++){
        std::cout << list3.get(i) << " ";
    } 
    std::cout << std::endl;

    //5. mixing pop and push functions 
    ULListStr list4;
    std::cout << "Push back: Adding 0 to new list 4 : ";

    list4.push_back("0");
    for(int i = 0; i < list4.size(); i++){
        std::cout << list4.get(i) << " ";
    } 
    std::cout << std::endl;
    
    std::cout << "Push front: Adding 24 to  list 4: ";
    list4.push_front("24");
    for(int i = 0; i < list4.size(); i++){
        std::cout << list4.get(i) << " ";
    } 
    std::cout << std::endl;

    std::cout << "Push front: Adding C to  list 4: ";

    list4.push_front("C");

    for(int i = 0; i < list4.size(); i++){
        std::cout << list4.get(i) << " ";
    } 
    std::cout << std::endl;

    std::cout << "back(): retrieving last item of list 4: ";
    std::cout << list4.back() << std::endl;
    std::cout << "front(): retrieving first item of list 4: ";
    std::cout << list4.front() << std::endl;


    std::cout << "Pop front: removing C from list 4: ";
    list4.pop_front();
    for(int i = 0; i < list4.size(); i++){
        std::cout << list4.get(i) << " ";
    } 
    std::cout << std::endl;

    std::cout << "filling up list with  15 values for list 5: ";
    
    ULListStr list5;
    list5.push_back("A");
    list5.push_back("B");
    list5.push_back("C");
    list5.push_back("D");
    list5.push_back("E");
    list5.push_back("F");
    list5.push_back("G");
    list5.push_back("H");
    list5.push_back("I");
    list5.push_back("J");
    list5.push_back("K");
    list5.push_back("L");
    list5.push_back("M");
    list5.push_back("N");
    list5.push_back("O");

    for(int i = 0; i < list5.size(); i++){
        std::cout << list5.get(i) << " ";
    } 
    std::cout << std::endl;

    std::cout << "set(): Replacing letter D in list 5 with a *** : ";
    list5.set(3,"***");

    for(int i = 0; i < list5.size(); i++){
        std::cout << list5.get(i) << " ";
    } 
    std::cout << std::endl;





}
