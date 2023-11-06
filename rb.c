#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
    int color; 
};


struct Node* root = NULL;


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->color = 1; 
    return newNode;
}


void leftRotate(struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void rightRotate(struct Node* x) {
    struct Node* y = x->left;
    x->left = y->right;
    if (y->right != NULL)
        y->right->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;
    y->right = x;
    x->parent = y;
}


void fixInsertRBTree(struct Node* x) {
    while (x != root && x->parent->color == 1) {
        if (x->parent == x->parent->parent->left) {
            struct Node* y = x->parent->parent->right;
            if (y != NULL && y->color == 1) {
                x->parent->color = 0;
                y->color = 0;
                x->parent->parent->color = 1;
                x = x->parent->parent;
            } else {
                if (x == x->parent->right) {
                    x = x->parent;
                    leftRotate(x);
                }
                x->parent->color = 0;
                x->parent->parent->color = 1;
                rightRotate(x->parent->parent);
            }
        } else {
            struct Node* y = x->parent->parent->left;
            if (y != NULL && y->color == 1) {
                x->parent->color = 0;
                y->color = 0;
                x->parent->parent->color = 1;
                x = x->parent->parent;
            } else {
                if (x == x->parent->left) {
                    x = x->parent;
                    rightRotate(x);
                }
                x->parent->color = 0;
                x->parent->parent->color = 1;
                leftRotate(x->parent->parent);
            }
        }
    }
    root->color = 0;
}


void insertRBTree(int data) {
    struct Node* newNode = createNode(data);
    if (root == NULL) {
     
        newNode->color = 0;
        root = newNode;
    } else {
        struct Node* y = NULL;
        struct Node* x = root;
        while (x != NULL) {
            y = x;
            if (newNode->data < x->data)
                x = x->left;
            else
                x = x->right;
        }
        newNode->parent = y;
        if (y == NULL)
            root = newNode;
        else if (newNode->data < y->data)
            y->left = newNode;
        else
            y->right = newNode;
        if (newNode->parent == NULL) {
            newNode->color = 0; 
            return;
        }
        if (newNode->parent->parent == NULL)
            return;
        fixInsertRBTree(newNode);
    }
}

void inOrderTraversal(struct Node* x) {
    if (x == NULL)
        return;
    inOrderTraversal(x->left);
    printf("%c(%s) ", x->data, x->color == 0 ? "B" : "R");
    inOrderTraversal(x->right);
}

int main() {
    char keys[] = "FSQKCLHTVWMRNPABXYZE";
    int i;
    for (i = 0; i < 20; i++) {
        insertRBTree(keys[i]);
    }

    printf("In-order traversal of RB tree: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
