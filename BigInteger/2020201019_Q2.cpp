#include <bits/stdc++.h>
#include <string>
#include <string.h>
using namespace std;
#define ulli unsigned long long int
class BigInteger{
    private: 
     string arr;
    public:
     int factorial(int n);
     int power(ulli b,ulli e);
     string gcd(string a,string b);
     int multiply(ulli x, ulli y);
     void output(int n);
};

void BigInteger::output(int n){
    for(int i = n-1; i >= 0; i--) 
	    cout << (arr[i]-'0'); 
    cout<<endl;
   // delete[] arr;
}

int BigInteger::multiply(ulli x, ulli y){
    int temp=0,mul; 
    for (ulli i = 0; i < y; i++){
        mul = (arr[i] -'0')* x + temp; 
        arr[i] = mul % 10; 
        temp = mul / 10; 
    } 
    while (temp){ 
        arr[y] = temp % 10; 
        temp = temp / 10; 
        y++; 
    } 
   return y; 
} 

int BigInteger::power(ulli b, ulli  x){
    //arr = new int [30000]; 
    int digits = 0; 
    int temp = b; 
    while (b != 0){ 
        arr[digits++] = b % 10; 
        b = b / 10; 
    } 
    for (ulli i = 2; i <= x; i++) 
        digits = multiply(temp, digits); 
  
    return digits;
} 

int BigInteger::factorial(int a){
    //arr= new int[30000]; 
    arr[0] = 1; 
    int digits = 1; 
    for (int x=2; x<=a; x++) 
        digits = multiply(x,digits); 
    return digits;
}
string BigInteger::gcd(string a, string b){ 
    if(a == b) 
        return a; 
    if(a == 0) 
        return b; 
    if(b == 0) 
        return a; 
    if(~a&1){ 
        if(b&1) 
            return gcd(a>>1,b); 
        else
            return gcd(a>>1,b>>1)<<1; 
    } 
    if(~b&1) 
        return gcd(a,b>>1); 
    if (a>b) 
        return gcd((a-b)>>1,b); 
    return gcd((b-a)>>1,a); 
} 

int main(){
   
    ulli x,a,b,n;
    BigInteger t;
    int q;
    cin>>q;
    while(q--){
        cin>>x;
        switch(x){
            case 1: cin>>a>>b;
                    if(b==0) cout<<'1'<<endl;
                    else if(a==0) cout<<'0'<<endl;
                    else{
                       // BigInteger p;
                        n =t.power(a,b);
                        t.output(n);
                    }
                    break;
            case 2: cin>>a>>b;
                    //BigInteger t;
                    t.gcd(a,b);
                    cout<<t.gcd(a,b)<<endl;
                    break;
            case 3: cin>>a;
                    //BigInteger t;
                    n = t.factorial(a); 
                    t.output(n);
                    break;       
        }
    }
   return 0;
}