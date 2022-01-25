#include <bits/stdc++.h>
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
class Pair
{
public:
    Node *head;
    Node *tail;
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

// Node *palindromeLL(Node *head)
// {
// }

Node *midPointLL(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *mergeTwoSortedLL(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *tail = NULL;
    if (head1->data <= head2->data)
    {
        head = head1;
        tail = head1;
        head1 = head1->next;
    }
    else
    {
        head = head2;
        tail = head2;
        head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            tail->next = head1;
            tail = tail->next;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            tail = tail->next;
            head2 = head2->next;
        }
    }
    if (head1 == NULL)
    {
        tail->next = head2;
    }
    if (head2 == NULL)
    {
        tail->next = head1;
    }
    return head;
}

// Node *mergeSortLL(Node *head)
// {
// }

Node *reverseLLRecursively(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *smallans = reverseLLRecursively(head->next);
    Node *temp = smallans;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return smallans;
}

Pair reverseLLRecursively_2(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallAns = reverseLLRecursively_2(head->next);
    smallAns.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}

Node *reverseLL_Better(Node *head)
{
    return reverseLLRecursively_2(head).head;
}

Node *reverseLLRecursively_3(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *smallans = reverseLLRecursively(head->next);
    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;
    return smallans;
}

Node *reverseLLIteratively(Node *head)
{
    Node *current = head;
    Node *n = NULL;
    Node *prev = NULL;
    // current->next = prev;
    while (current != NULL)
    {
        n = current->next;
        current->next = prev;
        prev = current;
        current = n;
    }
    return prev;
}

int getNodeIndexData(Node *head, int data)
{
    Node *temp = head;

    if (temp->next == NULL)
    {
        return -1;
    }

    if (temp->data == data)
    {
        return 0;
    }

    int count = getNodeIndexData(temp->next, data);

    if (count != -1)
    {
        return ++count;
    }
    else
    {
        return -1;
    }

    return count;
}

Node *evenAfterOddLL(Node *head)
{
    Node *oddH = NULL;
    Node *oddT = NULL;
    Node *evenH = NULL;
    Node *evenT = NULL;
    while (head != NULL)
    {
        if (head->data % 2 == 0)
        {
            if (evenH == NULL)
            {
                evenH = head;
                evenT = head;
            }
            else
            {
                evenT->next = head;
                evenT = evenT->next;
            }
        }
        else
        {
            if (oddH == NULL)
            {
                oddH = head;
                oddT = head;
            }
            else
            {
                oddT->next = head;
                oddT = oddT->next;
            }
        }
        head = head->next;
    }
    if (oddT == NULL)
    {
        return evenH;
    }
    if (evenH == NULL)
    {
        return oddH;
    }
    oddT->next = evenH;
    return oddH;
}

Node *deleteEveryNNodes(Node *head, int M, int N)
{
    Node *temp = head;
    while (temp != NULL)
    {
        for (int i = 0; i < M - 1; i++)
        {
            if (temp != NULL)
            {
                temp = temp->next;
            }
        }
        Node *p = temp;
        if (temp == NULL)
        {
            return head;
        }
        for (int j = 0; j < N; j++)
        {

            if (temp != NULL && temp->next != NULL && p->next != NULL)
            {
                p = temp->next;
                temp->next = p->next;
                delete (p);
            }
        }
        temp = temp->next;
    }
    return head;
}

Node *swapTwoNodes(Node *head, int M, int N)
{
    Node *p = head, *q = head;

    for (int index = 0; index < M; index++)
    {
        p = p->next;
    }
    for (int index = 0; index < N; index++)
    {
        q = q->next;
    }

    int x = p->data;
    p->data = q->data;
    q->data = x;

    return head;
}

Node *kReverse(Node *head, int n)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *current = head;
    Node *temp = head;
    Node *prev = NULL;
    int i = 0;
    while (current != NULL && i < n)
    {
        temp = temp->next;
        current->next = prev;
        prev = current;
        current = temp;
        i++;
    }
    if (temp != NULL)
    {
        head->next = kReverse(temp, n);
    }
    return prev;
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
    // Node *mid = midPointLL(head);
    // cout << mid->data << endl;

    // Node *head1 = takeInput_Better();
    // Node *head2 = takeInput_Better();
    // print(head1);
    // print(head2);
    // Node *head = mergeTwoSortedLL(head1, head2);
    // print(head);
    // head = reverseLLRecursively(head);
    // head = reverseLLRecursively_3(head);
    // head = reverseLLIteratively(head);
    // print(head);

    // int data;
    // cin >> data;
    // cout << getNodeIndexData(head, data) << endl;

    // head = evenAfterOddLL(head);
    // print(head);

    // int M, N;
    // cin >> M >> N;
    // head = deleteEveryNNodes(head, M, N);
    // print(head);

    // head = swapTwoNodes(head, 3, 4);
    // print(head);

    int n;
    cin >> n;
    head = kReverse(head, n);
    print(head);
}
