// Name: Bilal Ahmed
// Registration No: 573512
// Section: D

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

    void DeleteNode(int delData)
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        if (head->data == delData)
        {
            node* temp = head;
            head = head->next;
            delete temp;

            cout << "Value deleted." << endl;
            return;
        }

        node* curr = head;

        while (curr->next != nullptr)
        {
            if (curr->next->data == delData)
            {
                node* temp = curr->next;
                curr->next = temp->next;
                delete temp;

                cout << "Value deleted." << endl;
                return;
            }

            curr = curr->next;
        }

        cout << "Value not found." << endl;
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

    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(20);
    list.AddNode(30);

    cout << "Original list:" << endl;
    list.PrintList();

    cout << endl;

    cout << "Deleting 20:" << endl;
    list.DeleteNode(20);
    list.PrintList();

    cout << endl;

    cout << "Deleting first node 10:" << endl;
    list.DeleteNode(10);
    list.PrintList();

    cout << endl;

    cout << "Deleting last node 30:" << endl;
    list.DeleteNode(30);
    list.PrintList();

    cout << endl;

    cout << "Trying to delete 99:" << endl;
    list.DeleteNode(99);
    list.PrintList();

    cout << endl;

    cout << "Deleting the only remaining node:" << endl;
    list.DeleteNode(20);
    list.PrintList();

    cout << endl;

    cout << "Trying deletion from empty list:" << endl;
    list.DeleteNode(10);

    list.ClearList();

    return 0;
}
