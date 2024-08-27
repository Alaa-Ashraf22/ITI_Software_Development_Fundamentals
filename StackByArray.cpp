#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int _data)
    {
        data = _data;
        prev = next = NULL;
    }
};


class StackByLinkedList
{
    Node* top;
public:
    StackByLinkedList()
    {
        top = NULL;
    }

    void Push(int data)
    {
        Node* newNode = new Node(data);
        if (top == NULL)
        {
            top = newNode;
        }
        else
        {
            newNode->prev = top;
            top = newNode;
        }
        cout << data << " pushed to stack" << endl;
    }

    void Pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            Node* temp = top;
            top = top->prev;
            cout << temp->data << " popped from stack" << endl;
            delete temp;
        }
    }

    void Peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Top element is " << top->data << endl;
        }
    }

    void Display()
    {
        if (top == NULL)
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << "Stack elements: ";
            Node* temp = top;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->prev;
            }
            cout << endl;
        }
    }

    ~StackByLinkedList()
    {
        while (top != NULL)
        {
            Node* temp = top;
            top = top->prev;
            delete temp;
        }
    }
};


class LinkedList
{
public:
    Node* Head;
    Node* Tail;

    LinkedList()
    {
        Head = Tail = NULL;
    }

    void Add(int data)
    {
        Node* newNode = new Node(data);
        if (Head == NULL && Tail == NULL)
        {
            Head = Tail = newNode;
        }
        else
        {
            newNode->prev = Tail;
            Tail->next = newNode;
            Tail = newNode;
        }
    }

    void Display()
    {
        Node* current = Head;
        while (current != NULL)
        {
            cout << current->data << "\t";
            current = current->next;
        }
        cout << endl;
    }

    void InsertBefore(int item, int newValue)
    {
        Node* newNode = new Node(newValue);
        Node* current = Head;

        if (Head != NULL && Head->data == item)
        {
            newNode->next = Head;
            Head->prev = newNode;
            Head = newNode;
            return;
        }

        while (current != NULL && current->next != NULL && current->next->data != item)
        {
            current = current->next;
        }

        if (current != NULL && current->next != NULL)
        {
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }
    }

    void ReverseList()
    {
        Node* current = Head;
        Node* prev = NULL;
        Node* next = NULL;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            current->prev = next;
            prev = current;
            current = next;
        }
        Head = prev;
    }

    void GetLength()
    {
        int counter = 0;
        Node* current = Head;
        while (current != NULL)
        {
            counter++;
            current = current->next;
        }
        cout << "Length of list: " << counter << endl;
    }

    int GetValue(int index)
    {
        Node* current = Head;
        int v = 0;
        while (current != NULL)
        {
            if (v == index)
                return current->data;
            v++;
            current = current->next;
        }
        return -1;
    }

    ~LinkedList()
    {
        Node* current = Head;
        while (current != NULL)
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main()
{
    StackByLinkedList stack;
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Display();
    stack.Peek();
    cout << "\n*************************************************\n";
    stack.Pop();
    stack.Display();

    LinkedList list;
    list.Add(1);
    list.Add(2);
    list.Add(3);
    list.Display();
    list.InsertBefore(2, 10);
    list.Display();
    list.ReverseList();
    list.Display();
    list.GetLength();
    cout << "Value at index 1: " << list.GetValue(1) << endl;

    return 0;
}
