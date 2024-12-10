#include <stdio.h>
#include <stdlib.h>
#define N 100

int Array(int arr[N]);
void MENU(void);
void print(int cols, int arr[N]);
int add(int arr[N], int cols);
void correct(int arr[N], int cols);
int deletElement(int arr[N], int cols);
void sort(int arr[N], int cols, int num);
void search(int arr[N],int cols, int num,int value);
int binarySearch(int arr[N], int cols, int target);

int main() {
    int menu, cols, arr[N],value;
    char AorB;
    while (1) {
        printf("1. nhap vao mot mang so nguyen.\n");
        printf("!1. thoat.\n");
        printf("nhap lua chon cua ban: ");
        scanf("%d",&menu);
        if (menu==1) {
            cols=Array(arr);
            while (1) {
                MENU();
                scanf("%d",&menu);
                if(menu==8){
                    break;
                }else{
                    switch(menu) {
                        case 1:
                            printf("\nmang ban dang lam viec la:\n");
                            print(cols, arr);
                            break;
                        case 2:
                            printf("\n");
                            cols=add(arr, cols);
                            cols++;
                            break;
                        case 3:
                            printf("\n");
                            correct(arr,cols);
                            break;
                        case 4:
                            printf("\n");
                            cols=deletElement(arr,cols);
                            break;
                        case 5:
                            printf("\n");
                            printf("a.sap sep tang dan.\n");
                            printf("b.sap sep giam dan.\n");
                            printf("lua chon cua ban. ");
                            scanf(" %c", &AorB);
                            sort(arr,cols,AorB);
                            break;
                        case 6:
                            printf("\n");
                            printf("gia tri muon tim kiem: ");
                            scanf("%d",&value);
                            printf("a.tim kiem tuyen tinh.\n");
                            printf("b.tim kiem nhi phan.\n");
                            printf("lua chon cua ban: ");
                            scanf(" %c", &AorB);
                            search(arr,cols,AorB,value);
                            break;
                        case 7:
                            return 0;
                        default:
                            printf("lua chon khong hop le.\n");
                            break;
                    }
                }
            }
        }else{
            return 0;
        }
    }
    printf("Hello world!\n");
    return 0;
}
int Array(int arr[N]) {// nhập vào mảng
    int cols;
    printf("nhap vao so phan tu cua mang: ");
    scanf("%d", &cols);
    for (int i = 0; i < cols; i++) {
        printf("arr[%d] ", i+1);
        scanf("%d", &arr[i]);
    }
    return cols;
}
void MENU(void) { //in menu
    printf("1. in ra gia tri cac phan tu dang quan li.\n");
    printf("2. them mot phan tu vao mot vi tri chi dinh.\n");
    printf("3. sua mot phan tu o vi tri chi dinh.\n");
    printf("4. xoa mot phan tu o vi tri chi dinh.\n");
    printf("5. sap sep cac phan tu.\n");
    printf("6. tim kiem phan tu nhap vao.\n");
    printf("7. thoat.\n");
    printf("8. home.\n");
    printf("\nmoi ban nhap vao lua chon: ");
}
void print(int cols, int arr[N]) { // in mảng
    for (int i = 0; i < cols; i++) {
        printf("arr[%d]: %d\n", i, arr[i]);
    }
}
int add(int arr[N], int cols) { // thêm phần tử
    int index, value;
    printf("nhap vao vi tri va gia tri muon them: ");
    scanf("%d %d", &index, &value);
    for (int i = cols; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    return cols;
}
void correct(int arr[N], int cols){// thay thế phần tử
    int index, value;
    printf("nhap vao vi tri va gia tri muon sua: ");
    scanf("%d %d", &index, &value);
    arr[index]=value;
}
int deletElement(int arr[N],int cols){//xoa phan tử
    int index;
    printf("nhap vao vi tri muon xoa: ");
    scanf("%d", &index);
    for(int i=index; i<cols-1; i++){
        arr[i]=arr[i+1];
    }
    cols--;
    return cols;
}
void sort(int arr[N], int cols,int num){//sap sep
    if(num=='a'){
        for(int i=0; i<cols-1; i++){
            for(int j=0; j<cols-i-1; j++){
                if(arr[j]>arr[j+1]){
                    int temp =arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
        printf("mang sap sep tang dan:\n");
        for(int i=0; i<cols; i++){
            printf("%d ",arr[i]);
        }
    }else if(num=='b'){
        for(int i=0; i<cols-1; i++){
            for(int j=0; j<cols-i-1; j++){
                if(arr[j]<arr[j+1]){
                    int temp =arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
        printf("mang sap sep giam dan:\n");
        for(int i=0; i<cols; i++){
            printf("%d ",arr[i]);
        }
    }else{
        printf("khong hop le\n");
    }
}
void search(int arr[N],int cols, int num,int value){//tìm kiếm
    if(num=='a'){
        for(int i=0; i<cols; i++){
            if(arr[i]==value){
                printf("phan tu %d co trong mang va nam o vi tri thu %d\n",value,i+1);
                break;
            }
        }
        printf("phan tu %d khong co trong mang\n",value);
    }else if(num=='b'){
        for(int i=0; i<cols-1; i++){
            for(int j=0; j<cols-i-1; j++){
                if(arr[j]>arr[j+1]){
                    int temp =arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
        printf("mang da dc sap sep lai theo thu tu tang dan:\n");
        int a=binarySearch(arr,cols,value);
        if(a!=-1){
            printf("phan tu %d co trong mang va nam o vi tri thu %d\n",value,a);
        }else{
            printf("phan tu %d khong co trong mang\n",value);
        }
    }
}
int binarySearch(int arr[N], int cols, int target){//tìm kiếm nhị phân
    int left=0;
    int right=cols-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid]>target){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    return -1;
}
