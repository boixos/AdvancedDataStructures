
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

template <class T1, class T2>
class HashMap
{

public:
    class HashEntry
    {
    public:
        T1 key;
        T2 value;
        HashEntry *next;
        HashEntry(T1 key, T2 value)
        {
            this->key = key;
            this->value = value;
            next = NULL;
        }
    };
    HashEntry **table;
    int TABLE_SIZE = 0;
    int size = 0;
    HashMap();
    int HashFunc(T1 key)
    {
        string str = to_string(key);
        unsigned long hash = 0;
        int c;
        int n = str.length();
        for (c = 0; c < n; c++)
            hash = ((hash << 5) + hash) + str[c]; /* hash * 33 + c */

        return hash % TABLE_SIZE;
    }

    void insert(T1 key, T2 value);
  
    T2 find(T1 key)
    {
        //cout<<"x";
        int hash = HashFunc(key);
       // cout<<"y";
        while (table[hash] != NULL && table[hash]->key != key)
        { //cout<<"here";
            hash = HashFunc(hash + 1);
        }
        if (table[hash] == NULL)
            return (T2)NULL;
        else
            return table[hash]->value;
    }
    T2 operator[](T1 key)
    {
        return find(key);
    }

      void erase(int key);
      void rehash(){
          HashEntry **temp = table;
            cout << "herer";
            int tempts = TABLE_SIZE;
            TABLE_SIZE = 2 * TABLE_SIZE;
            table = new HashEntry *[TABLE_SIZE];
            size = 0;
            for (int i = 0; i < tempts; i++)
                table[i] = NULL;
            for (int i = 0; i < tempts; i++)
            {
                while (temp[i] != NULL)
                {
                    insert(temp[i]->key, temp[i]->value);
                    temp[i] = temp[i]->next;
                }
            }
      }
};
template <class T1 ,class T2> 
HashMap<T1,T2>::HashMap()
    {
        TABLE_SIZE = 1003;
        size = 0;
        table = new HashEntry *[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            table[i] = NULL;
        }
    }
template <class T1 ,class T2> 
void HashMap<T1,T2>::insert(T1 key, T2 value)
    {
        int hash = HashFunc(key);
       
        HashEntry *t = table[hash];
        while (t != NULL)
        {
            if (t->key == key)
            {
                t->value = value;
                return;
            }
            t = t->next;
        }
        // if (table[hash]->key == key)
        //     table[hash]->value = value;

        t = table[hash];
        HashEntry *t1 = new HashEntry(key,value);
        t1->next = t;
        
        table[hash] = t1;
        //cout<<table[hash]->key<<" "<<table[hash]->value<<" insrt"<<endl;
        size++;
        
        int loadfac = (1.0 * size) / TABLE_SIZE;
        if (loadfac > 0.75)
        { cout<<"here"<<endl;
            rehash();
        }
    }
template <class T1 ,class T2> 
void HashMap<T1,T2>::erase(int key)
    {
        int hash = HashFunc(key);
        while (table[hash] != NULL)
        {
            if (table[hash]->key == key)
                break;
            hash = HashFunc(hash + 1);
        }
        if (table[hash] == NULL)
        {
            ///cout << "No Element found at key " << key << endl;
            return;
        }
        else
        {
            delete table[hash];
        }
        cout << "Element Deleted" << endl;
    };
    int main()
{
    HashMap<int, int> m;
    m.insert(1, 10);
    m.insert(9, 10);
    m.insert(8, 10);
    m.insert(11, 10);
    m.insert(71, 10);
    m.insert(12, 10);
    //m.display();
    cout << m.find(1);
}