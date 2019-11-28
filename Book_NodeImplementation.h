#pragma once
template<class Item>
Book_Node<Item>* Book_Node<Item>::FindAuthor(Book_Node* root_ptr, const Item& entry) {
   if (root_ptr == NULL) {
      Book_Node *notFound = new Book_Node("Not Found");
      return notFound;
   }
   if (entry == root_ptr->GetName()) {
      return root_ptr;
   }
   else if (entry < root_ptr->GetName()) {
      return FindAuthor(root_ptr->GetLeftChild(), entry);
   }
   else if (entry > root_ptr->GetName()) {
      return FindAuthor(root_ptr->GetRightChild(), entry);
   }
}

template<class Item>
void Book_Node<Item>::AddEntry(Book_Node* root_ptr, const Item& first, const Item& name, const Item& book, const Item& ISBN) {

   if (root_ptr == NULL) {
      Book_Node* newAuthor = new Book_Node<Item>(first, name, book, ISBN);
      root_ptr = newAuthor;
      size++;
   }
   else if (name < root_ptr->GetName()) {
      if (root_ptr->GetLeftChild() != NULL)
         return AddEntry(root_ptr->GetLeftChild(), first, name, book, ISBN);
      else
         root_ptr->SetLeftChild(new Book_Node<Item>(first, name, book, ISBN));
   }
   else if (name > root_ptr->GetName()) {
      if (root_ptr->GetRightChild() != NULL)
         return AddEntry(root_ptr->GetRightChild(), first, name, book, ISBN);
      else
         root_ptr->SetRightChild(new Book_Node<Item>(first, name, book, ISBN));
   }
}

//using pre-order traversal to traverse tree
template<class Process, class BookNode>
void ApplyToAll(Process f, BookNode* node_ptr) {
   if (node_ptr != NULL) {
      f(node_ptr->GetName()); //we are able to modify the data here thanks to GetData returning a reference
      ApplyToAll(f, node_ptr->GetLeftChild());
      ApplyToAll(f, node_ptr->GetRightChild());
   }
}

template<class Node, class Data>
bool Compare(Node* node_ptr, Data data) {
   if (node_ptr->GetName() == data)
      return true;
   else
      false;
}

template<class Item>
size_t GetSize(Item* node_ptr) {
   size_t size = 0;
   if (node_ptr == NULL)
      return 0;
   else
      return
      1 + GetSize(node_ptr->GetLeftChild()) + GetSize(node_ptr->GetRightChild());
}
