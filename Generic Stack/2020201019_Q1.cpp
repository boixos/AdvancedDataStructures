#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<limits>
#include<math.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;


template <class T>

class node{
    public:
     T data;
     node<T>* next;
};  

template <class T>
class Stack{
    private:
     node<T>* st;
    public:
     Stack();
     bool empty();
     T top();
     void push( T  x);
     void pop();
    
};
template <class T>
Stack<T>::Stack(){
    st = NULL;
}
template <class T>
void Stack<T>::push(T x){
    node<T>* temp = new node<T>;
        temp->data = x;
        temp->next = st;
        st= temp;
} 
template <class T>
void Stack<T>::pop(){
    if (st == NULL){
        cout << "Stack is empty" << endl;
        exit(1);
    }
    else {
        node<T>* temp;
        temp = st;
        st= st->next;
        delete temp;
       }
}
template <class T>
T Stack<T>::top(){
    if (!empty())
        return st->data;
    else
        exit(1);
}
template <class T>    
bool Stack<T>::empty(){
        return st == NULL; 
}

int OperatorPrecedence(char c){ 
    if(c == '+'||c == '-') 
    return 1; 
    if(c == '*'||c == '/'||c == '%') 
    return 2; 
    return 0; 
} 
  
double PerformOperations(double a, double b, char c){ 
    switch(c){ 
        case '+':  return a + b; 
        case '-':  return a - b; 
        case '*':  return a * b; 
        case '/':  return a / b; 
        case '%':  return fmod(a,b);
        default :  return 0;
    } 
} 
bool isOperator(char c){
    return (c == '+'|| c=='-'|| c=='*'|| c=='/'|| c=='%');
}  

void calculate(Stack<double> *operands,Stack<char> *operators){
    
    double b = (*operands).top(); 
    (*operands).pop(); 
                  
    double a = (*operands).top(); 
    (*operands).pop(); 
                  
    char op = (*operators).top(); 
    (*operators).pop(); 
                  
    (*operands).push(PerformOperations(a, b, op)); 
            
}

double evaluate(string expression){ 
    int i,n= expression.length(); 
  
    Stack <double> operands; 
 
    Stack <char> operators; 
      
    for(i = 0; i < n; i++){ 
          
         if(expression[i] == '('){ 
            operators.push(expression[i]); 
        } 
          
       
        else if(isdigit(expression[i])){ 
            double val = atof(&expression[i]); 
            operands.push(val); 
            while(expression[i] == '.' || isdigit(expression[i])) 
                 i++;
             i--;
           
        } 
          
       
        else if(expression[i] == ')') 
        { 
            while(!operators.empty() && operators.top() != '(') 
            {  
                calculate(&operands,&operators);
            } 
              
            if(!operators.empty()) 
               operators.pop(); 
        } 
           
        else if(isOperator(expression[i]))
        { 
             
            while(!operators.empty() && OperatorPrecedence(operators.top()) >= OperatorPrecedence(expression[i]))
            { 
                calculate(&operands,&operators);
            } 
             
            operators.push(expression[i]); 
        }
        else if(expression[i] == ' ') 
            continue;  
    } 
      
    while(!operators.empty())
    { 
       calculate(&operands,&operators);
    } 
    return operands.top(); 
} 

int main(){
    string exp;
    getline(cin,exp);
    double result = evaluate(exp);
    cout << fixed;
    cout << setprecision(5)<<result<<endl; 
    
    return 0;
}