//
//  main.cpp
//  expt-11
//
//  Created by Parth Verma on 30/10/17.
//  Copyright © 2017 Parth Verma. All rights reserved.
//

#include <iostream>

template <class T>
struct node{
    T ele;
    node<T>* next;
};
template <class T>
class stack {
    int _size;
    node<T> *top;
    
public:
    stack(){
        top = NULL;
        _size = 0;
    }
    void add(T ele){
        node<T> *n =new node<T>(ele,top);
        _size++;
        top = n;
    }
    node<T>& pop(){
        if (_size==0){
            std::cout<<"Empty Stack";
            return NULL;
        }
        node<T> ret,*n = top;
        ret = *n;
        top = n->next;
        delete n;
        _size--;
        return ret;
    }
    int size(){
        return _size;
    }
};

template <class T>
class linked_list {
    int _size;
    node<T> *head,*tail;
    
public:
    linked_list(){
        _size = 0;
        head=tail=NULL;
    }
    void add_node(T item){
        node<T> *temp =  new node<T>();
        *temp = item;
        if (head==NULL){
            head = temp;
        }
        tail->next=temp;
        tail=temp;
        _size++;
    }
    void insert_node(T item,int pos){
        node<T> *temp = new node<T>();
        if (pos==0){
            temp->next=head;
            head=temp;
        }
        else if (pos== _size-1){
            add_node(item);
        }
        else if (pos<_size){
            node<T> *t=head;
            for (int n=1;n<=pos;n++){
                t=t->next;
            }
            t->next=temp->next;
            temp->next=t;
        }
    }
    int size(){
        return _size;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
