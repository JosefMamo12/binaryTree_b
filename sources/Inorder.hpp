#pragma once
#include "BinaryTree.hpp"
#include <iostream>
#include <list>
#include "Node.hpp"

using namespace std;

namespace ariel
{

    template <typename T>
    class Inorder
    {

    private:
        // nodePtr is the current location in the tree. we can move
        // freely about the tree using left, right, and parent.
        // tree is the address of the stree object associated
        // with this iterator. it is used only to access the
        // root pointer, which is needed for ++ and --
        // when the iterator value is end()

        Node<T> *m_pointer;
        Node<T> *root;

    public:
        T &operator*() const
        {
            return m_pointer->value;
        }

        T *operator->() const
        {
            return &(m_pointer->value);
        }
        const Inorder operator++(int)
        {
            Inorder tmp = *this;
            Node<T> *p;

            if (m_pointer == nullptr)
            {
                // ++ from end(). get the root of the tree
                m_pointer = this->m_pointer;

                // error! ++ requested for an empty tree
                if (m_pointer == nullptr)
                    throw invalid_argument("No");

                // move to the smallest value in the tree,
                // which is the first node inorder
                while (m_pointer->left != nullptr)
                {
                    m_pointer = m_pointer->left;
                }
            }
            else if (m_pointer->right != nullptr)
            {
                // successor is the farthest left node of
                // right subtree
                m_pointer = m_pointer->right;

                while (m_pointer->left != nullptr)
                {
                    m_pointer = m_pointer->left;
                }
            }
            else
            {
                // have already processed the left subtree, and
                // there is no right subtree. move up the tree,
                // looking for a parent for which m_pointer is a left child,
                // stopping if the parent becomes NULL. a non-NULL parent
                // is the successor. if parent is NULL, the original node
                // was the last node inorder, and its successor
                // is the end of the list
                p = m_pointer->parent;
                while (p != nullptr && m_pointer == p->right)
                {
                    m_pointer = p;
                    p = p->parent;
                }

                // if we were previously at the right-most node in
                // the tree, m_pointer = nullptr, and the iterator specifies
                // the end of the list
                m_pointer = p;
            }
            return tmp;
        }
        Inorder &operator++()
        {
            Node<T> *p;

            if (root == nullptr)
            {
                // ++ from end(). get the root of the tree
                m_pointer = root;

                // error! ++ requested for an empty tree
                if (m_pointer == nullptr)
                    throw invalid_argument("No");

                // move to the smallest value in the tree,
                // which is the first node inorder
                while (m_pointer->left != nullptr)
                {
                    m_pointer = m_pointer->left;
                }
            }
            else if (m_pointer->right != nullptr)
            {
                // successor is the farthest left node of
                // right subtree
                m_pointer = m_pointer->right;

                while (m_pointer->left != nullptr)
                {
                    m_pointer = m_pointer->left;
                }
            }
            else
            {
                // have already processed the left subtree, and
                // there is no right subtree. move up the tree,
                // looking for a parent for which m_pointer is a left child,
                // stopping if the parent becomes NULL. a non-NULL parent
                // is the successor. if parent is NULL, the original node
                // was the last node inorder, and its successor
                // is the end of the list
                p = m_pointer->parent;
                while (p != nullptr && m_pointer == p->right)
                {
                    m_pointer = p;
                    p = p->parent;
                }

                // if we were previously at the right-most node in
                // the tree, m_pointer = nullptr, and the iterator specifies
                // the end of the list
                m_pointer = p;
            }

            return *this;
        }
        bool operator==(const Inorder &rhs) const
        {
            return m_pointer == rhs.m_pointer;
        }

        bool operator!=(const Inorder &rhs) const
        {
            return m_pointer != rhs.m_pointer;
        }
        Inorder(Node<T> *root)
        {
            
            if (root != nullptr)
            {
                this->root = root;
                while (root->left != nullptr)
                {
                    root = root->left;
                }
                m_pointer = root;
            }
            else
            {
                m_pointer = nullptr;
            }
        }
    };
}