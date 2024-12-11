#include <stdio.h>
#include <stdlib.h>
void array();
int main()
{
    array();
    printf("Hello world!\n");
    return 0;
}
void array(){
    int n,m;
    printf("nhap so hang: ");
    scanf("%d",&n);
    printf("nhap so cot: ");
    scanf("%d",&m);
    int Arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d",&Arr[i][j]);
        }
    }
    printf("mang cua ban la:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d ",Arr[i][j]);
        }
        printf("\n");
    }
}
