#pragma once
#include <iostream>
#include "BinaryTree.hpp"

using namespace std;

namespace ariel
{
    template <class T>
    struct Node
    {
   
        T value;
        Node *right;
        Node *left;
        Node *parent;

       Node( const T & theElement)
	: value{ theElement }, left{ nullptr }, right{ nullptr }, parent { nullptr } { }
    };
}
