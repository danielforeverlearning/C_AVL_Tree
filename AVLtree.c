
#include <stdio.h>
#include <stdlib.h>
#include "AVLtree.h"

#define HEIGHT_MAX(a, b) ((a) > (b) ? (a) : (b))

struct Node *MallocNode() {
    struct Node *ptr = NULL;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    return ptr;
}

//Using recursion
//DO NOT want to blow the stack, its normally only 65k
void Print(struct Node *ptr) {
    if (ptr != NULL) {

        //go to lowest value node
        while (ptr->left != NULL)
            ptr = ptr->left;

        printf("%d\n", ptr->value);

        Print(ptr->right);
    }
}//Print


int Insert(struct Node **pp, int val) {
    int result = 0;
    int heightLeft = 0;
    int heightRight = 0;

    if ((*pp) != NULL) {
        if (val < ((*pp)->value))
            result = Insert( &((*pp)->left), val );
        else
            result = Insert( &((*pp)->right), val );

        if (result != 0) //error happened
            return result;

        if ((*pp)->left == NULL)
            heightLeft = 0;
        else
            heightLeft = (*pp)->left->height;

        if ((*pp)->right == NULL)
            heightRight = 0;
        else
            heightRight = (*pp)->right->height;

        int BalanceFactor = heightLeft - heightRight;
        if (BalanceFactor == 0 || BalanceFactor == 1 || BalanceFactor == -1) {
            //NO ROTATION
            (*pp)->height = HEIGHT_MAX(heightLeft, heightRight) + 1;
            return 0;
        }
        

    }
    else {
        *pp = MallocNode();
        if (*pp == NULL) {
             //Failed to MallocNode, must be out of heap space
             return -1;
        }
        else {
             (*pp)->value       = val;
             (*pp)->left        = NULL;
             (*pp)->right       = NULL;
             (*pp)->height      = 1;
             return 0;
        }
    }
}//Insert

