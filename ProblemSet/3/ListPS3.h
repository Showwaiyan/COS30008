
// COS30008, List, Problem Set 3, 2022

#pragma once

#include "DoublyLinkedList.h"
#include "DoublyLinkedListIterator.h"

#include <stdexcept>

template<typename T>
class List
{
private:
	// auxiliary definition to simplify node usage
	using Node = DoublyLinkedList<T>;

	Node* fRoot;	// the first element in the list
	size_t fCount;	// number of elements in the list

public:
	// auxiliary definition to simplify iterator usage
    using Iterator = DoublyLinkedListIterator<T>;

	~List()                                                             // destructor - frees all nodes
    {
        while ( fRoot != nullptr )
        {
            if ( fRoot != &fRoot->getPrevious() )                       // more than one element
            {
                Node* lTemp = const_cast<Node*>(&fRoot->getPrevious()); // select last
                
                lTemp->isolate();                                       // remove from list
                delete lTemp;                                           // free
            }
            else
            {
                delete fRoot;                                           // free last
                break;                                                  // stop loop
            }
        }
    }

    void remove( const T& aElement )	                                // remove first match from list
    {
        Node* lNode = fRoot;                                            // start at first
        
        while ( lNode != nullptr )                                      // Are there still nodes available?
        {
            if ( **lNode == aElement )                                  // Have we found the node?
            {
                break;                                                  // stop the search
            }

            if ( lNode != &fRoot->getPrevious() )                       // not reached last
            {
                lNode = const_cast<Node*>(&lNode->getNext());           // go to next
            }
            else
            {
                lNode = nullptr;                                        // stop search
            }
        }
        
        // At this point we have either reached the end or found the node.
        if ( lNode != nullptr )                                         // We have found the node.
        {
            if ( fCount != 1 )                                          // not the last element
            {
                if ( lNode == fRoot )
                {
                    fRoot = const_cast<Node*>(&fRoot->getNext());       // make next root
                }
            }
            else
            {
                fRoot = nullptr;                                        // list becomes empty
            }
            
            lNode->isolate();                                           // isolate node
            delete lNode;                                               // release node's memory
            fCount--;                                                   // decrement count
        }
    }

	//////////////////////////////////////////////////////////////////
    //// PS3
    //////////////////////////////////////////////////////////////////
    
	// P1

    List() :
        fRoot(nullptr),
        fCount(0)
    {}

    bool empty() const
    {
        return fRoot == nullptr;
    }

    size_t size() const
    {
        return fCount;
    }

    void push_front( const T& aElement )
    {
        Node* lNode = new Node( aElement );
        
        if ( fRoot == nullptr )
        {
            fRoot = lNode;
        }
        else
        {
            fRoot->push_front( *lNode );
            fRoot = lNode;
        }
        
        fCount++;
    }

    Iterator begin() const
    {
        return Iterator( fRoot );
    }

    Iterator end() const
    {
        return Iterator( fRoot ).end();
    }

    Iterator rbegin() const
    {
        return Iterator( fRoot ).rbegin();
    }

    Iterator rend() const
    {
        return Iterator( fRoot ).rend();
    }

    void push_back( const T& aElement )         // adds aElement at back
    {
        Node* lNode = new Node( aElement );
        
        if ( fRoot == nullptr )
        {
            fRoot = lNode;
        }
        else
        {
            fRoot->push_front( *lNode );
        }
        
        fCount++;
    }

	// P3

    const T& operator[]( size_t aIndex ) const  // list indexer
    {
        if ( aIndex >= fCount )
        {
            throw std::out_of_range( "Index out of bounds." );
        }
        
        const Node* lNode = fRoot;
        for ( size_t i = 0; i < aIndex; ++i )
        {
            lNode = &lNode->getNext();
        }
        
        return **lNode;
    }

    List( const List& aOtherList ) :            // copy constructor
        fRoot( nullptr ),
        fCount( 0 )
    {
        *this = aOtherList;
    }

    List& operator=( const List& aOtherList )   // assignment operator
    {
        if ( this != &aOtherList )
        {
            this->~List();
            fRoot = nullptr;
            fCount = 0;
            
            for ( const T& lElement : aOtherList )
            {
                push_back( lElement );
            }
        }
        
        return *this;
    }
    
    List( List&& aOtherList ) :                 // move constructor
        fRoot( aOtherList.fRoot ),
        fCount( aOtherList.fCount )
    {
        aOtherList.fRoot = nullptr;
        aOtherList.fCount = 0;
    }

    List& operator=( List&& aOtherList )        // move assignment operator
    {
        if ( this != &aOtherList )
        {
            this->~List();
            fRoot = aOtherList.fRoot;
            fCount = aOtherList.fCount;
            
            aOtherList.fRoot = nullptr;
            aOtherList.fCount = 0;
        }
        
        return *this;
    }

    void push_front( T&& aElement )             // move push_front
    {
        Node* lNode = new Node( std::move( aElement ) );
        
        if ( fRoot == nullptr )
        {
            fRoot = lNode;
        }
        else
        {
            fRoot->push_front( *lNode );
            fRoot = lNode;
        }
        
        fCount++;
    }

    void push_back( T&& aElement )              // move push_back
    {
        Node* lNode = new Node( std::move( aElement ) );
        
        if ( fRoot == nullptr )
        {
            fRoot = lNode;
        }
        else
        {
            fRoot->push_front( *lNode );
        }
        
        fCount++;
    }
};

