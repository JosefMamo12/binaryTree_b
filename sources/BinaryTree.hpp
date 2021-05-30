#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include "Preorder.hpp"
#include "Inorder.hpp"
#include "Postorder.hpp"
#include <queue>
#include <algorithm>
#include "Node.hpp"

using namespace std;

namespace ariel
{
    template <class T>
    class BinaryTree
    {
        Node<T> *root;

    public:
        BinaryTree() : root(nullptr){};
        BinaryTree(const BinaryTree<T> &rhs) : root(copyTreeHelper(rhs.root)) {}
        Node<T> *copyTreeHelper(Node<T> *rhs_root)
        {
            if (rhs_root == nullptr)
            {
                return nullptr;
            }
            Node<T> *newNode = new Node<T>(rhs_root->value);
            newNode->left = copyTreeHelper(rhs_root->left);
            if(newNode->left){
                newNode->left->parent = newNode;
            }
            newNode->right = copyTreeHelper(rhs_root->right);
            if(newNode->right){
                newNode->right->parent = newNode;
            }
            return newNode;
        }
        BinaryTree(BinaryTree &&other)noexcept{
                root = other.root;
                other.root = nullptr;
        }
        BinaryTree &operator=(const BinaryTree &other) noexcept
        {
            if (this != &other)
            {
                cout << "Use assigment operator" << endl;
                BinaryTree temp(other);
                swap(temp.root, root);
            }
            return *this;
        }
        BinaryTree &operator=(BinaryTree &&otherBST) noexcept
        {
            if (this != &otherBST)
            {
                destroy_recorsivaly(root);
                root = otherBST.root;
                otherBST.root = nullptr;
            }

            return *this;
        }

        BinaryTree &add_root(T val)
        {
            if (!root)
            {
                Node<T> *curr = new Node<T>(val);
                root = curr;
            }
            else
            {
                root->value = val;
            }
            return *this;
        }
        Node<T> *search_address(Node<T> *curr, T val)
        {
            if (!curr)
            {
                return nullptr;
            }
            if (curr->value == val)
            {
                return curr;
            }

            Node<T> *res1 = search_address(curr->left, val);
            if (res1)
            {
                return res1;
            }
            Node<T> *res2 = search_address(curr->right, val);
            return res2;
        }

        bool search(Node<T> *curr, T val)
        {

            if (!curr)
            {
                return false;
            }
            if (curr->value == val)
            {
                return true;
            }

            bool res1 = search(curr->left, val);
            if (res1)
            {
                return true;
            }
            bool res2 = search(curr->right, val);
            return res2;
        }
        BinaryTree &add_right(T existVal, T val_to_add)
        {
            if (search(root, existVal))
            {
                Node<T> *temp = search_address(root, existVal);
                if (temp->right == nullptr)
                {
                    Node<T> *newNode = new Node<T>(val_to_add);
                    temp->right = newNode;
                    newNode->parent = temp;
                }
                else
                {
                    temp->right->value = val_to_add;
                }
            }
            else
            {
                throw invalid_argument("There is no such a Node");
            }
            return *this;
        }
        BinaryTree &add_left(T existVal, T val_to_add)
        {
            if (search(root, existVal))
            {
                Node<T> *temp = search_address(root, existVal);
                if (temp->left == nullptr)
                {
                    Node<T> *newNode = new Node<T>(val_to_add);
                    temp->left = newNode;
                    newNode->parent = temp;
                }
                else
                {
                    temp->left->value = val_to_add;
                }
            }
            else
            {
                throw invalid_argument("There is no such a Node");
            }
            return *this;
        }

        friend ostream &operator<<(ostream &os, const BinaryTree<T> &a)
        {

            return os;
        }

        Inorder<T> begin()
        {
            return Inorder<T>(root);
        }
        Inorder<T> end()
        {
            return Inorder<T>(nullptr);
        }

        Inorder<T> begin_inorder()
        {
            return Inorder<T>(root);
        }
        Inorder<T> end_inorder()
        {
            return Inorder<T>(nullptr);
        }
        Preorder<T> begin_preorder()
        {
            return Preorder<T>(root);
        }
        Preorder<T> end_preorder()
        {
            return Preorder<T>(nullptr);
        }
        Postorder<T> begin_postorder()
        {
            return Postorder<T>(root);
        }
        Postorder<T> end_postorder()
        {
            return Postorder<T>(nullptr);
        }
        void destroy_recorsivaly(Node<T> *node)
        {
            if (node)
            {
                destroy_recorsivaly(node->left);
                destroy_recorsivaly(node->right);
                delete node;
                node = nullptr;
            }
        }
        ~BinaryTree()
        {
            destroy_recorsivaly(root);
        }
        Node<T> *getRoot()
        {
            return this->root;
        }
    };
}