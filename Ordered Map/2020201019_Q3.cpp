#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int count;
template <class KEY, class VAL>
class Node
{
public:
    KEY key;
    VAL value;
    Node *left = NULL;
    Node *right = NULL;
};

template <class KEY, class VAL>
class orderedmap
{
    Node<KEY, VAL> *root;
    int count;

public:
    orderedmap();
    int max(int a, int b);
    int size();
    int height(Node<KEY, VAL> *node);
    Node<KEY, VAL> *successor(Node<KEY, VAL> *ptr);
    int balance(Node<KEY, VAL> *ptr);

    Node<KEY, VAL> *leftrotate(Node<KEY, VAL> *ptr);
    Node<KEY, VAL> *rightrotate(Node<KEY, VAL> *ptr);

    void insert(KEY key, VAL value);
    Node<KEY, VAL> *insertNode(KEY key, VAL value, Node<KEY, VAL> *ptr);

    void erase(KEY key);
    Node<KEY, VAL> *deleteNode(KEY key, Node<KEY, VAL> *ptr);

    bool find(KEY key);
    bool ispresent(KEY key, Node<KEY, VAL> *ptr);

    VAL *KeyValue(KEY key, Node<KEY, VAL> *ptr);
    VAL &operator[](KEY key);

    void clear();
    void clearTree(Node<KEY,VAL>* node);

    void display();
    void inorder(Node<KEY,VAL>* node);
};
template <class KEY, class VAL>
orderedmap<KEY, VAL>::orderedmap()
{
    root = NULL;
    count = 0;
}
template <class KEY, class VAL>
int orderedmap<KEY, VAL>::balance(Node<KEY, VAL> *ptr)
{
    return height(ptr->left) - height(ptr->right);
}

template <class KEY, class VAL>
int orderedmap<KEY, VAL>::size()
{
    return count;
}
template <class KEY, class VAL>
int orderedmap<KEY, VAL>::height(Node<KEY, VAL> *ptr)
{

    if (ptr == NULL)
    {
        return 0;
    }
    if (ptr->left == NULL && ptr->right == NULL)
    {
        return 1;
    }
    else
    {
        return max(height(ptr->right), height(ptr->left)) + 1;
    }
}
template <class KEY, class VAL>
Node<KEY, VAL> *orderedmap<KEY, VAL>::successor(Node<KEY, VAL> *ptr)
{
    Node<KEY, VAL> *pt = ptr;
    while (pt->left)
    {
        pt = pt->left;
    }
    return pt;
}
template <class KEY, class VAL>
Node<KEY, VAL> *orderedmap<KEY, VAL>::leftrotate(Node<KEY, VAL> *ptr)
{
    Node<KEY, VAL> *newptr = new Node<KEY, VAL>();
    newptr = ptr->right;
    ptr->right = newptr->left;
    newptr->left = ptr;
    ptr = newptr;
    return ptr;
}
template <class KEY, class VAL>
Node<KEY, VAL> *orderedmap<KEY, VAL>::rightrotate(Node<KEY, VAL> *ptr)
{
    Node<KEY, VAL> *newptr = new Node<KEY, VAL>();
    newptr = ptr->left;
    ptr->left = newptr->right;
    newptr->right = ptr;
    ptr = newptr;
    return ptr;
}
template <class KEY, class VAL>
void orderedmap<KEY, VAL>::insert(KEY key, VAL value)
{
    count++;
    root = insertNode(key, value, root);
}

template <class KEY, class VAL>
Node<KEY, VAL> *orderedmap<KEY, VAL>::insertNode(KEY key, VAL value, Node<KEY, VAL> *ptr)
{
    if (ptr == NULL)
    {
        ptr = new Node<KEY, VAL>();
        ptr->key = key;
        ptr->value = value;
        ptr->right = NULL;
        ptr->left = NULL;
        return ptr;
    }

    if (ptr->key == key)
    {
        ptr->value = value;
        count--;
        return ptr;
    }

    if (key < ptr->key)
    {
        ptr->left = insertNode(key, value, ptr->left);
    }

    if (key > ptr->key)
    {
        
        ptr->right = insertNode(key, value, ptr->right);
    }

    if (balance(ptr) > 1)
    {

        if (balance(ptr->left) > 0)
        {
            ptr = rightrotate(ptr);
        }
        else
        {
            ptr->left = leftrotate(ptr->left);
            ptr = rightrotate(ptr);
        }
    }
    
    if (balance(ptr) < -1)
    {
        if (balance(ptr->right) < 0)
        {
            ptr = leftrotate(ptr);
            
        }
        else
        {
            ptr->right = rightrotate(ptr->right);
            ptr = leftrotate(ptr->left);
            
        }
    }
    return ptr;
}

template <class KEY, class VAL>
void orderedmap<KEY, VAL>::erase(KEY key)
{
    root = deleteNode(key, root);
    count--;
}

template <class KEY, class VAL>
Node<KEY, VAL> *orderedmap<KEY, VAL>::deleteNode(KEY key, Node<KEY, VAL> *ptr)
{
    if (ptr == NULL)
    {
        return ptr;
    }

    if (key < ptr->key)
    {
        ptr->left = deleteNode(key, ptr->left);
    }
    else if (key > ptr->key)
    {
        ptr->right = deleteNode(key, ptr->right);
    }
    else
    {
        if (ptr->left == NULL && ptr->right == NULL)
        {
            ptr = NULL;
        }
        else if (ptr->left != NULL && ptr->right == NULL)
        {
            Node<KEY, VAL> *temp = ptr->left;
            *ptr = *temp;
            free(temp);
        }
        else if (ptr->left == NULL && ptr->right != NULL)
        {
            Node<KEY, VAL> *temp = ptr->right;
            *ptr = *temp;
            free(temp);
        }
        else
        {
            Node<KEY, VAL> *temp = successor(ptr->right);
            ptr->key = temp->key;
            ptr->value = temp->value;
            ptr->right = deleteNode(temp->key, ptr->right);
        }
    }

    if (ptr == NULL)
        return ptr;

    if (ptr->left == NULL && ptr->right == NULL)
        return ptr;

    if (balance(ptr) > 1)
    {

        if (balance(ptr->left) > 0)
        {
            ptr = rightrotate(ptr);
        }
        else
        {
            ptr->left = leftrotate(ptr->left);
            ptr = rightrotate(ptr);
        }
    }

    if (balance(ptr) < -1)
    {
        if (balance(ptr->right) < 0)
        {
            ptr = leftrotate(ptr);
            
        }
        else
        {
            ptr->right = rightrotate(ptr->right);
            ptr = leftrotate(ptr->left);
            
        }
    }
    return ptr;
}

template <class KEY, class VAL>
bool orderedmap<KEY, VAL>::find(KEY key)
{
    bool isthere = ispresent(key, root);
    return isthere;
}

template <class KEY, class VAL>
bool orderedmap<KEY, VAL>::ispresent(KEY key, Node<KEY, VAL> *ptr)
{
    if (ptr == NULL)
        return false;
    if (key < ptr->key)
        return ispresent(key, ptr->left);
    else if (key > ptr->key)
        return ispresent(key, ptr->right);
    else
        return true;
}

template <class KEY, class VAL>
VAL *orderedmap<KEY, VAL>::KeyValue(KEY key, Node<KEY, VAL> *ptr)
{

    if (ptr == NULL)
    { //cout<<"False"<<endl;
        static VAL value;
        return NULL;
    }
    if (key < ptr->key)
        return KeyValue(key, ptr->left);
    else if (key > ptr->key)
        return KeyValue(key, ptr->right);
    else
    {
        return &ptr->value;
    }
}

template <class KEY, class VAL>
VAL &orderedmap<KEY, VAL>::operator[](KEY key)
{
    VAL *ptr = KeyValue(key, root);
    if (ptr == NULL)
    {
        insert(key, (VAL)NULL);
        ptr = KeyValue(key, root);
        return *ptr;
    }
    return *ptr;
}
template <class KEY, class VAL>
void orderedmap<KEY, VAL>::display()
{
    inorder(this->root);
    cout<<endl;
    
}
template <class KEY, class VAL>
void orderedmap<KEY, VAL>::inorder(Node<KEY,VAL>* node){
    if(node != NULL){
        inorder(node->left);
        cout<<node->key<<" -> "<<node->value<<endl;
        inorder(node->right);
    }
}
template <class KEY, class VAL>
int orderedmap<KEY, VAL>::max(int a, int b)
{
    return a > b ? a : b;
};
template <class KEY, class VAL>
void orderedmap<KEY, VAL>::clear(){
    clearTree(this->root);
}
template <class KEY, class VAL>
void orderedmap<KEY, VAL>::clearTree(Node<KEY,VAL>* node){
    if(node == NULL)
      return;
    clearTree(node->left);
    clearTree(node->right);
    delete node;  
    
};
int main(){
    orderedmap<int,int> m;
    m.insert(1,10);
    m.insert(11,10);m.insert(111,10);m.insert(1111,10);m.insert(11111,10);m.insert(11011,10);
    m.display();
    //m.clear();
    //m.display();
}
