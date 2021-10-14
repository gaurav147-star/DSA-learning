#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node *takeInput_Better()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {

            head = newnode;

            tail = newnode;
            tail->next = tail;
        }

        else
        {

            newnode->next = head;
            tail->next = newnode;
            tail = tail->next;

            //or
            //tail=newnode;
        }
        cin >> data;
        // newnode->prev = newnode;
    }
    return head;
}
Node *insertNode(Node *head, int Index, int data)
{
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;
    if (Index == 0)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;

        newNode->next = head;
        head = newNode;
        return head;
    }

    while (temp->next != head && count < Index - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next != head)
    {
        //1st option
        // Node *a = temp->next;
        // temp->next = newNode;
        // newNode->next = a;

        //2nd option
        // temp->next = newNode;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

Node *deleteNode(Node *head, int Index)
{
    Node *temp = head;

    int count = 0;
    if (Index == 0)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        Node *a = head;
        head = a->next;
        temp->next = a->next;
        delete a;
        return head;
    }
    while (temp->next != head && count < Index - 1)
    {
        temp = temp->next;
        count++;
    }
    Node *a = temp->next;
    temp->next = a->next;
    delete a;

    return head;
}

//Print the linked list
void print(Node *head)
{
    Node *temp;
    if (head == NULL)
    {
        return;
    }
    temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;

    } while (temp != head);
    cout << endl;
}

int main()
{
    Node *head = takeInput_Better();
    print(head);

    // int Index, data;
    // cin >> Index >> data;

    //head = insertNode(head, Index, data);
    head = deleteNode(head, 2);
    print(head);
}
