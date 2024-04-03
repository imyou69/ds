#include <stdio.h> 
#include <stdlib.h> 

struct node { 
    int info;
    struct node *llink;
    struct node *rlink;
};

struct node *first = NULL;

void insertfront() { 
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->llink = temp->rlink = NULL;
    printf("Enter the node to be inserted: \n");
    scanf("%d", &temp->info);
    if(first == NULL) { 
        first = temp;
        return;
    } 
    temp->rlink = first;
    first->llink = temp;
    first = temp;
} 

void insertleft() { 
    int key;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->llink = temp->rlink = NULL;
    if (first == NULL) { 
        printf("List is empty!!\n");
        return;
    } 
    printf("Enter the key before which node is to be inserted: \n");
    scanf("%d", &key);
    printf("Enter the node to be inserted:\n");
    scanf("%d", &temp->info);
    struct node *prev = NULL;
    struct node *cur = first;
    while (cur != NULL) { 
        if (cur->info == key && cur == first) { 
            temp->rlink = cur;
            cur->llink = temp;
            first = temp;
            return;
        } 
        if (cur->info == key) { 
            temp->rlink = cur;
            cur->llink = temp;
            temp->llink = prev;
            prev->rlink = temp;
            return;
        } 
        prev = cur;
        cur = cur->rlink;
    } 
    printf("Key not found\n");
} 

void Delete() { 
    int key;
    printf("Enter the node to be deleted:\n");
    scanf("%d", &key);
    if (first == NULL) { 
        printf("List is empty \n");
        return;
    } 
    if (first->rlink == NULL) { 
        if (key == first->info) { 
            printf ("%d node is deleted\n", key);
            free(first);
            first = NULL;
            return;
        } 
        else { 
            printf("Key not found!\n");
            return;
        } 
    } 
    struct node *cur = first;
    while (cur != NULL) { 
        if (cur->info == key) { 
            if (cur == first) { 
                first = first->rlink;
                printf ("%d node is deleted\n", key);
                free(cur);
                return;
            } 
            if (cur->rlink == NULL) { 
                struct node *prev = cur->llink;
                prev->rlink = NULL;
                printf("%d node is deleted\n", key);
                free(cur);
                return;
            } 
            struct node *prev = cur->llink;
            struct node *next = cur->rlink;
            prev->rlink = next;
            next->llink = prev;
            printf("%d node is deleted\n", key);
            free(cur);
            return;
        } 
        cur = cur->rlink;
    } 
    printf("Key not found\n");
} 

void display () { 
    if (first == NULL) { 
        printf("List is empty \n");
        return;
    } 
    printf("List is:\n");
    struct node *cur = first;
    while (cur != NULL) { 
        printf("%d \n", cur->info);
        cur = cur->rlink;
    } 
} 

int main() { 
    int ch;
    printf("MENU\n1)Insert at front \n2)Insert before a node \n3)Delete at node\n4)Display\n");
    while (1) { 
        printf("Enter your choice: \n");
        scanf("%d", &ch);
        switch (ch) { 
            case 1:
                insertfront();
                break;
            case 2:
                insertleft();
                break;
            case 3:
                Delete();
                break;
            case 4:
                display();
                break;
            default:
                exit(0);
        } 
    } 
    return 0;
} 
