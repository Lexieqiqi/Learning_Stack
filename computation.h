//
// Created by Lexie on 2018/11/13.
//

#ifndef STACK_COMPUTATION_H
#define STACK_COMPUTATION_H

#endif //STACK_COMPUTATION_H

#include <iostream>
using namespace std;

class computation{
public:
    computation();
    void Input();
    void Calculate();
    int priority(char x);
private:
    Stack<int> vals;
    Stack<char> ops;
    char a[50];
};

computation::computation() {
    cout << "Hahaha,我要自己写运算的过程了，呵呵" << endl;
    for(int i = 0;i < 50;i++){
        a[i] = 'q';
    }
}

void computation::Input() {
    cout << "Please input a computation expression :" ;
    cin.getline(a,50);
    cin.sync();
}

void computation::Calculate() {
    if(ops.IsEmpty()){
        ops.Push(a[0]);
    }
    for(int i = 1;a[i]!='#';i++){
        if(isdigit(a[i])){
            vals.Push(int(a[i]-'0'));
            continue;
        }
        else{
            while(priority(a[i])<=priority(ops.Top())){
                if((a[i]==')'&&ops.Top()==')')||(a[i]=='#'&&ops.Top()=='#')){
                    ops.Pop();
                }
                else{
                    if(ops.Top()=='*')
                        vals.Push(vals.Pop()*vals.Pop());
                    if(ops.Top()=='/')
                        vals.Push(vals.Pop()/vals.Pop());
                    if(ops.Top()=='+')
                        vals.Push(vals.Pop()+vals.Pop());
                    if(ops.Top()=='-')
                        vals.Push(vals.Pop()-vals.Pop());
                    ops.Pop();
                }
            }
                while(priority(a[i])>priority(ops.Top())){
                    ops.Push(a[i]);
                }
        }
    }
    while(ops.Top()!='#'){
        if(ops.Top()=='*')
            vals.Push(vals.Pop()*vals.Pop());
        if(ops.Top()=='/'){
            int temp = vals.Pop();
            vals.Push(vals.Pop()/temp);
        }
        if(ops.Top()=='+')
            vals.Push(vals.Pop()+vals.Pop());
        if(ops.Top()=='-')
            vals.Push(vals.Pop()-vals.Pop());
        ops.Pop();
    }
    cout << "The result is "<<vals.Top() << endl;
}

int computation::priority(char x) {
    if(x == '+'||x == '-')    return 0;
    if(x == '*'||x == '/'||x == '%')    return 1;
    if(x == '('||x == ')')    return -1;
    if(x == '#')    return -2;
}

