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

    void SearchNode(int searchData)
    {
        node* curr = head;
        int position = 1;

        while (curr != nullptr)
        {
            if (curr->data == searchData)
            {
                cout << "Value found at position " << position << endl;
                return;
            }

            curr = curr->next;
            position++;
        }

        cout << "Value not found" << endl;
    }

    void PrintSecondNode()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        if (head->next == nullptr)
        {
            cout << "Second node does not exist." << endl;
            return;
        }

        cout << "Second node: " << head->next->data << endl;
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

    cout << "Checking empty list:" << endl;
    list.PrintSecondNode();

    cout << endl;

    list.AddNode(10);

    cout << "After adding one node:" << endl;
    list.PrintList();
    list.PrintSecondNode();

    list.AddNode(20);
    list.AddNode(30);
    list.AddNode(20);

    cout << endl;

    cout << "List: ";
    list.PrintList();

    cout << endl;

    cout << "Searching 20:" << endl;
    list.SearchNode(20);

    cout << endl;

    cout << "Searching 99:" << endl;
    list.SearchNode(99);

    cout << endl;

    list.PrintSecondNode();

    list.ClearList();

    return 0;
}
