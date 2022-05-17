#include<stdio.h>
#include<pthread.h>
struct argu
{
int a;
char b[20];
};


void * hello_fun(void *data){
    struct argu *temp= (struct argu *)data;
    
    printf("Hello World \na = %d\nb = %s",temp->a,temp->b);
    return NULL;
}

int main(){
    struct argu data={34,"sa"};

    pthread_t thread =0;
    pthread_create(&thread,NULL,hello_fun,(void*)&data);
    pthread_join(thread,NULL);
    pthread_exit(NULL);
    return 0;
}