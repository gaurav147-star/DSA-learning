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
            // or
            // tail=newnode;
        }
        cin >> data;
    }
    return head;
}

// count the node of the linked list
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

// get the data of the particular index
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
        // 1st option
        //  Node *a = temp->next;
        //  temp->next = newNode;
        //  newNode->next = a;

        // 2nd option
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

// Eliminate the duplicate in the linked list
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

// Append last n node to first
Node *updateList(Node *head, int m)
{

    // Total nodes in the list
    int length = getCount(head);

    if (length != m && m < length)
    {

        // Count of nodes to be skipped
        // from the beginning
        int skip = length - m;
        Node *prev = NULL;
        Node *curr = head;

        // Skip the nodes
        while (skip > 0)
        {
            prev = curr;
            curr = curr->next;
            skip--;
        }

        // Change the pointers
        prev->next = NULL;
        Node *tempHead = head;
        head = curr;

        // Find the last node
        while (curr->next != NULL)
            curr = curr->next;

        // Connect it to the head
        // of the sub list
        curr->next = tempHead;
    }

    // Print the updated list
    return head;
}
Node *insertInMiddle(Node *head, int x)
{
    // Cpde here
    Node *newnode = new Node(x);
    if (head == NULL)
    {
        head = newnode;
        return head;
    }
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        // cout << temp->data << " ";
        temp = temp->next;
    }
    // cout << endl;
    // cout << len << endl;
    int count;
    if (len % 2 == 0)
    {
        count = len / 2;
    }
    else
    {
        count = (len + 1) / 2;
    }
    // cout << count << endl;
    temp = head;
    while (count-- > 1)
    {

        temp = temp->next;
        // cout << temp->data << " ";
    }

    newnode->next = temp->next;
    temp->next = newnode;

    return head;
}

// Print the linked list
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

// Search node in a linked list
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

// reverse the linked list
Node *reverse(Node *head)
{

    if (!head)
        return NULL;
    Node *current = head;
    Node *next = NULL;
    Node *prev = NULL;

    /*reverse first k nodes of the linked list */
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    return prev;
}

Node *removeNthFromEnd(Node *head, int n)
{
    Node *temp = head;
    Node *mhead = temp;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    // cout<<count<<endl;
    temp = head;
    Node *prev = nullptr;
    count = count - n;
    if (count == 0)
    {
        return head->next;
    }
    while (count > 0)
    {
        prev = temp;
        temp = temp->next;
        count--;
    }
    // cout<<temp->val<<endl;
    if (temp->next == nullptr)
    {
        prev->next = nullptr;
    }
    else
    {
        prev->next = temp->next;
    }
    return mhead;
}

Node *mid(Node *head)

{

    Node *fast = head->next;
    Node *slow = head;

    if (head == NULL || head->next == NULL)
        return head;
    else
    {

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
    }
    return slow;
}
bool check_palindrome(Node *head)

{
    Node *m = mid(head);
    
    Node *r = reverse(m);

    while (head != NULL)
    {
        if (head->data != r->data)
        {
            return false;
        }
        else
        {
            head = head->next;
            r = r->next;
        }
    }
    return true;
}
int main()
{
    Node *head = takeInput_Better();
    print(head);
    // int Index, data;
    // cin >> Index >> data;

    // cout << getCountRecursively(head) << endl;
    // cout << getCount(head) << endl;
    // cout << getIndexData(head, Index) << endl;
    // head = insertNode(head, Index, data);
    // head = deleteNode(head, 3);
    // print(head);
    // //cout << getCount(head) << endl;
    // //cout << getIndexData(head, 3) << endl;

    // Search(head, 15);
    // eliminateDuplicate(head);
    // head = insertInMiddle(head, 3);
    // int n;
    // cin >> n;
    // head = removeNthFromEnd(head, n);
    // print(head);
    cout << check_palindrome(head) << endl;
}
