#include<stdio.h>
#include<stdlib.h>

struct st {
    int data;
    struct st *left;
    struct st *right;
};
typedef struct st* NODE;

struct st *root = NULL, *temp;

void insert() {
    struct st *nc, *pNode;
    int v;
    printf("Enter the value of the node\n");
    scanf("%d", &v);
    temp = (NODE)malloc(sizeof(struct st));
    temp->data = v;
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL) {
        root = temp;
    } else {
        nc = root;
        while (nc != NULL) {
            pNode = nc;
            if (v < nc->data)
                nc = nc->left;
            else
                nc = nc->right;
        }
        if (v < pNode->data) {
            pNode->left = temp;
        } else {
            pNode->right = temp;
        }
    }
}

void preorder(struct st *temp) {
    if (temp != NULL) {
        printf("%d ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void inorder(struct st *temp) {
    if (temp != NULL) {
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}

void postorder(struct st *temp) {
    if (temp != NULL) {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ", temp->data);
    }
}

int main() {
    int ch;
    while (1) {
        printf("\n 1.insert Elements \n 2.preorder \n 3.inorder \n 4.postorder \n 5.exit");
        printf("\n enter your choice ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: insert(); break;
            case 2: preorder(root); break;
            case 3: inorder(root); break;
            case 4: postorder(root); break;
            case 5: exit(0);
            default: printf("Invalid operation");
        }
    }
    return 0;
}
