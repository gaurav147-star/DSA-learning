#include <bits/stdc++.h>

#include "TreeNode.h"
using namespace std;

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data " << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter num of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter" << i << "th child of" << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter num of children of" << rootData << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;

    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

void printTreeLevelWise(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); i++)
        {
            pendingNodes.push(front->children[i]);
            if (i == front->children.size() - 1)
                cout << front->children[i]->data;

            else
                cout << front->children[i]->data << ",";
        }

        cout << endl;
    }
}

int numNodes(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += numNodes(root->children[i]);
    }
    return ans;
}

// recursive
int sumOfAllNodes(TreeNode<int> *root)
{
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += sumOfAllNodes(root->children[i]);
    }

    return sum;
}

// level wise

int sumOfAllNodesLevelWise(TreeNode<int> *root)
{

    int sum = 0;
    queue<TreeNode<int> *> pn;
    pn.push(root);

    while (pn.size() != 0)
    {
        TreeNode<int> *front = pn.front();
        pn.pop();
        sum = sum + front->data;

        for (int i = 0; i < front->children.size(); i++)
        {
            pn.push(front->children[i]);
        }
    }
    return sum;
}

int largestData(TreeNode<int> *root)
{
    int num = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        if (num > largestData(root->children[i]))
        {
            return num;
        }
        else
        {
            num = largestData(root->children[i]);
        }
    }
    return num;
}

int heightOfTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int max = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << endl;
        int temp = heightOfTree(root->children[i]);
        cout << temp << "--" << max << endl;
        if (temp > max)
        {
            max = temp;
        }
    }
    return max + 1;
}

void printAtLevelK(TreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << endl;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children[i], k - 1);
    }
}

int countLeafNodes(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->children.size() == 0)
    {
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += countLeafNodes(root);
    }
    return ans;
}

void preorder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
}

void postorder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        postorder(root->children[i]);
    }
    cout << root->data << " ";
}

void deleteTree(TreeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}

int main()
{
    // TreeNode<int> *root = new TreeNode<int>(1);
    // TreeNode<int> *node1 = new TreeNode<int>(2);
    // TreeNode<int> *node2 = new TreeNode<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);

    // TreeNode<int> *root = takeInput();
    TreeNode<int> *root = takeInputLevelWise();
    // printTree(root);
    // printTreeLevelWise(root);
    // preorder(root);
    postorder(root);

    // cout << numNodes(root) << endl;
    // cout << sumOfAllNodes(root) << endl;
    // cout << largestData(root) << endl;
    // cout << heightOfTree(root) << endl;
    // printAtLevelK(root, 2);
    // cout << countLeafNodes(root);

    // TODO delete tree
}
