// binary tree traversal methods

#include <iostream>
#include "arrayQueue.h"
#include "binaryTreeNode.h"
#include "myExceptions.h"

using namespace std;

template <class T>
void visit(binaryTreeNode<T>* x)
{// visit node *x, just output element field.
    cout << x->element << ' ';
}

template <class T>
void preOrder(binaryTreeNode<T>* t)
{
    //Complete the code
    if (t != NULL)
    {
        visit(t);
        preOrder(t->leftChild);
        preOrder(t->rightChild);
    }
}

template <class T>
void inOrder(binaryTreeNode<T>* t)
{
    //Complete the code below
    if (t != NULL)
    {
        inOrder(t->leftChild);
        visit(t);
        inOrder(t->rightChild);
    }
}

template <class T>
void postOrder(binaryTreeNode<T>* t)
{
    //Complete the code below
    if (t != NULL)
    {
        postOrder(t->leftChild);
        postOrder(t->rightChild);
        visit(t);
   }
}

template <class T>
void levelOrder(binaryTreeNode<T>* t)
{
    //Complete the code below
    arrayQueue<binaryTreeNode<T>*> q;
    
    while (t != NULL)
    {
        visit(t);
        if (t->leftChild)
            q.push(t->leftChild);
        if (t->rightChild)
            q.push(t->rightChild);
        try {
            t = q.front();
        }
        catch (queueEmpty) {
            return;
        }
        q.pop();
    }
    

}

int main(void)
{
    /*
  // Sample: create a binary tree: Sample
  binaryTreeNode<int> *top, *left, *right;
  left = new binaryTreeNode<int> (4);
  right = new binaryTreeNode<int> (5);
  head = new binaryTreeNode<int> (2, y, z);

  // Sample: traverse x in all ways
  cout << "Inorder: ";
  inOrder(head);
  cout << endl;
  */

  /* Your input tree:
   *
   *          1
   *	      / \
   *        2   3
   *       / \
   *      4   5
   *
   */

   /* Your output:
    *
    * $> ./binaryTreeTraversals
    *
    *     Inorder: 4 2 5 1 3
    *     Preorder: 1 2 4 5 3
    *     Postorder: 4 5 2 3 1
    *     Level order: 1 2 3 4 5
    *
    */

    //Complete the code below

    binaryTreeNode<int>* root, * left, * right, * top, * r_right;
    left = new binaryTreeNode<int>(4);
    right = new binaryTreeNode<int>(5);
    top = new binaryTreeNode<int>(2, left, right);
    r_right = new binaryTreeNode<int>(3);
    root = new binaryTreeNode<int>(1, top, r_right);

    cout << "Preorder : ";
    preOrder(root);
    cout << endl;
    cout << "Inorder : ";
    inOrder(root);
    cout << endl;
    cout << "Postorder : ";
    postOrder(root);
    cout << endl;
    cout << "Level Order : ";
    levelOrder(root);
    cout << endl;



    return 0;
}
