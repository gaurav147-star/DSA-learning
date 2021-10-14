#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
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
            tail->next = NULL;
            tail->prev = NULL;
        }

        else
        {

            tail->next = newnode;
            newnode->prev = tail;
            tail = tail->next;
            //or
            //tail=newnode;
        }
        cin >> data;
        // newnode->prev = newnode;
    }
    return head;
}

//insert new in the doubly linked list
Node *insertNode(Node *head, int Index, int data)
{
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;
    if (Index == 0)
    {
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
        return head;
    }

    while (temp != NULL && count < Index - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        //1st option
        // Node *a = temp->next;
        // temp->next = newNode;
        // newNode->next = a;

        //2nd option
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }
    return head;
}

//delete node from any index
Node *deleteNode(Node *head, int Index)
{
    Node *temp = head;

    int count = 0;
    if (Index == 0)
    {

        Node *a = head;
        head = a->next;
        head->prev = NULL;
        delete a;
        return head;
    }
    while (count < Index - 1)
    {
        temp = temp->next;
        count++;
    }
    Node *a = temp->next;
    temp->next = a->next;
    a->next->prev = temp;
    delete a;

    return head;
}
//Print the linked list
void print(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        cout << head->data << " ";
        temp = head;
        head = head->next;
    }
    cout << endl;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    Node *head = takeInput_Better();
    print(head);
    // int Index, data;
    // cin >> Index >> data;
    // head = insertNode(head, Index, data);
    head = deleteNode(head, 2);
    print(head);
}
