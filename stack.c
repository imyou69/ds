// #include<stdio.h>
// #include<stdlib.h>
// #define max 5

// int top = -1;
// int a[max];

// void push(){
//     int item;
//     if(top == max-1){
//         printf("Stack is full");
//         return;
//     }
//     else{
//         printf("Enter the number: ");
//         scanf("%d", &item);
//         a[++top] = item;
//         printf("The number %d is successfully to your stack\n",item);
//     }
// }

// void pop(){
//     if(top==-1){
//         printf("Stack is empty");
//         return;
//     }
//     else{
//         printf("The element %d has been popped out",a[top] );
//         top--;
//     }
// }

// void display(){
//     int i;
//     if(top==-1){
//         printf("Stack is empty");
//     }
//     else{
//         printf("The elements are: \n");
//         for(i=top;i>=0;i--){
//             printf("%d \t \n", a[i]);
//         }
//     }
// }

// void main(){
//     int ch=1;
//     while(ch){
//         printf("\n 1. Push \n 2. Pop \n 3. Display \n 4. Exit \n");
//         printf("Enter your choice: \n");
//         scanf("%d",&ch);
//         switch(ch){
//             case 1: push();
//             break;
//             case 2: pop();
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
#define max 100
int rear =-1;
int a[max];

void push(){
    int item;
    if(rear==max-1){
        printf("Stack is full");
        return;
    }
    printf("Enter the element to push: ");
    scanf("%d",&item);
    a[++rear]=item;
    return;
}

void pop(){
    if(rear==-1){
        printf("Stack is empty!");
    }
    else{
         printf("The number %d has popped out successfully!",a[rear]);
         rear--;
         return;
    }
}

void display(){
    int i;
    if(rear==-1){
        printf("Stack is empty");
    }
    else{
        printf("The elements are: \n");
        for(i=rear;i>=0;i--){
            printf("%d", a[i]);
        }
    }
}

void main(){
    int ch=1;
    while(ch){
    printf("Enter 1, Enter 2 , Enter 3 ");
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