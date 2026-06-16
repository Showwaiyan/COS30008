
// COS30008, Problem Set 4, Problem 3, 2022

#pragma once

#include "BinarySearchTree.h"

#include <stack>

template<typename T>
class BinarySearchTreeIterator
{
private:
    
    using BSTree = BinarySearchTree<T>;
    using BNode = BinaryTreeNode<T>;
    using BTreeNode = BNode*;
    using BTNStack = std::stack<BTreeNode>;

    const BSTree& fBSTree;		// binary search tree
    BTNStack fStack;			// DFS traversal stack
    
    void pushLeft( BTreeNode aNode );
    
public:
    
    using Iterator = BinarySearchTreeIterator<T>;
    
    BinarySearchTreeIterator( const BSTree& aBSTree );

    const T& operator*() const;
    Iterator& operator++();
    Iterator operator++(int);
    bool operator==( const Iterator& aOtherIter ) const;
    bool operator!=( const Iterator& aOtherIter ) const;
    
    Iterator begin() const;
    Iterator end() const;
};

template<typename T>
void BinarySearchTreeIterator<T>::pushLeft( BTreeNode aNode )
{
    while ( !aNode->empty() )
    {
        fStack.push( aNode );
        aNode = aNode->left;
    }
}

template<typename T>
BinarySearchTreeIterator<T>::BinarySearchTreeIterator( const BSTree& aBSTree ) :
    fBSTree( aBSTree )
{}

template<typename T>
const T& BinarySearchTreeIterator<T>::operator*() const
{
    return fStack.top()->key;
}

template<typename T>
typename BinarySearchTreeIterator<T>::Iterator& BinarySearchTreeIterator<T>::operator++()
{
    BTreeNode lNode = fStack.top();
    fStack.pop();
    pushLeft( lNode->right );
    return *this;
}

template<typename T>
typename BinarySearchTreeIterator<T>::Iterator BinarySearchTreeIterator<T>::operator++(int)
{
    Iterator lCopy = *this;
    ++(*this);
    return lCopy;
}

template<typename T>
bool BinarySearchTreeIterator<T>::operator==( const Iterator& aOtherIter ) const
{
    return &fBSTree == &aOtherIter.fBSTree && fStack == aOtherIter.fStack;
}

template<typename T>
bool BinarySearchTreeIterator<T>::operator!=( const Iterator& aOtherIter ) const
{
    return !( *this == aOtherIter );
}

template<typename T>
typename BinarySearchTreeIterator<T>::Iterator BinarySearchTreeIterator<T>::begin() const
{
    Iterator lCopy = *this;
    lCopy.fStack = BTNStack();
    lCopy.pushLeft( fBSTree.fRoot );
    return lCopy;
}

template<typename T>
typename BinarySearchTreeIterator<T>::Iterator BinarySearchTreeIterator<T>::end() const
{
    Iterator lCopy = *this;
    lCopy.fStack = BTNStack();
    return lCopy;
}
