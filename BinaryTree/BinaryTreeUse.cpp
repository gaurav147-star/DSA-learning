#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
#include "Node.h"
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

int numNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + numNodes(root->left) + numNodes(root->right);
}
int countNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    int count = 0;
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        count++;
        // cout << count << endl;
        if (front->left)
        {
            pendingNodes.push(front->left);
        }
        if (front->right)
        {
            pendingNodes.push(front->right);
        }
    }
    return count;
}

bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    if (root->data == x)
    {
        return true;
    }
    bool ans = false;
    if (root->left)
    {
        bool xans = isNodePresent(root->left, x);
        if (xans)
        {
            ans = xans;
        }
    }
    if (root->right)
    {
        bool xans = isNodePresent(root->right, x);
        if (xans)
        {
            ans = xans;
        }
    }
    return ans;
}

int heightOfTree(BinaryTreeNode<int> *root)
{
    int ans = 0;
    if (root == NULL)
    {
        return 0;
    }

    int lans = heightOfTree(root->left);
    if (lans > ans)
    {
        ans = lans;
    }

    int rans = heightOfTree(root->right);
    if (rans > ans)
    {
        ans = rans;
    }

    return 1 + ans;
}

void mirrorBinary(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    BinaryTreeNode<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorBinary(root->left);
    mirrorBinary(root->right);
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
void postOrder(BinaryTreeNode<int> *root)
{

    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void inOrder(BinaryTreeNode<int> *root)
{

    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

BinaryTreeNode<int> *buildTreeHelper(int *in, int *pre, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
    {
        return NULL;
    }
    int rootData = pre[preS];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPreS = preS + 1;
    int lPreE = lInE - lInS + lPreS;
    int rPreS = lPreE + 1;
    int rPreE = preE;
    int rInS = rootIndex + 1;
    int rInE = inE;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
    return root;
}

BinaryTreeNode<int> *buildTree(int *in, int *pre, int size)
{
    return buildTreeHelper(in, pre, 0, size - 1, 0, size - 1);
}

int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int diameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int opt1 = height(root->left) + height(root->right);
    int opt2 = diameter(root->left);
    int opt3 = diameter(root->right);
    return max(opt1, max(opt2, opt3));
}

pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);
    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

pair<int, int> minAndmax(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = root->data;
        p.second = root->data;
        return p;
    }

    pair<int, int> p;
    p.first = p.second = root->data;

    if (root->left)
    {
        pair<int, int> leftAns = minAndmax(root->left);
        p.first = min(p.first, leftAns.first);
        p.second = max(p.second, leftAns.second);
    }
    if (root->right)
    {
        pair<int, int> rightAns = minAndmax(root->right);
        p.first = min(p.first, rightAns.first);
        p.second = max(p.second, rightAns.second);
    }

    return p;
}

int sumOfNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int sum = root->data;
    if (root->left)
    {
        sum += sumOfNodes(root->left);
    }
    if (root->right)
    {
        sum += sumOfNodes(root->right);
    }
    return sum;
}

bool balanced(BinaryTreeNode<int> *root)
{

    if (root == NULL)
    {
        return 0;
    }
    int lans = 1, rans = 1;
    if (root->left)
    {
        lans += heightOfTree(root->left);
    }
    if (root->right)
    {
        rans += heightOfTree(root->right);
    }
    cout << lans << " " << rans << endl;
    if (lans == rans)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

BinaryTreeNode<int> *removeLeafNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);

    return root;
}

void levelOrderTraversal(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> pNodes;
    pNodes.push(root);
    pNodes.push(NULL);

    while (pNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pNodes.front();
        pNodes.pop();

        if (front == NULL)
        {
            // pNodes.pop();
            if (pNodes.size() == 0)
            {
                return;
            }
            cout << endl;
            pNodes.push(NULL);
        }
        else
        {
            cout << front->data << " ";
            if (front->left != NULL)
            {
                pNodes.push(front->left);
            }
            if (front->right != NULL)
            {
                pNodes.push(front->right);
            }
        }
    }
}
// void printLevelOrder(BinaryTree<int> *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     queue<BinaryTree<int> *> pending;
//     pending.push(root);
//     pending.push(NULL);
//     while (pending.size() != 0)
//     {
//         BinaryTree<int> *front = pending.front();
//         pending.pop();
//         if (front != NULL)
//         {

//             cout << front->data << " ";
//             if (front->left != NULL)
//             {
//                 pending.push(front->left);
//             }
//             if (front->right != NULL)
//             {
//                 pending.push(front->right);
//             }
//         }
//         if (front == NULL)
//         {
//             if (pending.size() == 0)
//             {
//                 return;
//             }
//             cout << endl;
//             pending.push(NULL);
//         }
//     }
// }

vector<Node<int> *> createLLForEachLevel(BinaryTreeNode<int> *root)
{
    vector<Node<int> *> v;
    if (root == NULL)
    {
        v.push_back(NULL);
        return v;
    }
    queue<BinaryTreeNode<int> *> pNodes;
    pNodes.push(root);
    pNodes.push(NULL);

    Node<int> *head = NULL;
    Node<int> *tail = head;

    while (pNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pNodes.front();
        pNodes.pop();

        if (front == NULL)
        {
            tail->next = NULL;
            if (pNodes.size() == 0)
            {
                break;
            }
            cout << endl;
            pNodes.push(NULL);
            head = NULL;
            tail = NULL;
        }
        else
        {
            Node<int> *n = new Node<int>(front->data);
            if (head == NULL)
            {
                head = tail = n;
                v.push_back(head);
            }
            else
            {
                tail->next = n;
                tail = n;
            }

            cout << front->data << " ";
            if (front->left != NULL)
            {
                pNodes.push(front->left);
            }
            if (front->right != NULL)
            {
                pNodes.push(front->right);
            }
        }
    }
    return v;
}

int main()
{
    // BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
    // root->left = node1;
    // root->right = node2;
    // BinaryTreeNode<int> *root = takeInput();
    BinaryTreeNode<int> *root = takeInputLevelWise();

    // printTree(root);
    printTreeLevelWise(root);
    // cout << numNodes(root) << endl;
    // cout << countNodes(root) << endl;

    // if (isNodePresent(root, 10))
    // {
    //     cout << "true" << endl;
    // }
    // else
    // {
    //     cout << "false" << endl;
    // }

    // cout << heightOfTree(root) << endl;
    // mirrorBinary(root);
    // printTreeLevelWise(root);

    // preorder
    // node->l->r
    // preOrder(root);

    // postorder
    // l->r->node
    // postOrder(root);

    // inorder
    // l->node->r
    // inOrder(root);

    // int in[] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
    // int pre[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};
    // BinaryTreeNode<int> *root = buildTree(in, pre, 9);
    // printTreeLevelWise(root);

    // pair<int, int> p = heightDiameter(root);
    // cout << p.first << " " << p.second << endl;
    // pair<int, int> p = minAndmax(root);
    // cout << p.first << " " << p.second << endl;

    // cout << sumOfNodes(root) << endl;
    // if (balanced(root))
    // {
    //     cout << "true" << endl;
    // }
    // else
    // {
    //     cout << "false" << endl;
    // }

    // removeLeafNodes(root);
    // printTreeLevelWise(root);
    // levelOrderTraversal(root);
    createLLForEachLevel(root);
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

