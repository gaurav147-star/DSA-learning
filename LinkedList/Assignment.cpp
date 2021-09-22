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

void eliminateDuplicate(Node *head)
{
    Node *t1 = head;
    Node *next_next;

    if (t1 == NULL)
    {
        return;
    }
    while (t1->next != NULL)
    {

        // 1 2 2 2 3 4 4
        if (t1->data == t1->next->data)
        {

            next_next = t1->next->next;
            free(t1->next);
            t1->next = next_next;
        }
        else
        {

            t1 = t1->next;
        }
    }
}

// void updateList(Node *head, int m)
// {

//     // Total nodes in the list
//     int count = getCount(head);

//     if (count != m && m < count)
//     {

//         // Count of nodes to be skipped
//         // from the beginning
//         int skip = count - m;
//         Node *prev = NULL;
//         Node *curr = head;

//         // Skip the nodes
//         while (skip > 0)
//         {
//             prev = curr;
//             curr = curr->next;
//             skip--;
//         }

//         // Change the pointers
//         prev->next = NULL;
//         Node *tempHead = head;
//         head = curr;

//         // Find the last node
//         while (curr->next != NULL)
//             curr = curr->next;

//         // Connect it to the head
//         // of the sub list
//         curr->next = tempHead;
//     }

//     // Print the updated list
//     print(head);
// }

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

void Search(Node *head, int Searchdata)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {

        if (temp->data == Searchdata)
        {
            cout << count;
        }
        count++;
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

    // cout << getCountRecursively(head) << endl;
    // //cout << getCount(head) << endl;
    // //cout << getIndexData(head, Index) << endl;
    // //head = insertNode(head, Index, data);
    // head = deleteNode(head, 3);
    // print(head);
    // //cout << getCount(head) << endl;
    // //cout << getIndexData(head, 3) << endl;

    // Search(head, 15);
    eliminateDuplicate(head);
    print(head);
}