#include <stdio.h>
#include <stdlib.h>
void generalWishes();
int main()
{
    generalWishes();
    printf("Hello world!\n");
    return 0;
}
void generalWishes(){
    int a,b;
    printf("moi ban nhap vao so a: ");
    scanf("%d",&a);
    printf("moi ban nhap vao so b: ");
    scanf("%d",&b);
    int x=a,y=b;
    if(a<b){
        int x=a;
        a=b;
        b=x;
    }
    int r=a%b;
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }
    printf("uoc chung lon nhat cua %d va %d la: %d\n",x,y,b);
}
