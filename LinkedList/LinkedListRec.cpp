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

int getCountRecursively(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + getCountRecursively(head->next);
    }
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

Node *insertNodeRec(Node *head, int i, int data)
{

    if (head == NULL)
        return NULL;
    if (i == 0)
    {
        Node *temp = new Node(data);
        temp->next = head;
        return temp;
    }

    if (i == 1)
    {
        Node *temp = new Node(data);
        temp->next = head->next;
        head->next = temp;
        return head;
    }
    Node *curr = insertNodeRec(head->next, i - 1, data);

    return head;
}

Node *deleteNodeRec(Node *head, int i)
{

    if (head->next == NULL)
        return NULL;

    if (i == 0)
    {
        Node *temp = head->next;
        head->next = NULL;
        delete head;
        return temp;
    }
    if (i == 1)
    {
        Node *temp = head->next;
        head->next = temp->next;
        temp->next = NULL;
        delete temp;
        return head;
    }
    Node *curr = deleteNodeRec(head->next, i - 1);

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
    // head = insertNodeRec(head, Index, data);
    // cout << getCountRecursively(head) << endl;
    // print(head);


}
