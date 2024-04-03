// #include<stdio.h>
// #include<stdlib.h>
// #include<ctype.h>
// #include<string.h>

// #define size 100

// int isOperator(char ch){
//     return(ch == '+' || ch == '-' || ch == '*' || ch == '/');
// }

// int precedence(char op){
//     if(op == '+' || op == '-')
//         return 1;
//     if(op == '*' || op == '/')
//         return 2;
//     return 0;
// }

// void itp(char *inf, char *pos){
//     char stack[size];
//     int top = -1;
//     int i, j=0;

//     for(i=0;inf[i]!='\0';++i){
//         if(isalnum(inf[i])){
//             pos[j++]=inf[i];
//         }else if(isOperator(inf[i])){
//             while(top != -1 && precedence(inf[i])<=precedence(stack[top])){
//                 pos[j++]=stack[top--];
//             }
//             stack[++top]=inf[i];
//         }else if (inf[i]=='('){
//             stack[++top]=inf[i];
//         }else if(inf[i]==')'){
//             while(top!=-1 && stack[top]!='('){
//                 pos[j++]=stack[top--];
//             }
//         if (top!=-1 && stack[top]=='('){
//             --top;
//             }
//         }
//     }
//     while(top!=-1){
//         pos[j++]=stack[top--];
//     }
//     pos[j]='\0';
// }

// int main(){
//     char inf[size], pos[size];

//     printf("enter the expression: ");
//     scanf("%s",inf);

//     itp(inf,pos);

//     printf("The postfix expression is:%s",pos);
//     return 0;
// }


#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define max 100

int isOperator(char ch){
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' );
}

int precendence(char op){
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    return 0;
}

void itp(char *inf, char *pos){
    int j=0, i;
    char stack[max];
    int top = -1;

    for(i=0;inf[i]!='\0';++i){
        if(isalnum(inf[i])){
            pos[j++]=inf[i];
        }else if(isOperator(inf[i])){
            while(top!=-1 && precendence(inf[i])<=precendence(stack[top])){
                pos[j++] = stack[top--];
            }
            stack[++top]=inf[i];
        }else if(inf[i]==')'){
            stack[++top]=inf[i];
        }else if(inf[i]=='('){
            while(top!=-1 && stack[top]!=')'){
                pos[j++]= stack[top--];
            }
            if(top!=-1 && stack[top]==')'){
                --top;
            }
        }
    }
    while(top!=-1){
        pos[j++]=stack[top--];
    }
    pos[j]='\0';
}

int main(){
    char inf[max], pos[max];

    printf("Enter the expression \n");
    scanf("%s",inf);

    itp(inf, pos);

    printf("The postfix expression is: %s ",pos);
    return 0;

}