struct Node {
    int value;

    struct Node *left;
    struct Node *right;

    int height;
};

struct Node *MallocNode();
void Print(struct Node *pRoot);
int Insert(struct Node **ppRoot, int val);



/*********************************************************************
4 types of rotations in AVL tree - RR, LL, RL, LR

Balance factor = HeightLeftSubtree - HeightRightSubtree

Balance factor = 0, 1, -1 means tree is balanced

(1)  RR 

10                                                              20
  \                                                            /  \
   \ R                                                      L /    \ R
    \                                                        /      \
     20      ===== counter-clockwise-rotation =====>       10        30
      \
       \ R
        \
        30


(2) LL
            30                                                 20
           /                                                  /  \
        L /                                                L /    \ R
         /                                                  /      \
       20         ===== clockwise-rotation =====>         10        30
       /
    L /
     /
    10

**********************************************************************/

