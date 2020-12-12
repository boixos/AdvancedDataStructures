#include <bits/stdc++.h>
#include <string>
#define s 2
#define lli long long
using namespace std;

class Trie
{
public:
    bool isleaf;
    Trie *cap[s];
    Trie();
    void insert(Trie *, string);
    bool search(string);
    lli MaxXor(Trie *, string);
    lli power(lli x, lli n);
};
Trie::Trie()
{
    this->isleaf = false;
    for (lli i = 0; i < s; i++)
        this->cap[i] = nullptr;
}

void Trie::insert(Trie *root, string x)
{
    //cout<<"here";
    Trie *temp = root;
    lli n = x.length();
    lli f;
    for (lli i = 0; i < n; i++)
    {
        f = x[i] - 48;
        if (temp->cap[f] != nullptr)
            temp = temp->cap[f];
        else
            temp = temp->cap[f] = new Trie();
    }

    temp->isleaf = true;
}
bool Trie::search(string x)
{
    if (this == nullptr)
        return false;

    Trie *curr = this;
    for (lli i = 0; i < x.length(); i++)
    {
        curr = curr->cap[x[i]];
        if (curr == nullptr)
            return false;
    }
    return curr->isleaf;
}
string DecToBin(lli n)
{
    string b;

    for (long long i = 39; i >= 0; i--)
    {
        lli k = n >> i;
        if (k & 1)
            b = b + '1';
        else
            b = b + '0';
    }
    return b;
}
lli Trie::MaxXor(Trie *root, string x)
{
    Trie *temp = root;
    lli ans = 0;
    lli n = x.length();
    for (lli i = 0; i <= 39; i++)
    {
        lli f = (x[i] - 48);
        //cout<<"here"<<endl;
        if (temp->cap[f ^ 1])
        {
            n = 39 - i;
            //n = power(2,n);
            ans = ans + power(2, n);
            //cout<<n<<" ";
            temp = temp->cap[f ^ 1];
        }
        else
        {
            temp = temp->cap[f];
        }
    }
    return ans;
}
lli Trie::power(lli x, lli y)
{
    lli temp;
    if (y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}
int main()
{
    lli n, q, a;
    string si;
    Trie *root = new Trie();
    cin >> n >> q;
    while (n--)
    {
        cin >> a;
        si = DecToBin(a);
        //cout<<si<<" ";
        root->insert(root, si);

        //cout<<root->search(si);
    }
    while (q--)
    {
        cin >> a;
        si = DecToBin(a);
        cout << root->MaxXor(root, si) << endl;
    }

    //cout<<n;
}