

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template <class T>
class node
{
public:
    T data;
    node<T> *left;
    node<T> *right;
    int CountLeft;
    int CountRight;
    int height;
    int DupCount;

    node()
    {
        data = 0;
        left = NULL;
        right = NULL;
        CountLeft = 0;
        CountRight = 0;
        height = 0;
        DupCount = 0;
    }
    node(int d)
    {
        this->data = d;
        left = NULL;
        right = NULL;
        CountLeft = 0;
        CountRight = 0;
        height = 1;
        DupCount = 1;
    }
};
template <class T>
class AvlTree
{
public:
   // node<T>* root;
    AvlTree();
    int height(node<T> *n);
    node<T> *insert(node<T> *n, T);
    node<T> *insertHelper(node<T> *n, T);

    node<T> *RotateLeftLeft(node<T> *n);
    node<T> *RotateLeftRight(node<T> *n);
    node<T> *RotateRightLeft(node<T> *n);
    node<T> *RotateRightRight(node<T> *n);

    node<T> *FindHeight(node<T> *n);
    int HeightDiff(node<T> *x)
    {
        return (height(x->left) - height(x->right));
    }
    void inorder(node<T> *n);

    node<T> *LeftMax(node<T> *n);
    node<T> *RightMin(node<T> *n);

    node<T> *DeleteNode(node<T> *n, T);
    node<T> *DeleteNodeHelper(node<T> *n, T);

    T max(T, T);
    T kth_smallest_util(node<T> *n, int, int);
    T kth_smallest(node<T> *, int);
    T KthLargestHelper(node<T> *n, int, int);
    T KthLargest(node<T> *n, int);

    bool contains(node<T> *n, int);

    T closest_util(node<T> *n, T, int);
    T closest(node<T> *, T);

    int InRange(node<T> *n, T, T);
    int SmHelper(node<T> *n, T, int);
    int SmForRange(node<T> *n, T);
};
template <class T>
AvlTree<T>::AvlTree() {
	//root = NULL;
}
template <class T>
T AvlTree<T>::max(T a, T b)
{
    return (a > b) ? a : b;
}
template <class T>
int AvlTree<T>::height(node<T> *x)
{
    if (x == NULL)
        return 0;
    return x->height;
}
template <class T>
node<T> *AvlTree<T>::FindHeight(node<T> *x)
{

    int heightdiff = HeightDiff(x);
    if (heightdiff < -1)
    {

        int rheightdiff = HeightDiff(x->right);

        if (rheightdiff > 0)
            x = RotateRightLeft(x);
        else
        {
            x = RotateRightRight(x);
        }
    }
    else if (heightdiff > 1)
    {
        int lheightdiff = HeightDiff(x->left);
        if (lheightdiff > 0)
        {
            x = RotateLeftLeft(x);
        }
        else
            x = RotateLeftRight(x);
    }
    return x;
}
template <class T>
node<T> *AvlTree<T>::RotateLeftLeft(node<T> *n)
{
    node<T> *p;
    p = n->left;
    n->left = p->right;
    n->CountLeft = ((p->CountRight));
    p->right = n;
    p->CountRight = ((n->CountLeft) + (n->CountRight)) + 1;

    n->height = max(height(n->left), height(n->right)) + 1;
    p->height = max(height(p->left), height(p->right)) + 1;
    return p;
}
template <class T>
node<T> *AvlTree<T>::RotateRightRight(node<T> *n)
{
    node<T> *p;
    p = n->right;
    n->CountRight = ((p->CountLeft));
    n->right = p->left;
    p->CountLeft = ((n->CountLeft) + (n->CountRight)) + 1;
    p->left = n;

    n->height = max(height(n->left), height(n->right)) + 1;
    p->height = max(height(p->left), height(p->right)) + 1;
    return p;
}
template <class T>
node<T> *AvlTree<T>::RotateLeftRight(node<T> *n)
{
    node<T> *p;
    p = n->left;
    n->left = RotateRightRight(p);
    n = RotateLeftLeft(n);
    return n;
}
template <class T>
node<T> *AvlTree<T>::RotateRightLeft(node<T> *n)
{
    node<T> *p;
    p = n->right;
    n->right = RotateLeftLeft(p);
    n = RotateRightRight(n);
    return n;
}
template <class T>
node<T> *AvlTree<T>::insertHelper(node<T> *root, T val)
{
    if (root == NULL)
    {
        root = new node<T>(val);
        return root;
    }
    if (val == root->data)
    {
        root->DupCount++;
        return root;
    }
    else
    {
        if (val < root->data)
        {
            root->CountLeft++;
            root->left = insertHelper(root->left, val);
            root->height = max(height(root->left), height(root->right)) + 1;
            root = FindHeight(root);
        }
        else if (val > root->data)
        {
            root->CountRight++;
            root->right = insertHelper(root->right, val);
            root->height = max(height(root->left), height(root->right)) + 1;
            root = FindHeight(root);
        }
    }

    return root;
}
template <class T>
node<T> *AvlTree<T>::insert(node<T> *root, T val)
{
    return insertHelper(root, val);
}
template <class T>
void AvlTree<T>::inorder(node<T> *n)
{
    if (n != NULL)
    {
        inorder(n->left);
        int c = n->DupCount;
        while (c--)
          {//n->DupCount--; 
           cout << n->data << " ";}
        inorder(n->right);
    }
    else
        return;
}
template <class T>
node<T> *AvlTree<T>::LeftMax(node<T> *root)
{
    if (root->right == NULL)
        return root;
    return LeftMax(root->right);
}
template <class T>
node<T> *AvlTree<T>::RightMin(node<T> *root)
{
    if (root->left == NULL)
        return root;
    return RightMin(root->left);
}
template <class T>
node<T> *AvlTree<T>::DeleteNodeHelper(node<T> *root, T val)
{
    if (root == NULL)
        return root;
    if (val == root->data)
    {
        if (root->DupCount > 1)
        {
            root->DupCount--;
            return root;
        }
        if (root->left == NULL && root->right == NULL)
        {
            node<T> *child = root;
            root = NULL;
            free(child);
        }
        else if (root->left == NULL)
        {
            node<T> *child = root->right;
            *root = *child;
            free(child);
        }
        else if (root->right == NULL)
        {
            node<T> *child = root->left;
            *root = *child;
            free(child);
        }
        else
        {
            node<T> *child = RightMin(root->right);
            root->data = child->data;
            root->CountRight--;
            root->right = DeleteNodeHelper(root->right, child->data);
        }
    }
    else if (val < root->data)
    {
        root->CountLeft--;
        root->left = DeleteNodeHelper(root->left, val);
    }
    else
    {
        root->CountRight--;
        root->right = DeleteNodeHelper(root->right, val);
    }
    if (root == NULL)
        return root;
    root = FindHeight(root);
    return root;
}
template <class T>
node<T> *AvlTree<T>::DeleteNode(node<T> *root, T val)
{
    if (!contains(root, val))
    {
        return root;
    }
    return DeleteNodeHelper(root, val);
}
template <class T>
T AvlTree<T>::kth_smallest_util(node<T> *root, int index, int pos)
{
    if (root == NULL)
        return -1;

    pos += root->CountLeft + 1;
    if (pos == index)
        return root->data;
    else
    {
        if (index < pos)
        {
            return kth_smallest_util(root->left, index, pos - (root->CountLeft + 1));
        }
        else
        {
            return kth_smallest_util(root->right, index, pos);
        }
    }
}
template <class T>
T AvlTree<T>::kth_smallest(node<T> *root, int k)
{
    return kth_smallest_util(root, k, 0);
}
template <class T>
T AvlTree<T>::KthLargestHelper(node<T> *root, int index, int pos)
{
    if (root == NULL)
        return -1;

    pos += root->CountRight + 1;
    if (pos == index)
        return root->data;
    else
    {
        if (index > pos)
        {
            return KthLargestHelper(root->left, index, pos);
        }
        else
        {
            return KthLargestHelper(root->right, index, pos - (root->CountRight + 1));
        }
    }
}
template <class T>
T AvlTree<T>::KthLargest(node<T> *root, int k)
{
    return KthLargestHelper(root, k, 0);
}
template <class T>
bool AvlTree<T>::contains(node<T> *root, int val)
{
    if (root == NULL)
        return false;
    if (root->data == val)
        return true;
    else if (val < root->data)
        return contains(root->left, val);
    else
        return contains(root->right, val);
}
template <class T>
T AvlTree<T>::closest_util(node<T> *root, T val, int x)
{
    int dp, dc;
    if (val == root->data)
        return root->data;
    dp = abs(x - val);
    dc = abs(root->data - val);
    if (dp <= dc && root->right == NULL && val > root->data)
    {
        if (dp == dc)
            return (x <= root->data) ? x : root->data;
        return x;
    }
    if (dp <= dc && root->left == NULL && val < root->data)
    {
        if (dp == dc)
            return (x <= root->data) ? x : root->data;
        return x;
    }
    else if (root->left == NULL && root->right == NULL)
        return root->data;

    if (val < root->data)
    {
        if (dp == dc)
        {
            x = (x <= root->data) ? x : root->data;
        }
        else
            x = (dp < dc) ? x : root->data;
        return closest_util(root->left, val, x);
    }
    else
    {
        if (dp == dc)
        {
            x = (x <= root->data) ? x : root->data;
        }
        else
            x = (dp < dc) ? x : root->data;
        return closest_util(root->right, val, x);
    }
    return -1;
}
template <class T>
T AvlTree<T>::closest(node<T> *root, T val)
{
    if (root == NULL)
        return -1;
    if (val == -1)
        return kth_smallest(root, 1);
    return closest_util(root, val, INT_MAX);
}
template <class T>
int AvlTree<T>::SmHelper(node<T> *root, T val, int pos)
{
    int leftheight = 0, rightheight = 0;
    if (root == NULL)
        return pos;

    pos += root->CountLeft + 1;
    if (root->data == val)
        return pos;
    else
    {
        if (val < root->data)
        {
            return SmHelper(root->left, val, pos - (root->CountLeft + 1));
        }
        else
        {
            return SmHelper(root->right, val, pos);
        }
    }
}
template <class T>
int AvlTree<T>::SmForRange(node<T> *root, T value)
{
    return SmHelper(root, value, 0);
}
template <class T>
int AvlTree<T>::InRange(node<T> *root, T val1, T val2)
{
    T temp, c1 = 0, c2 = 0, Rangecount = 0;
    if (val2 < val1)
    {
        temp = val2;
        val2 = val1;
        val1 = temp;
    }
    if (contains(root, val1) && contains(root, val2))
        Rangecount = 1;
    else if (contains(root, val1) && (!(contains(root, val2))))
        Rangecount = 1;
    c1 = SmForRange(root, val1);
    c2 = SmForRange(root, val2);
    return (c2 - c1 + Rangecount);
 };
