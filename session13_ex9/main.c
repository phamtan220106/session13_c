#include <stdio.h>
#include <stdlib.h>
int arr[100][100],n,m,rong=4;
void MENU();
void Array();
void matrix();
void corner();
void border();
void Diagonal();
void primeNumbers();
int main()
{
    int menu;
    while(1){
        MENU();
        scanf("%d",&menu);
        switch(menu){
            case 1:
                printf("\n");
                Array();
                break;
            case 2:
                printf("\n");
                matrix();
                break;
            case 3:
                printf("\n");
                corner();
                break;
            case 4:
                printf("\n");
                border();
                break;
            case 5:
                printf("\n");
                Diagonal();
                break;
            case 6:
                printf("\n");
                primeNumbers();
                break;
            case 7:
                return 0;
            default:
                printf("lua chon khong hop le\n");
                break;
        }

    }
    printf("Hello world!\n");
    return 0;
}
void MENU(){
    printf("1.nhap vao mang hai chieu.\n");
    printf("2.in cac gia tri ra theo ma tran.\n");
    printf("3.in ra cac phan tu o goc tren theo ma tran.\n");
    printf("4.in ra cac phan tu nam tren duong bien theo ma tran.\n");
    printf("5.in ra cac phan tu nam tren duong cheo chinh va duong cheo phu.\n");
    printf("6.in ra cac phan tu la so nguyen to theo ma tran.\n");
    printf("7.thoat.\n");
    printf("\nlua chon cua ban.\n");
}
void Array(){
    printf("nhap vao so hang: ");
    scanf("%d",&n);
    printf("nhap vao so cot: ");
    scanf("%d",&m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("arr[%d][%d]: ",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\n");
}
void matrix(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
void corner(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || i==n-1){
                if(j==0 || j==n-1){
                    printf("%*d ",rong,arr[i][j]);
                }
            }else{
                printf("%*c",rong,' ');
            }
        }
        printf("\n");
    }
}
void border(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || i==n-1 || j==0 || j==m-1){
                printf("%*d",rong,arr[i][j]);
            }else{
                printf("%*c",rong,' ');
            }
        }
        printf("\n");
    }
}
void Diagonal(){
    int x=(n>m)?m:n;
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            if(i==j || i+j==x-1){
                printf("%*d",rong,arr[i][j]);
            }else{
                printf("%*c",rong,' ');
            }
        }
        printf("\n");
    }
}
void primeNumbers(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int flag=1;
            if(arr[i][j]<=1){
                flag=0;
            }
            for(int t=2; t<=sqrt(arr[i][j]);t++){
                if(arr[i][j]%t==0){
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                printf("%*d",rong,arr[i][j]);
            }else{
                printf("%*c",rong,' ');
            }
        }
        printf("\n");
    }
}
