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

    void CreateThreeNodes()
    {
        int a, b, c;

        cout << "Enter three values: ";
        cin >> a >> b >> c;

        node* first = new node;
        node* second = new node;
        node* third = new node;

        first->data = a;
        second->data = b;
        third->data = c;

        first->next = second;
        second->next = third;
        third->next = nullptr;

        head = first;
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

    cout << "Before creating list:" << endl;
    list.PrintList();

    cout << endl;

    list.CreateThreeNodes();

    cout << "After creating list:" << endl;
    list.PrintList();

    list.ClearList();

    return 0;
}
