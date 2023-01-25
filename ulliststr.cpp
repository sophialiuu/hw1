//foo
#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

//push front 
void ULListStr::push_front(const std::string& val){
  //if list is empty, no items 
  if(empty()){
    Item* temp = new Item();//make new item 
    temp->last = ARRSIZE; //set first and last pointers to end of array
    temp->first = ARRSIZE-1;
    temp->val[temp->first] = val; //set first val in new item to val
    head_ = temp; //point head and tail at temp
    tail_ = temp;
  }
  //if item is full 
  else if(head_->last - head_->first == ARRSIZE){
    Item* temp = new Item(); //make new item
    temp->last = ARRSIZE; //set first and last poitners to end up arr 
    temp->first = ARRSIZE-1; 
    temp->val[temp->first] = val; //set first val in new item to val
     
    head_->prev = temp;
    temp->next = head_;
    temp->prev = NULL; //temp's prev is null **necessary??
    head_ = temp; //point head at temp 
  }
  //if inserting into existing item that has space 
  else{
    head_->first--; //move first one space backward 
    head_->val[head_->first] = val; //set val
  }
  size_++;
}


//push back 
void ULListStr::push_back(const std::string& val){
  //if list empty, prev and next are still null 
  if(empty()){
    Item* temp = new Item(); //make new item 
    temp-> val[temp->first] = val; //put val at front of arr 
    temp->last++; //increment last 
    head_ = temp; //set head and tail to temp 
    tail_ = temp; 
  }
  //or if current tail item is already full 
  else if(tail_->last  == ARRSIZE && !empty()){ //- tail_->first
    Item* temp = new Item(); //make a new item 
    temp->val[temp->first] = val; //put val at front of new item arr 
    temp->last++; //increment last
  
    tail_->next = temp;
    temp->prev = tail_;
    temp->next = NULL; //set temp's next to NULL
    tail_ = temp; //set new tail to temp 
  }
  //otherwise insert it into existing item that has space
  else{
    tail_->val[tail_->last] = val; //add item to last space
    tail_->last++; //increment last
  }
  size_++;
}

//pop front 
void ULListStr::pop_front(){
  //if list only has one val, delete everything 
  if(size() == 1){
    delete tail_;
    tail_ = NULL;
    //delete tail_;
    head_ = NULL;
  }
  //if list has multiple items and first item needs to be deleted 
  else if(empty() == false && head_->first == ARRSIZE - 1 && head_->last == ARRSIZE && head_->next != NULL){
    Item* oldHead = head_; //save loc of old head 
    head_ = oldHead->next; //set head to old head's next item
    delete oldHead; //dealloc old tail item
    head_->prev = NULL; //set head's prev to null
  }
  else{
    head_->first++; //incr head's first ptr
  }
  size_--;
}

 
//pop back 
void ULListStr::pop_back(){
  //if list only has one val, delete everything 
  if(size() == 1){
    delete tail_;

    tail_ = NULL;
   // delete tail_;
    head_ = NULL;
  }
  else if(empty() == false && tail_->prev != NULL && tail_->first == 0 && tail_->last == 1){
    Item* oldTail = tail_; //save loc of old head 
    tail_ = oldTail->prev; //set tail to old tails prev item
    delete oldTail; //dealloc old tail item
    tail_->next = NULL; //set tail's next to null
  }
  //if deleting from existing item that has more than one val 
  else{
    tail_->last--; //decr tail's last pointer 
  }
  size_--;
}

//back 
std::string const & ULListStr::back() const{
  return tail_->val[tail_->last-1];  
}

//front 
std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}

//get val at loc 
std::string* ULListStr::getValAtLoc(size_t loc) const{
  if(loc > size()){
    return NULL;
  }
  Item* curr = head_; //set temp item to head 

  while(curr->last - curr->first <= loc){ //while not in the right item
    loc = loc - (curr->last - curr->first); //update location 
    curr = curr->next; //step to the next item 
  }
  return &curr->val[curr->first + loc]; 

}

