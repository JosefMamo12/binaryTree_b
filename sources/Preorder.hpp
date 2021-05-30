#pragma once
#include "BinaryTree.hpp"
#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include "Node.hpp"

using namespace std;

namespace ariel
{
    template <class T>
    class Preorder
    {
    private:
        Node<T> *m_pointer;
        stack<Node<T> *> st;
        unsigned int size = 0;

    public:
        T &operator*() const
        {
            return m_pointer->value;
        }

        T *operator->() const
        {
            return &(m_pointer->value);
        }
        const Preorder operator++(int)
        {
            Preorder tmp = *this;
                if (m_pointer->left != nullptr && m_pointer->right != nullptr )
            {
                st.push(m_pointer->right);
                m_pointer = m_pointer->left;
            }
            else if(m_pointer->left != nullptr && m_pointer->right == nullptr ){
                m_pointer = m_pointer->left;
            }
            else if(m_pointer->right != nullptr && m_pointer->left == nullptr){
                m_pointer = m_pointer->right;
            }
            else if (m_pointer->left == nullptr && m_pointer->right == nullptr && !st.empty())
            {
                m_pointer = st.top();
                st.pop();
            }
            else
            {
                m_pointer = nullptr;
            }
            return tmp;
        }
        Preorder &operator++()
        {
            if (m_pointer->left != nullptr && m_pointer->right != nullptr )
            {
                st.push(m_pointer->right);
                m_pointer = m_pointer->left;
            }
            else if(m_pointer->left != nullptr && m_pointer->right == nullptr ){
                m_pointer = m_pointer->left;
            }
            else if(m_pointer->right != nullptr && m_pointer->left == nullptr){
                m_pointer = m_pointer->right;
            }
            else if (m_pointer->left == nullptr && m_pointer->right == nullptr && !st.empty())
            {
                m_pointer = st.top();
                st.pop();
            }
            else
            {
                m_pointer = nullptr;
            }

            return *this;
        }
        bool operator==(const Preorder &rhs) const
        {
            return m_pointer == rhs.m_pointer;
        }

        bool operator!=(const Preorder &rhs) const
        {
            return m_pointer != rhs.m_pointer;
        }
        Preorder(Node<T> *root)
        {
            if (root != nullptr)
            {
                m_pointer = root;
            }
            else
            {
                m_pointer = nullptr;
            }
        }
     
    };

}