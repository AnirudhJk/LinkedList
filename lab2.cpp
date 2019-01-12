#include <iostream>
using namespace std;
class Node
{
  public:
    // Data
    int data;
    // Pointer to the next Node
    Node *next;
    // Construct that makes the ptr to NULL
    Node()
    {
        next = NULL;
    }
};

class LinkedList
{
    // Head + Circles inside linked with each other
  public:
    // Head -> Node type ptr
    Node *head;
    Node *tail;

    // Construct
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    // Circles inside linked with each other
    // Rules how circles will be linked
    // Insert
    int countItems()
    {
        //the counter
        int i = 1;
        Node *current = head;
        //running till the last element and incrementing the counter for every element
        while (current->next != NULL)
        {
            i++;
            current = current->next;
        }
	//returning the count value of the last element
        return i;
    }
    void insert(int value)
    {
        // If 1st Node is added
        Node *temp = new Node;
        // Insert value in the node
        temp->data = value;
        // 1st Node only.
        if (head == NULL)
        {
            head = temp;
        }
        // Any other Node only.
        else
        {
            tail->next = temp;
        }
        tail = temp;
    }

    void insertAt(int pos, int value)
    {
        //put it in the position only if the position exists in the linked list;
        if (pos <= countItems() + 1)
        {
            //
            int i = 1;
            Node *current = head;
            current = head;
            while (i < pos - 1)
            {
                i++;
                current = current->next;
            }

            // Create a node
            Node *temp = new Node;
            temp->data = value;


            // Moving ptrs like magic ! if not head
            temp->next = current->next;
            current->next = temp;

            // Update the code for 1st position
        }
        else
        {
            cout << "there isn't such a position in the Linked list" << endl;
        }
    }

    // Deletion of last element
    void delet()
    {
        // store the tail in temp
        Node *temp = tail;
        // before tail has to point to null
        Node *current = head;
        while (current->next != tail)
        {
            current = current->next;
        }
        current->next = NULL;

        // update tail

        tail = current;
        // delete temp
        delete temp;
    }

    //Deletion of a particuar element
    void deletAt(int pos)
    {
        Node *current = head;
        for (int i = 1; i < pos - 1; i++)
        {
            current = current->next;
        }
        Node *temp = current->next;
        current->next = temp->next;
    }
    // Display
    void display()
    {
        Node *current = head;
        while (current != NULL)
        {
            cout << current->data << "->";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.display();
    l1.deletAt(2);
    l1.display();
    cout<<l1.countItems()<<endl;
    l1.insertAt(2, 8);
    l1.display();
    return 0;
}