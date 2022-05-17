#include<stdio.h>
#include<pthread.h>

void * hello_fun(void *data){
    printf("Hello World %s \n",(char*)data);
    return NULL;
}

int main(){
    char data[]="test argu";
    pthread_t thread =0;
    pthread_create(&thread,NULL,hello_fun,(void*)data);
    pthread_join(thread,NULL);
    pthread_exit(NULL);
    return 0;
}