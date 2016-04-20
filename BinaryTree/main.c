//
//  main.c
//  BinaryTree
//
//  Created by Sunil Kumar on 20/04/16.
//  Copyright © 2016 Sunil Kumar. All rights reserved.
//

#include <stdio.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

void insert(struct node ** root, int value) {
    
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = value;
    temp ->left = NULL;
    temp -> right = NULL;
    
    if (*root == NULL) {
        *root = temp;
    } else {
        struct node *temp2 = *root;
        struct node *save = NULL;
        while (temp2 != NULL) {
            save = temp2;
            if (temp2 -> data < value) {
                temp2 = temp2 -> right;
            } else {
                temp2 = temp2 -> left;
            }
        }
        if (save -> data > value) {
            save ->left = temp;
        } else {
            save ->right = temp;
        }
    }
    
}

void print(struct node *root) {
    if (root) {
        print(root ->left);
        printf("%d ", root ->data);
        print(root -> right);
    }
}

int checkMirrorTree(struct node *r1, struct node *r2) {
    if (r1 == NULL && r2 == NULL) {
        return 1;
    } else if (r1 == NULL ||  r2 == NULL){
        return 0;
    } else {
        if (r1 -> data == r2 -> data) {
            return (checkMirrorTree(r1 -> left, r2 -> right)) && (checkMirrorTree(r1 ->right, r2 ->left));
        } else {
            return 0;
        }
    }
}

struct node * mirrorTree(struct node *root) {
    if (root) {
        mirrorTree(root ->left);
        mirrorTree(root ->right);
        struct node *temp = root ->left;
        root ->left = root ->right;
        root ->right = temp;
    }
    return root;
}

void printPredSucc(struct node *root, int value) {
    static int flag = 0;
    static int flag2 = 0;
    if (root == NULL) {
        return;
    } else {
        if (root -> data == value) {
            flag = 1;
        }
        printPredSucc(root -> left, value);
        if (flag == 1) {
            printf("pred: %d",root ->data);
            flag = 0;
        }
        if (root -> data == value) {
            printf(" value: %d", root -> data);
            flag2 = 1;
        }
        printPredSucc(root -> right, value);
        if (flag2 == 1) {
            printf("succ: %d",root ->data);
            flag2 = 0;
        }
        
    }
}

int main(int argc, const char * argv[]) {
    struct node *root = NULL;
    struct node *root1 = NULL;
    struct node *root2 = NULL;
    insert(&root,1);
    insert(&root,2);
    insert(&root,3);
    insert(&root,4);
    insert(&root,5);
    insert(&root,6);
    insert(&root,7);
    insert(&root,8);
    print(root);
    insert(&root1,10);
    insert(&root1,5);
    insert(&root1,15);
    insert(&root1,7);
    insert(&root1,3);
    printf("\n tree1\n");
    print(root1);
    printPredSucc(root1, 5);
    struct node *root3 = mirrorTree(root1);
    printf(" \n tree3\n");
    print(root3);
    printf("\n tree1\n");
    print(root1);
    int val = checkMirrorTree(root1, root3);
    printf("mirror tree %d",val);
    return 0;
}