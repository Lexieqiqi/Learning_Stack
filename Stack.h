//
// Created by Lexie on 2018/11/12.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

#endif //STACK_STACK_H

#include <iostream>
using namespace std;

template <class T>
struct Node{
    T data;
    struct Node *next;
};

template <class T>
class Stack {
public:
    Stack();
    void Push(T const x);
    const T Pop();
    const T Top();
    bool IsEmpty();
    void Size();
    void Print();
private:
    int curr_size;
    typedef struct Node<T> *LNode;
    LNode top;
    LNode bottom;
};

template <class T>
Stack<T>::Stack()
        :top(nullptr),bottom(nullptr){
    curr_size = 0;
}

template <class T>
void Stack<T>::Push(const T x) {
    cout << "Push " << x << " into stack."<<endl;
    LNode node = new Node<T>;
    node->data = x;
    if(curr_size == 0){
        bottom = node;
    }
    else{
        top->next = node;
    }
    top = node;
    node = NULL;
    curr_size = curr_size + 1;
}

template <class T>
const T Stack<T>::Pop() {
    T vals = top->data;
    if(curr_size == 0){
        cout << "No element to pop. ERROR!" << endl;
    }
    else{
        cout << "Pop "<<top->data<<" out of stack."<<endl;
        LNode node;
        node = bottom;
        for(int i = 1;i < curr_size-1;i++){
            node = node->next;
        }
        node->next = NULL;
        top = node;
        node = NULL;
        curr_size = curr_size - 1;
    }
    return vals;
}

template <class T>
const T Stack<T>::Top() {
    return top->data;
}

template <class T>
void Stack<T>::Size() {
    cout << "The size of this stack is "<<curr_size<<endl;
}

template <class T>
void Stack<T>::Print() {
    LNode node;
    node = bottom;
    for(int i = 0;i < curr_size;i++){
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
    node = NULL;
}

template <class T>
bool Stack<T>::IsEmpty() {
    return bottom == nullptr;
}