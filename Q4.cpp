// Name: Bilal Ahmed
// Registration No: 573512
// Section: ______

#include <iostream>
using namespace std;

class List
{
private:
    struct node
    {
        int data;
        node* next;
    };

    node* head;

public:
    List()
    {
        head = nullptr;
    }

    void AddNode(int addData)
    {
        node* newNode = new node;

        newNode->data = addData;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        node* curr = head;

        while (curr->next != nullptr)
        {
            curr = curr->next;
        }

        curr->next = newNode;
    }

    void InsertAtBeginning(int addData)
    {
        node* newNode = new node;

        newNode->data = addData;
        newNode->next = head;

        head = newNode;
    }

    void PrintList()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        node* curr = head;

        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << endl;
    }

    void ClearList()
    {
        node* curr = head;

        while (curr != nullptr)
        {
            node* temp = curr;
            curr = curr->next;
            delete temp;
        }

        head = nullptr;
    }
};

int main()
{
    List list;

    cout << "Starting list:" << endl;
    list.PrintList();

    cout << endl;

    list.InsertAtBeginning(20);

    cout << "After inserting 20 at beginning:" << endl;
    list.PrintList();

    cout << endl;

    list.InsertAtBeginning(10);

    cout << "After inserting 10 at beginning:" << endl;
    list.PrintList();

    cout << endl;

    list.AddNode(30);

    cout << "After adding 30 at end:" << endl;
    list.PrintList();

    list.ClearList();

    return 0;
}
