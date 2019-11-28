#pragma once
/*
File Included: Book_NodeHeader.h

Class Provided: Book_Node

   Private Member Variables:

      Item firstName;
         the first name of the author stored here

      Item lastName;
         the last name of the author stored here

      Item bookName;
         the name of the authors book stored here

      Item ISBN;
         the ISBN of the book related to author stored here

      Book_Node* left_child;
         stores a pointer to the left child of this parent

      Book_Node* right_child;
         stores a pointer to the right child of this parent

      typedef Item value_type;
         stores the data type we are using with this template

      size_t size;
         keeps track of how many elements we added to the tree

   Public  Member Functions:

   DEFAULT CONSTRUCTOR
      Book_Node(
      const Item& init_first = Item(),
      const Item& init_name = Item(),
      const Item& init_bookName = Item(),
      const Item& init_ISBN = Item(),
      Book_Node* init_left = NULL,
      Book_Node* init_right = NULL);
         this is our default constructor, if no values are passed in, sets both children to NULL,
         else, it assigns each value to the appropriate member variable

      
   Item& GetFirst();
      Pre-Condition:
      Post-Condition:

   Item& GetName();
      Pre-Condition:
      Post-Condition:

   Item& GetISBN();
      Pre-Condition:
      Post-Condition:

   Item& GetBook();
      Pre-Condition:
      Post-Condition:

   Book_Node*& GetLeftChild();
      Pre-Condition:
      Post-Condition:

   Book_Node*& GetRightChild();
      Pre-Condition:
      Post-Condition:

   void SetLeftChild(Book_Node* left);
      Pre-Condition:
      Post-Condition:

   void SetRightChild(Book_Node* right);
      Pre-Condition:
      Post-Condition:

   void AddEntry(Book_Node* root_ptr, const Item& first, const Item& name, const Item& book, const Item& ISBN);
      Pre-Condition:
      Post-Condition:

   //compares authors name to binary trees entries
   Book_Node* FindAuthor(Book_Node* root_ptr, const Item& entry);
      Pre-Condition:
      Post-Condition:
   

*/


template<class Item>
class Book_Node {
private:
   Item firstName, lastName, bookName, ISBN;
   Book_Node* left_child;
   Book_Node* right_child;

   typedef Item value_type;
   size_t size;
public:

   //default Constructor
   Book_Node(
      const Item& init_first = Item(),
      const Item& init_name = Item(),
      const Item& init_bookName = Item(),
      const Item& init_ISBN = Item(),
      Book_Node* init_left = NULL,
      Book_Node* init_right = NULL)
   {
      firstName = init_first;
      lastName = init_name;
      bookName = init_bookName;
      ISBN = init_ISBN;
      left_child = init_left;
      right_child = init_right;
   }

   Item& GetFirst() {
      return firstName;
   }

   //returns a reference to the data allowing us to modify it
   Item& GetName() {
      return lastName;
   }

   Item& GetISBN() {
      return ISBN;
   }

   Item& GetBook() {
      return bookName;
   }

   Book_Node*& GetLeftChild() {
      return left_child;
   }

   Book_Node*& GetRightChild() {
      return right_child;
   }

   void SetLeftChild(Book_Node* left) {
      left_child = left;
   }

   void SetRightChild(Book_Node* right) {
      right_child = right;
   }

   void AddEntry(Book_Node* root_ptr, const Item& first, const Item& name, const Item& book, const Item& ISBN);

   //compares authors name to binary trees entries
   Book_Node* FindAuthor(Book_Node* root_ptr, const Item& entry);
};
#include "Book_NodeImplementation.h"