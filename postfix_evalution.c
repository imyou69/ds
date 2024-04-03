// #include <stdio.h>
// #include <stdlib.h>

// #define MAXSIZE 30

// int stack[MAXSIZE];
// int top = -1;

// void push(int item) {
//     if (top != MAXSIZE - 1) {
//         stack[++top] = item;
//     } else {
//         printf("Stack Overflow\n");
//         exit(EXIT_FAILURE);
//     }
// }

// int pop() {
//     if (top != -1) {
//         return stack[top--];
//     } else {
//         printf("Stack Underflow\n");
//         exit(EXIT_FAILURE);
//     }
// }

// int evaluatePostfix(char postfix[]) {
//     int i, operand1, operand2, result;
//     for (i = 0; postfix[i] != '\0'; i++) {
//         if (isdigit(postfix[i])) {
//             push(postfix[i] - '0'); // Convert character to integer and push onto the stack
//         } else {
//             operand2 = pop();
//             operand1 = pop();

//             switch (postfix[i]) {
//                 case '+':
//                     result = operand1 + operand2;
//                     break;
//                 case '-':
//                     result = operand1 - operand2;
//                     break;
//                 case '*':
//                     result = operand1 * operand2;
//                     break;
//                 case '/':
//                     result = operand1 / operand2;
//                     break;
//                 default:
//                     printf("Invalid operator: %c\n", postfix[i]);
//                     exit(EXIT_FAILURE);
//             }

//             push(result);
//         }
//     }
//     return pop();
// }

// int main() {
//     char postfix[MAXSIZE];
//     printf("Enter a valid postfix expression:\n");
//     scanf("%s", postfix);

//     int result = evaluatePostfix(postfix);

//     printf("Result of the postfix expression: %d\n", result);

//     return 0;
// }


#include<stdio.h>
#include<stdlib.h>

#define max 50

int stack[max];
int top = -1;

void push(int item){
    if(top!=max-1){
        stack[++top]=item;
    }else{
        printf("Stack Overflow");
        exit(EXIT_FAILURE);
    }
}

int pop(){
    if(top!=-1){
        return stack[top--];
    }else{
        printf("Stack Underflow");
        exit(EXIT_FAILURE);
    }
}

int etp(char pos[]){
    int i , op1,op2,res;
    for(i=0;pos[i]!='\0';i++){
        if(isdigit(pos[i])){
            push(pos[i] - '0');
        }else{
            op1 = pop();
            op2 = pop();


            switch(pos[i]){
                case '+':
                    res = op1 + op2;
                    break;
                case '-':
                    res = op1 - op2;
                    break;
                case '*':
                    res = op1 * op2;
                    break;
                case '/':
                    res = op1 / op2;
            }
            push(res);
        }
       
    }
    return pop();  
}

int main(){
    char pos[max];

    printf("Enter the expression: \n");
    scanf("%s",pos);

    int res=etp(pos);

    printf("The expression is: %d",res);

    return 0;

}
