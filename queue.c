// #include<stdio.h>
// #include<stdlib.h>

// #define max 5

// int rear=-1;
// int front=-1;
// int a[max];

// void push(){
//     if(rear==max-1){
//         printf("Queue is full");
//         return;
//     }
//     else{
//         int item;
//         if(front==-1)
//             front=0;
//             printf("Enter your number");
//             scanf("%d",&item);
//             rear++;
//             a[rear]=item;
//             printf("Element %d is successfully added into the queue",item);
//     }
// }

// void pop(){
//     if(front==-1){
//         printf("Queue is empty");
//         return;
//     }else{
//         printf("Element %d has popped out",a[front]);
//         if(front==rear)
//             front = rear = -1;
//         else
//             front++;
//     }
// }

// void display(){
//     if(front==-1){
//         printf("Queue is empty");
//         return;
//     }else{
//         int i;
//         for(i=front;i<=rear;i++){
//             printf("%d\t",a[i]);
//         }
//     }
// }

// void main(){
//     int ch=1;
//     while(ch){
//         printf("Enter your choice");
//         scanf("%d",&ch);
//         switch(ch){
//             case 1:push();
//             break;
//             case 2:pop();
//             break;
//             case 3: display();
//             break;
//             case 4: exit(0);
//             break;
//         }
//     }
// }


#include<stdio.h>
#include<stdlib.h>
#define max 10

int f =-1;
int r=-1;
int a[max];

void push(){
    
    if(r==max-1){
        printf("queue is full");
        return;
    }
    else{
        int item;
        if(f==-1)
            f=0;
            printf("Enter the element: ");
            scanf("%d",&item);
            r++;
            a[r]=item;
            
    
    }
}

void pop(){
    if(f==-1){
        printf("Queue is empty");
        return;
    }
    else{
        printf("The element %d has been popped out",a[f]);
        if(f==r)
            f=r=-1;
        
        else
            f++;
    }
}


void display(){
    int i;
    if(f==-1){
        printf("Queue is empty");
        return;
    }
    else{
        for(i=f;i<=r;i++){
            printf("%d",a[i]);
        }
    }
}

void main(){
    int ch=1;
    while(ch){
        printf("push, pop , display");
        scanf("%d",&ch);
        switch(ch){
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
        }
    }
}