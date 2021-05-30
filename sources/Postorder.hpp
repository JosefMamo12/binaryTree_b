#pragma once
#include "BinaryTree.hpp"
#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include "Node.hpp"
#include <bits/stdc++.h>

using namespace std;

namespace ariel
{
    template <class T>
    class Postorder
    {
    private:
        Node<T> *m_pointer;
        Node<T> *root;
        unordered_set<Node<T> *> visited;
        u_int size = 0;

    public:
        T &operator*() const
        {

            return m_pointer->value;
        }

        T *operator->() const
        {
            return &(m_pointer->value);
        }
        const Postorder operator++(int)
        {
            Postorder tmp = *this;
            if (m_pointer == root)
            {
                m_pointer = nullptr;
            }
            else
            {
                Node<T> *temp = root;
                while (temp && visited.find(temp) == visited.end())
                {

                    // Visited left subtree
                    if (temp->left &&
                        visited.find(temp->left) == visited.end())
                        temp = temp->left;

                    // Visited right subtree
                    else if (temp->right &&
                             visited.find(temp->right) == visited.end())
                        temp = temp->right;

                    // Print node
                    else
                    {
                        m_pointer = temp;
                        visited.insert(temp);
                        break;
                    }
                }
            }
            return tmp;
        }
        Postorder &operator++()
        {
            if (m_pointer == root)
            {
                m_pointer = nullptr;
            }
            else
            {
                Node<T> *temp = root;
                while (temp && visited.find(temp) == visited.end())
                {

                    // Visited left subtree
                    if (temp->left &&
                        visited.find(temp->left) == visited.end())
                        temp = temp->left;

                    // Visited right subtree
                    else if (temp->right &&
                             visited.find(temp->right) == visited.end())
                        temp = temp->right;

                    // Print node
                    else
                    {
                        m_pointer = temp;
                        visited.insert(temp);
                        break;
                    }
                }
            }
            return *this;
        }
        bool operator==(const Postorder &rhs) const
        {
            return m_pointer == rhs.m_pointer;
        }

        bool operator!=(const Postorder &rhs) const
        {
            return m_pointer != rhs.m_pointer;
        }
        Postorder(Node<T> *root)
        {
            if (root != nullptr)
            {
                this->root = root;
                struct Node<T> *temp = root;

                while (temp && visited.find(temp) == visited.end())
                {

                    // Visited left subtree
                    if (temp->left &&
                        visited.find(temp->left) == visited.end())
                        temp = temp->left;

                    // Visited right subtree
                    else if (temp->right &&
                             visited.find(temp->right) == visited.end())
                        temp = temp->right;

                    // Print node
                    else
                    {
                        m_pointer = temp;
                        visited.insert(temp);
                        break;
                    }
                }
            }
            else
            {
                m_pointer = nullptr;
            }
        }
    };
}
