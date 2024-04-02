// #include<stdio.h>
// #include<stdlib.h>

// struct employee{
//     int id;
//     char name[50];
//     float salary;
// };

// void main(){
//     int n,i,ch,searchid;
//     struct employee emp[5];
//     printf("Enter the number of employee\n");
//     scanf("%d",&n);
//     printf("Enter %d employee details: \n", n);
//     for(i=0;i<n;i++){
//         printf("Enter the employee id:");
//         scanf("%d",&emp[i].id);
//         printf("Enter the name of the employee:");
//         scanf("%s",&emp[i].name);
//         printf("Enter the salary of the employee:");
//         scanf("%f",&emp[i].salary);
//     }

//     while(1){
//         printf("\n 1. Display \n 2.Display \n 3.Exit \n");
//         scanf("%d",&ch);
//         switch(ch){
//             case 1: for(i=0;i<n;i++){
//                 printf("ID of the employee: %d \n Name of the employee: %s \n Salary of the employee: %f \n",emp[i].id,emp[i].name,emp[i].salary);
//             }
//             break;
//             case 2: printf("Enter the employee id: \n");
//                     scanf("%d",&searchid);
//                     for(i=0;i<n;i++){
//                         if(emp[i].id==searchid){
//                             printf("Name of the employee is: %s \n Salary of the employee is: %f",emp[i].name,emp[i].salary);
//                             break;
//                         }
//                     }
//                     if(i==n){
//                         printf("Employee not found");
//                     }
//                     break;
//             case 3: exit(0);
//             break;
//         }
//     }
    
// }

#include <stdio.h>
#include <stdlib.h>

struct employee{
    char name[50];
    int id;
    float salary;
};

void main(){
    int i , n , ch , searchid;
    struct employee emp[5];
    printf("Enter the number of employee \n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\n Name: ");
        scanf("%s",&emp[i].name);
        printf("\n ID: ");
        scanf("%d",&emp[i].id);
        printf("\n Salary: ");
        scanf("%f",&emp[i].salary);
    }
    while(1){
        printf("\n 1.Display All Details:  \n 2.Search \n 3.Exit \n");
        scanf("%d",&ch);
        switch (ch){
            case 1: for(i=0;i<n;i++){
                printf("Employee Name: %s \n Employee ID: %d \n Employee Salary: %f \n",emp[i].name,emp[i].id,emp[i].salary);
            }
            break;
            case 2: printf("Enter the ID to search to search:");
                    scanf("%d",&searchid);
                    for(i=0;i<n;i++){
                        if(searchid==emp[i].id){
                            printf("\n Employee Name: %s \n Employee ID: %d, Employee Salary: %s\n",emp[i].name,emp[i].id,emp[i].salary);
                        }
                    else{
                        printf("ID not found");
                        }
                    }
                    break;
            case 3: exit(0);
                    

        }
    }
}
