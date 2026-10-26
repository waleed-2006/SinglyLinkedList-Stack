// singly linked list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;
template <typename Val>
class sNode {
private:
    Val _val;
    sNode<Val>* _next;


public:
    sNode(const Val& value) {
        _val = value;
        _next = nullptr;
    }
    sNode() {
        _next = nullptr;
    }
    template <typename Val>
    friend class sLinkedList;
};


template <typename Val>
class linkeListStack {
private:
    sNode<Val>* _Top;
    int _capacity;
    int _size;
public:
    linkeListStack(const int capacity) {
        _Top = nullptr;
        _capacity = capacity;
        _size=0;
    }

    void Push(const Val& val) {
        if (_size == _capacity) {
            throw invalid_argument("Stack is Full");
        }
        sNode<Val>* New = new sNode(val);

        if (_Top == nullptr) {
            _Top = New;
            return;
        }
        sNode<Val>* old = _Top;
        New->_next = old;
        _Top = New;
        ++_size;
    }



    void Pop() {
        if (_size == 0) {
            throw invalid_argument("Stack is Empty");
        }
        if (_Top == nullptr) {
            return;
        }
        sNode<Val>* old = _Top;

        _Top = _Top->_next;
        delete old;
        --_size;
    }
    const Val& Top() {
        return _Top;
    }

    int size() {
        return _size;
    }
    bool empty() {
        return _Top == nullptr;
    }

    
};




int main() {

}