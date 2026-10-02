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

    void InsertAtBeginning(int addData)
    {
        node* newNode = new node;

        newNode->data = addData;
        newNode->next = head;

        head = newNode;

        cout << "Value inserted at beginning." << endl;
    }

    void AddNode(int addData)
    {
        node* newNode = new node;

        newNode->data = addData;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            node* curr = head;

            while (curr->next != nullptr)
            {
                curr = curr->next;
            }

            curr->next = newNode;
        }

        cout << "Value inserted at end." << endl;
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

        cout << "Value not found." << endl;
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

        cout << "List: ";

        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << endl;
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

    int choice;

    while (true)
    {
        cout << "\n========== LINKED LIST MENU ==========" << endl;
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Search value" << endl;
        cout << "4. Delete value" << endl;
        cout << "5. Display list" << endl;
        cout << "6. Count nodes" << endl;
        cout << "7. Display second node" << endl;
        cout << "8. Exit" << endl;
        cout << "======================================" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int value;

            cout << "Enter value: ";
            cin >> value;

            list.InsertAtBeginning(value);
        }

        else if (choice == 2)
        {
            int value;

            cout << "Enter value: ";
            cin >> value;

            list.AddNode(value);
        }

        else if (choice == 3)
        {
            int value;

            cout << "Enter value to search: ";
            cin >> value;

            list.SearchNode(value);
        }

        else if (choice == 4)
        {
            int value;

            cout << "Enter value to delete: ";
            cin >> value;

            list.DeleteNode(value);
        }

        else if (choice == 5)
        {
            list.PrintList();
        }

        else if (choice == 6)
        {
            cout << "Total nodes: " << list.CountNodes() << endl;
        }

        else if (choice == 7)
        {
            list.PrintSecondNode();
        }

        else if (choice == 8)
        {
            list.ClearList();

            cout << "Program ended." << endl;

            break;
        }

        else
        {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
