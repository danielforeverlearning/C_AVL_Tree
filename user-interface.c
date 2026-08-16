/* sudo apt install make */
/* sudo apt install gcc */

#include <stdio.h>
#include <unistd.h>
#include "AVLtree.h"


int main() {

    int scanf_result = 0;
    int choice = 0;
    
    struct Node *root_ptr = NULL;

    while (true) {
         choice = 0;
         printf("(0): Exit\n");
         printf("(1): Insert\n");
         printf("Choice:");
         
         scanf_result = scanf("%d", &choice);
         if (scanf_result == 0) {
             printf("dirty exit\n");
             break;
         }
         else { //number choice
             if (choice == 0) {
                 printf("clean exit\n");
                 break;
             }
             else if (choice == 1) {
                 printf("Please enter a value:\n");
                 scanf_result = scanf("%d", &choice);
                 if (scanf_result == 0) {
                     printf("not a node value exit\n");
                     break;
                 }
                 else {
                     int result = Insert(&root_ptr, choice);
                     if (result == -1) {
                         printf("Insert: Failed to malloc node!, Exiting!\n");
                         break;
                     }
                     else {
                         printf("Printing AVL Tree\n");
                         printf("*************************************\n");
                         Print(root_ptr);
                     }
                 }
             }
             else {
                 printf("Bad choice, exiting!\n");
                 break;
             }
         }//number choice
    }//while
    return 0;
}//main

