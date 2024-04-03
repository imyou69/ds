// #include<stdio.h>

// #define MAX_SIZE 100

// int main() {
//     int mat[MAX_SIZE][MAX_SIZE], sparse[MAX_SIZE * MAX_SIZE][3];
//     int i, j, mr, mc, nzero = 0,  s = 1, elem;

//     printf("Enter number of rows:\n");
//     scanf("%d", &mr);
//     printf("Enter number of columns:\n");
//     scanf("%d", &mc);

//     printf("Enter the matrix:\n");
//     for (i = 0; i < mr; i++) {
//         for (j = 0; j < mc; j++) {
//             scanf("%d", &mat[i][j]);
//             if (mat[i][j] != 0) {
//                 nzero++;
//                 sparse[s][0] = i;
//                 sparse[s][1] = j;
//                 sparse[s][2] = mat[i][j];
//                 s++;
//             }
//         }
//     }

//     sparse[0][0] = mr;
//     sparse[0][1] = mc;
//     sparse[0][2] = nzero;

//     printf("\nSparse matrix is:\n");
//     for (i = 0; i <= nzero; i++) {
//         for (j = 0; j < 3; j++) {
//             printf("%d ", sparse[i][j]);
//         }
//         printf("\n");
//     }

//     printf("Enter the element to be searched:\n");
//     scanf("%d", &elem);

//     for (i = 1; i <= nzero; i++) {
//         if (sparse[i][2] == elem) {
//             printf("Element found at (row, col) = (%d, %d)\n", sparse[i][0], sparse[i][1]);
//             return 0;
//         }
//     }

//     printf("Element not found\n");
//     return 0;
// }

#include<stdio.h>

#define max 100

int main(){
    int mat[max][max], sparse[max*max][3];
    int i , j, mc, mr , nzero=0, s=1,elem;

    printf("Enter the number of rows");
    scanf("%d",&mr);
    printf("Enter the number of column");
    scanf("%d",&mc);

    printf("Enter the matrix");
    for(i=0;i<mr;i++){
        for(j=0;j<mc;j++){
            scanf("%d",&mat[i][j]);
            if(mat[i][j]!=0){
                nzero++;
                sparse[s][0]=i;
                sparse[s][1]=j;
                sparse[s][2]=mat[i][j];
                s++;
            }
            
        }
    }
    sparse[0][0]=mr;
    sparse[0][1]=mc;
    sparse[0][2]=nzero;

    printf("The sparse matrix is: ");
    for(i=0;i<=nzero;i++){
        for(j=0;j<3;j++){
            printf("%d",sparse[i][j]);
        }
        printf("\n");
    }
    printf("Enter the element that needs to be searched: ");
    scanf("%d",&elem);
    for(i=1;i<=nzero;i++){
        if(sparse[i][2]==elem){
            printf("The element is in (row,col)",sparse[i][0],sparse[i][1]);
            return 0;
        }
    }
    printf("Element not found \n");
    return 0;

}