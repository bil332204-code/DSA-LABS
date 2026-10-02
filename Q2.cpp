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

    int CountNodes()
    {
        int count = 0;

        node* curr = head;

        while (curr != nullptr)
        {
            count++;
            curr = curr->next;
        }

        return count;
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

    int n;

    cout << "How many values do you want to enter? ";
    cin >> n;

    if (n < 0)
    {
        cout << "Number of nodes cannot be negative." << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        int value;

        cout << "Enter value " << i + 1 << ": ";
        cin >> value;

        list.AddNode(value);
    }

    cout << endl;
    cout << "List: ";
    list.PrintList();

    cout << "Total nodes: " << list.CountNodes() << endl;

    list.ClearList();

    return 0;
}
