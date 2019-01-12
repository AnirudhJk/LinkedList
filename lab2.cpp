#include <iostream>

using namespace std;

class Node
{
 public:
 int data;
 Node * next; // Pointer to the next Node
 // Construct that makes the ptr to NULL
 Node()
 {
  next = NULL;
 }
};

 class LinkedList
 {
  public:
  Node * head; // Head & tail Node type ptr
  Node * tail;

  LinkedList() // The constructor
  {
   head = NULL;
   tail = NULL;
  } 

  //Insertion
  void insert(int value)
  {
   Node * temp = new Node; // First new Node is created 
   temp->data = value; // Insert value in the node
 
   if(head == NULL) //If new Node is 1st Node
   {
    head = temp;
   }
 
   else //For any other Node only
   {
    tail->next = temp;
   }
   tail = temp;
  }  

  //Insertion at some position
  void insertAt(int pos, int value)
  { 
   if (countItems()<(pos-1)) //Required condition
   {
    cout<<"Linked List does not have required number of elements"<<endl;
   }
 
   else
   {
    // Reach the location before the position
    Node * current = head;
    int i = 1;
 
    while (i < pos-1)
    {
     i++;
     current = current->next;
    } 

    // Create a node
    Node * temp = new Node;
    temp -> data = value;
   	
    // Moving pointers if not head
    temp->next = current->next;
    current->next = temp;
   }
  }  
	
  // Deletion of last element
  void del()
  {
   Node * temp = tail; // Storing the tail in temp
   Node * current = head; // Before tail has to point to null

   while(current->next != tail)
   {
    current = current->next;
   }
   current->next = NULL; 
   tail = current; // Update tail
   delete temp; // Deleting temp
  }

  // Deletion at some position
  void deleteAt(int pos)
  {
  // Required condition
  if(countItems()< pos)
  {
   cout<<"Element does not exist"<<endl;
  }
 
  else
  {
   if(pos == 1)
   {
    Node * current = head;
    head = current->next;
    delete current;
   }
   else
   {
    Node * current = head; // Finding the element to delete
    int i =1;
   
    while (i < pos)
    {
     i++;
     current = current->next;
    }
    // Shifting pointer to the preceding Node and finding that element 
    Node * current1 = head;
    int j =1;
   
    while (j < pos-1)
    {
     j++;
     current1 = current1->next;
    }
    current1->next = current->next; // Shifting
    delete current; //delete current
   }
  }
 }

 // Counting the items
 int countItems()
 {
  int i = 1;
  // before tail has to point to null
  Node * current = head;

  while(current->next != NULL)
  {
   current = current->next;
   i++;
  } 
  return i;
 }

 // Displaying the ouptut
 void display()
 {
  Node * current = head;

  while(current != NULL)
  {
   cout << current->data << "->";
   current = current->next;
  }
  cout <<"NULL"<< endl;
 }
};
	
int main() 
{
 LinkedList l1;
 l1.insert(1);
 l1.insert(2);
 l1.insert(3);
 l1.display();
 l1.del();
 l1.display();
 
 int numIns, posIns;
 cout <<"Enter the position at which number has to be inserted" <<endl;
 cin >>posIns;
 cout <<"Enter the number to be inserted" <<endl;
 cin >>numIns;
 l1.insertAt(posIns, numIns);
 l1.display();

 cout<<l1.countItems()<<endl;
 int posDel;
 cout <<"Enter the position at which number has to be deleted" <<endl;
 cin >>posDel;
 l1.deleteAt(posDel);
 l1.display();

 cout<<l1.countItems()<<endl;
 return 0;
}
