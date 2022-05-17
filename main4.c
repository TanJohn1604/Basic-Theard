#include<stdio.h>
#include<pthread.h>

void * hello_fun(){

    return (void*)"return mess";
}

int main(){
    char *data;
    pthread_t thread =0;
    pthread_create(&thread,NULL,hello_fun,NULL);
    pthread_join(thread,(void**)&data);
    //pthread_exit(NULL); phai xoa dong exit nay
    printf("String return = %s",data);
    return 0;
}