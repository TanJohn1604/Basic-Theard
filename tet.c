#include<stdio.h>
#include<pthread.h>



int main(){
    void **a;
    int b=4;
    int *data=&b;
    a=&data;
    printf("dia chi a %d\n",a);
    printf("gia tri *a %d\n",*a);
    printf("gia tri **a %d\n",*(int*)*a);
    printf("dia chi data %d\n",data);
    printf("gia tri *data %d\n",*data);
    return 0;
}