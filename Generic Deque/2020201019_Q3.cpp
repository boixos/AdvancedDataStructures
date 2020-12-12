#include<bits/stdc++.h>
using namespace std;
int defaultarrsize = 0;
template <class T>
class Gdeque{
    private:
      T* arr;
      int arrSize;
      int beg;
      int end;
      
    public:
      Gdeque();
      Gdeque(int n,T x);
      T operator [] (int);
      void push_back(T x);
      void push_front(T x);
      void pop_back();
      void pop_front();
      T peekfront();
      T peekback();
      bool isempty();
      int size();
      void resize(int n,T x);
      void clear();
      void display();
       
};

template <class T>
 Gdeque<T>::Gdeque(){
    arr = new T [defaultarrsize];
    arrSize=defaultarrsize;
    beg=0;
    end=0;
}

template <class T>
 Gdeque<T>::Gdeque(int n, T x){
     arr = new T[n+1];
     for(int i=0;i<n;i++){  
         arr[i]=x;
     }
     arrSize = n;
     beg =0;
     end =n;
 }

 template <class T> 
void Gdeque<T>::resize(int n,T x){
    int s = size();
    if(n>s){

        for(int i=0;i<n-s;i++)
            push_back(x);
    }
    else if(n<s){
        for(int i=0; i< s-n; i++){
            pop_back();
        }
    }
}

template <class T>
bool Gdeque<T>::isempty(){
    return beg==end;
}

template <class T> 
int Gdeque<T>::size(){
    if(beg <= end)
    return end-beg;
    return arrSize + end - beg;
}

template <class T>
void Gdeque<T>::push_front(T x){
    if(size()+1 >= arrSize){
        int newarrsize,i;
        newarrsize = 2*arrSize;
        if(arrSize ==0) newarrsize=2;
        T* newarr = new T [newarrsize];
    
        if(beg<=end){
           for(i=beg;i<end;i++)
            newarr[i] = arr[i];
        }
        else{
            for (i = beg; i < arrSize; ++i)
             newarr[i] = arr[i];
            for (i = 0; i < end; ++i)
             newarr[i + arrSize] = arr[i];
            end += arrSize;
        }
        delete [] arr;
        arr = newarr;
        arrSize = newarrsize;
  }
   if (beg == 0)
     beg = arrSize;
   --beg;
   arr[beg] = x;
}
    
template <class T>
void Gdeque<T>::push_back(T x){
    if (size() + 1 >= arrSize){
        int newarrsize,i;
        newarrsize = 2 * arrSize;
        if (arrSize == 0) newarrsize = 2;
        T* newarr = new T [newarrsize];
    
        if (beg <= end){
            for (i = beg; i < end; ++i)
            newarr[i] = arr[i];
        }
        else{
            for (i = beg; i < arrSize; ++i)
            newarr[i] = arr[i];
            for (i = 0; i < end; ++i)
            newarr[i + arrSize] = arr[i];
            end += arrSize;
        }
        delete [] arr;
        arr = newarr;
        arrSize = newarrsize;
    }
    arr[end] = x;
    ++end;
    if (end == arrSize)
        end = 0;
}

template <typename T>
void Gdeque<T>::pop_front(){
  ++beg;
  if (beg == arrSize)
    beg = 0;
  
}

template <typename T>
void Gdeque<T>::pop_back(){
  if (end == 0)
    end = arrSize;
  --end;
  
}

template <typename T>
void Gdeque<T>::clear(){
    beg = 0;
    end = 0;
    delete[] arr;
}

template <class T>
void Gdeque<T>::display(){
   int i;
    if(beg<=end ){
        for(i=beg;i<end;i++) cout<<arr[i]<<' ';
    }
    else{ 
        for (i = beg; i < arrSize; ++i) cout<<arr[i]<<' ';
        for (i = 0; i < end; ++i) cout<<arr[i]<<' ';
    }
}

template <typename T>
T  Gdeque<T>::peekfront(){
        return arr[beg];
}

template <typename T>
T  Gdeque<T>::peekback(){
    if (end == 0)
       return arr[arrSize - 1];
    return arr[end - 1];
}

template <typename T>
T Gdeque<T>::operator [] (int i){
    i += beg;
    if (i >= arrSize)
       i -= arrSize;  
    return arr[i];
}

int main(){ 
    Gdeque<int> *arr =NULL;
    int Q,c,n;
    int x;
    cin>>Q;
    while (Q--){      
        cin>>c;
        switch (c){

            case 1: cin>>x;
                    arr->push_front(x);  
                    arr->display();
                    break;
            case 2: arr->pop_front();
                    arr->display();
                    break;
 
 case 3: cin>>x;
         arr->push_back(x);
         arr->display();
         break;
 
 case 4: arr->pop_back();
         arr->display();
         break;
 
 case 5: if(arr !=NULL)
         delete arr;
         arr = new Gdeque<int>();
         break;

case 6: cin>>n>>x;
         if(arr !=NULL)
         delete arr;
         arr = new Gdeque<int>(n,x);
         arr->display();
         break;

 case 7: cout<<arr->peekfront()<<endl;
         break;

 case 8: cout<<arr->peekback()<<endl;
         break;
 
 case 9: if(arr->isempty())
          cout<<"true\n";
         else
          cout<<"false\n";
         break;

 case 10: cout<<arr->size()<<endl;
          break;

 case 11: cin>>n>>x;
          arr->resize(n,x);
          arr->display();
          break;

 case 12: arr->clear();
          break;
 
case 13: cin>>n;
          cout<<(*arr)[n-1]<<endl;
          break;

 case 14: arr->display();
         break;

 default:
     break;
 }
    }
delete arr;
return 0;
}