#include <iostream>
#include <string>
#include "Book_NodeHeader.h"
using namespace std;

int main() {
   //Pre-Fill the tree with data for testing purposes
   Book_Node<string>* root_ptr = new Book_Node<string>("Aaron" ,"Shiel", "The Art of the Play", "123");
   root_ptr->AddEntry(root_ptr, "Cody", "Klunder", "Where The Calm Rest", "123");
   root_ptr->AddEntry(root_ptr, "Elias", "Herrera", "Why do we think?", "123");
   root_ptr->AddEntry(root_ptr, "Nico", "Cardona", "Is there a god?", "123");
   root_ptr->AddEntry(root_ptr, "Kelly", "Vo", "What They Teach you at Yale", "123");
   root_ptr->AddEntry(root_ptr, "Hazel", "Guillen", "What They Don't Teach you at Yale", "123");
   root_ptr->AddEntry(root_ptr, "George", "Miranda", "When did gas become so expensive?", "123");
   root_ptr->AddEntry(root_ptr, "Paymon", "Danapour", "Searches Explained", "123");
   root_ptr->AddEntry(root_ptr, "Ryan", "Shield", "How to do a kickflip", "123");
   
   int action = -1;
   cout << "Welcome to your Library Records." << endl;

   while (action != 0) {
      cout << "What would you like to do?" << endl;
      cout << "1. Search for an author." << endl;
      cout << "2. Add an Author and his book to the library." << endl;
      cout << "0. exit." << endl;

      cin >> action;
      //searching for an author by last name
      if (action == 1) {
         string name = "";
         cout << "Please enter the last name of the author with first letter uppercase: ";
         cin >> name;
         cout << endl;


         Book_Node<string>* author = root_ptr->FindAuthor(root_ptr, name);
         cout << "Author: " << author->GetName() << ", " << author->GetFirst() << endl;
         cout << "Book: " << author->GetBook() << endl;
         cout << "ISBN: " << author->GetISBN() << endl << endl;
      }
      //adding a new author and book to the tree
      if (action == 2) {
         string firstName, lastName, book, ISBN;
         cout << "What is the authors first name? ";
         cin >> firstName;
         cout << endl;
         cout << "What is the authors last name? upper case first letter: ";
         cin >> lastName;
         cout << endl;
         cout << "What is the name of the authors book? ";
         cin.ignore();
         getline(cin, book);
         cout << endl;
         cout << "What is the ISBN of the authors book? ";
         cin >> ISBN;
         cout << endl;
         root_ptr->AddEntry(root_ptr, firstName, lastName, book, ISBN);
         cout << "Entry Added." << endl;
      }

   }
  
   system("pause");
   return 0;
}