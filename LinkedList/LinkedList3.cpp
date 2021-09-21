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
        }
        else
        {

            tail->next = newnode;
            tail = tail->next;
            //or
            //tail=newnode;
        }
        cin >> data;
    }
    return head;
}

int getCount(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int getIndexData(Node *head, int Index)
{
    Node *temp = head;
    int count = 0;
    while (temp != 0)
    {

        if (count == Index)
        {
            return temp->data;
        }
        count++;
        temp = temp->next;
    }
    return 1;
}

Node *insertNode(Node *head, int Index, int data)
{
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;
    if (Index == 0)
    {
        newNode->next = head;
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

        Node *a = head;
        head = a->next;
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
    delete a;

    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = takeInput_Better();
    print(head);
    // int Index, data;
    // cin >> Index >> data;

    //cout << getCount(head) << endl;
    //cout << getIndexData(head, Index) << endl;
    //head = insertNode(head, Index, data);
    head = deleteNode(head, 3);
    print(head);
    //cout << getCount(head) << endl;
    //cout << getIndexData(head, 3) << endl;
}
