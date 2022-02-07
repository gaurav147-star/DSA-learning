#include <bits/stdc++.h>
#include "BSTree.h"
#include "Node.h"
class Pair
{
public:
    Node<int> *head;
    Node<int> *tail;
};
using namespace std;

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter left child of " << front->data << endl;
        int leftChild;
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChild);
            front->left = child;
            pendingNodes.push(child);
        }

        cout << "Enter right child of " << front->data << endl;
        int rightChild;
        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChild);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ": ";
    if (root->left != NULL)
    {
        cout << "L " << root->left->data << " ";
    }
    if (root->right != NULL)
    {
        cout << "R " << root->right->data << " ";
    }
    cout << endl;

    printTree(root->left);
    printTree(root->right);
}

void printTreeLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        if (front->left)
        {
            pendingNodes.push(front->left);
            cout << "L " << front->left->data << " ";
        }
        if (front->right)
        {
            pendingNodes.push(front->right);
            cout << "R " << front->right->data << " ";
        }
        cout << endl;
    }
}

bool search(BinaryTreeNode<int> *root, int val)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == val)
    {
        return true;
    }
    bool ans = false;

    if (val > root->data)
    {
        bool xans = search(root->right, val);
        if (xans == true)
        {
            ans = xans;
        }
    }
    if (val < root->data)
    {
        bool xans = search(root->left, val);
        if (xans == true)
        {
            ans = xans;
        }
    }
    return ans;
}

void printElementsInRange(BinaryTreeNode<int> *root, int x, int y)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data > x)
    {
        printElementsInRange(root->left, x, y);
    }
    if (x <= root->data && root->data <= y)
    {
        cout << root->data << " ";
    }

    printElementsInRange(root->right, x, y);
}

int maximum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}
int minimum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}
bool isBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    bool output = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
    return output;
}

class IsBSTReturn
{
public:
    bool isBST;
    int minimum;
    int maximum;
};

IsBSTReturn isBST2(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        IsBSTReturn output;
        output.isBST = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        return output;
    }
    IsBSTReturn leftOutput = isBST2(root->left);
    IsBSTReturn righttOutput = isBST2(root->right);
    int minimum = min(root->data, min(leftOutput.minimum, righttOutput.minimum));
    int maximum = max(root->data, max(leftOutput.maximum, righttOutput.maximum));
    bool isBSTFinal = (root->data > leftOutput.maximum) && (root->data <= righttOutput.minimum) && leftOutput.isBST && righttOutput.isBST;
    IsBSTReturn output;
    output.isBST = isBSTFinal;
    output.minimum = minimum;
    output.maximum = maximum;
    return output;
}

bool isBST3(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data < min || root->data > max)
    {
        return false;
    }
    bool isLeftOk = isBST3(root->left, min, root->data - 1);
    bool isRightOk = isBST3(root->right, root->data, max);
    return isLeftOk && isRightOk;
}

BinaryTreeNode<int> *constructBSTfromSortedArray(int a[], int s, int e)
{
    // cout << s << " " << e << endl;
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;

    int rootData = a[mid];
    // cout << rootData << endl;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    root->left = constructBSTfromSortedArray(a, s, mid - 1);
    root->right = constructBSTfromSortedArray(a, mid + 1, e);
    return root;
}
void preOrder(BinaryTreeNode<int> *root)
{

    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

Pair BST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        Pair ans;
        ans.head = NULL;
        ans.tail = NULL;
        return ans;
    }

    Node<int> *node = new Node<int>(root->data);

    Pair leftans = BST(root->left);
    Pair rightans = BST(root->right);

    Pair ans;

    if (leftans.head == NULL && rightans.head == NULL)
    {

        ans.head = node;
        ans.tail = node;
    }

    else if (!leftans.head && rightans.head)
    {
        ans.head = node;
        node->next = rightans.head;
        ans.tail = rightans.tail;
    }
    else if (leftans.head && rightans.head == NULL)
    {
        ans.head = leftans.head;
        leftans.tail->next = node;
        ans.tail = node;
    }
    else
    {
        ans.head = leftans.head;
        leftans.tail->next = node;
        node->next = rightans.head;
        ans.tail = rightans.tail;
    }

    return ans;
}
Node<int> *constructBST(BinaryTreeNode<int> *root)
{
    return BST(root).head;
}
Node<int> *constructBSTtoLL2(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        Node<int> *temp = new Node<int>(root->data);
        return temp;
    }
    Node<int> *temp = new Node<int>(root->data);
    Node<int> *leftans = constructBSTtoLL2(root->left);
    Node<int> *rightans = constructBSTtoLL2(root->right);
    if (leftans != NULL)
    {
        Node<int> *t = leftans;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = temp;
    }
    temp->next = rightans;
    if (leftans == NULL)
    {
        return temp;
    }
    return leftans;
}
void print(Node<int> *head)
{
    Node<int> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    // BinaryTreeNode<int> *root = takeInput();
    BinaryTreeNode<int> *root = takeInputLevelWise();

    // printTree(root);
    printTreeLevelWise(root);

    /* if (search(root, 12))
     {
         cout << "true" << endl;
     }
     else
     {
         cout << "false" << endl;
     }
     */
    // printElementsInRange(root, 6, 10);
    // if (isBST(root))
    // {
    //     cout << "true" << endl;
    // }
    // else
    // {
    //     cout << "false" << endl;
    // }

    // IsBSTReturn p = isBST2(root);
    // if (p.isBST)
    // {
    //     cout << "true" << endl;
    // }
    // else
    // {
    //     cout << "false" << endl;
    // }
    // if (isBST3(root))
    // {
    //     cout << "true" << endl;
    // }
    // else
    // {
    //     cout << "false" << endl;
    // }

    // int n;
    // cin >> n;
    // int a[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }

    // cout << endl;
    // cout << n << endl;

    // BinaryTreeNode<int> *root = constructBSTfromSortedArray(a, 0, n - 1);
    // preOrder(root);
    Node<int> *head = constructBST(root);
    print(head);
}
