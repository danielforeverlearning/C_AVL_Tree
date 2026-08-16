
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

        if (ptr->left != NULL)
            Print(ptr->left);

        printf("%d\n", ptr->value);

        Print(ptr->right);
    }
}//Print


void CalculateLeftAndRightHeight(struct Node **pp, int *height_left_ptr, int *height_right_ptr) {

        if ((*pp)->left == NULL)
            *height_left_ptr  = 0;
        else
            *height_left_ptr = (*pp)->left->height;

        if ((*pp)->right == NULL)
            *height_right_ptr = 0;
        else
            *height_right_ptr = (*pp)->right->height;
}//CalculateLeftAndRightHeight


int Insert(struct Node **pp, int val) {
    int result = 0;
    int heightLeft = 0;
    int heightRight = 0;

    if ((*pp) != NULL) { // non-NULL root
        if (val < ((*pp)->value))
            result = Insert( &((*pp)->left), val );
        else
            result = Insert( &((*pp)->right), val );

        if (result != 0) //error happened
            return result;

        CalculateLeftAndRightHeight(pp, &heightLeft, &heightRight);

        int BalanceFactor = heightLeft - heightRight;
        if (BalanceFactor == 0 || BalanceFactor == 1 || BalanceFactor == -1) {
            //NO ROTATION
            (*pp)->height = HEIGHT_MAX(heightLeft, heightRight) + 1;
            return 0;
        }
        else if (BalanceFactor == -2) {
            //RR rotate
            struct Node *new_left_ptr  = (*pp);
            struct Node *old_right_ptr = (*pp)->right;

            *pp = old_right_ptr;
            (*pp)->left = new_left_ptr;
            (*pp)->left->height = (*pp)->left->height - 1;
            (*pp)->left->right  = NULL;

            CalculateLeftAndRightHeight(pp, &heightLeft, &heightRight);

            //should we calculate BalanceFactor again just to doublecheck ??

            (*pp)->height = HEIGHT_MAX(heightLeft, heightRight) + 1;
            return 0;
        }
    }// non-NULL root
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

