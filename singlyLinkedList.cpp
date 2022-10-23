#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
    ~Node()
    {
        int value = this->data;

        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << endl
             << "Memory is free for node with data " << value << endl;
    }
};
void insertAtHead(int val, Node *&Head, Node *Tail)
{
    Node *temp = new Node(val);
    if (Head == NULL)
    {
        Head = temp;
        Tail = temp;
        return;
    }
    temp->next = Head;
    Head = temp;
}

void print(Node *&Head)
{
    Node *temp;

    temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtTail(int val, Node *&Head, Node *&Tail)
{
    Node *temp = new Node(val);
    if (Head == NULL)
    {
        Head = temp;
        Tail = temp;
        return;
    }

    Tail->next = temp;
    Tail = temp;
}

void insertAtMidde(int val, int position, Node *&Head, Node *&Tail)
{
    if (position == 1)
    {
        insertAtHead(val, Head, Tail);
        return;
    }
    else
    {
        Node *iterator = Head;
        Node *temp = new Node(val);
        for (int i = 1; i < (position - 1); i++)
        {
            iterator = iterator->next;
        }

        // Little Different from Code Help with Babbar
        if (iterator == Tail)
        {
            insertAtTail(val, Head, Tail);
            return;
        }
        temp->next = iterator->next;
        iterator->next = temp;
    }
}
void deleteAtPosition(Node *&Head, Node *&Tail, int position)
{
    Node *iterator = Head;
    if (position == 1)
    {
        Head = iterator->next;
        iterator->next = NULL;
        delete iterator;
        return;
    }
    else
    {
        int cnt = 1;
        Node *prev = NULL;
        while (cnt < position)
        {
            prev = iterator;
            iterator = iterator->next;
            cnt++;
        }
        if (iterator->next == NULL)
        {
            Tail = prev;
        }
        prev->next = iterator->next;
        iterator->next = NULL;

        delete iterator;
    }
}

void deleteByValue(Node *&Head, Node *&Tail, int key)
{
    int cnt = 1;
    Node *iterator = Head;
    while (iterator != NULL)
    {
        if (iterator->data == key)
        {
            deleteAtPosition(Head, Tail, cnt);
            return;
        }
        iterator = iterator->next;
        cnt++;
    }
}

int main()
{

    Node *n = NULL;
    Node *Head = n;
    Node *Tail = n;

    insertAtTail(1, Head, Tail);
    insertAtHead(1, Head, Tail);
    print(Head);
}
