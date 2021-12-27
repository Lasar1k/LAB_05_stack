//Copyright 2021 Lasar1k <alf.ivan2002@gmail.com>

#ifndef INCLUDE_STACK_HPP_
#define INCLUDE_STACK_HPP_

#include <initializer_list>
#include <stdarg.h>
#include <iostream>

template <class T>
class stackk
{
    struct Node
    {
        T value;
        Node *next;
    };
    Node *top;
public:
    stackk();
    stackk(const stackk&) = delete;
    stackk& operator=(const stackk&) = delete;
    template <class... Args>
    void push_emplace(Args&&... value);
    template<class T1, class... Args>
    void push_emplace1(T1&& value, Args&&... value1);
    void push(T&& value);
    void push(const T& value);
    const T& head() const;
    T pop();
    ~stackk();
};

template <class T>
stackk<T>::stackk()
{
    top = nullptr;
}

template <class T>
template <class... Args>
void stackk<T>::push_emplace(Args&&... value)
{
    for (auto p : std::initializer_list<T>{value...})
    {
        Node *node = new Node;
        node->value = p;
        node->next = top;
        top = node;
    }
}

template <class T>
void stackk<T>::push(T&& value)
{
    Node *node = new Node;
    node->value = value;
    node->next = top;
    top = node;
}

template <typename T>
void stackk<T>::push(const T& value)
{
    Node *node = new Node;
    node->value = value;
    node->next = top;
    top = node;
}

template <class T>
const T& stackk<T>::head() const
{
    return top->value;
}

template <class T>
T stackk<T>::pop()
{
    T value = top->value;
    Node *tmp = top;
    top = top->next;
    delete tmp;
    return value;
}

template <class T>
stackk<T>::~stackk()
{
    while (top)
    {
        Node *tmp = top;
        top = top->next;
        delete tmp;
    }
}

#endif // INCLUDE_STACK_HPP_
