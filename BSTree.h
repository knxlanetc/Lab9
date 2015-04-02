//--------------------------------------------------------------------
//
//  Laboratory 9                                    BSTree.h
//
//  Class declarations for the linked implementation of the Binary
//  Search Tree ADT -- including the recursive helpers of the
//  public member functions
//
//--------------------------------------------------------------------

#ifndef BSTREE_H
#define BSTREE_H

#include <stdexcept>
#include <iostream>

using namespace std;

template < typename DataType, class KeyType >    // DataType : tree data item
class BSTree                                     // KeyType : key field
{
  public:

    // Constructor
    BSTree ();                         // Default constructor
    BSTree ( const BSTree<DataType,KeyType>& other );   // Copy constructor
    BSTree& operator= ( const BSTree<DataType,KeyType>& other );
						  // Overloaded assignment operator

    // Destructor
    ~BSTree ();

    // Binary search tree manipulation operations
    void insert ( const DataType& newDataItem );  // Insert data item
    bool retrieve ( const KeyType& searchKey, DataType& searchDataItem ) const;
                                                  // Retrieve data item
    bool remove ( const KeyType& deleteKey );            // Remove data item
    void writeKeys () const;                      // Output keys
    void clear ();                                // Clear tree

    // Binary search tree status operations
    bool isEmpty () const;                        // Tree is empty
    // !! isFull() has been retired. Not very useful in a linked structure.

    // Output the tree structure -- used in testing/debugging
    void showStructure () const;

  protected:

    class BSTreeNode                  // Inner class: facilitator for the BSTree class
    {
      public:

        // Constructor
        BSTreeNode ( const DataType &nodeDataItem, BSTreeNode *leftPtr, BSTreeNode *rightPtr );

        // Data members
        DataType dataItem;         // Binary search tree data item
        BSTreeNode *left,    // Pointer to the left child
                   *right;   // Pointer to the right child
    };

    // Recursive helpers for the public member functions
    void insertHelper    ( BSTreeNode *&p, const DataType &newDataItem );
    bool retrieveHelper  ( BSTreeNode *p, const KeyType& searchKey, DataType &searchDataItem ) const;
    bool removeHelper    ( BSTreeNode *&p, const KeyType& deleteKey );
    void writeKeysHelper ( BSTreeNode *p ) const;
    void clearHelper     ( BSTreeNode *p );
    void showHelper      ( BSTreeNode *p, int level ) const;
    void copyTree        ( const BSTree<DataType,KeyType> &otherTree );
    void copyTreeHelper  ( BSTreeNode *&p, const BSTreeNode *otherPtr );

    // Data member
    BSTreeNode *root;   // Pointer to the root node
    BSTreeNode *currentNode; // Pointer to the current node
    BSTreeNode *predecessor; // Pointer to the predecessor node
};

#endif	// define BSTREE_H
