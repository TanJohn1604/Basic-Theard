#include<stdio.h>
#include<pthread.h>


pthread_mutex_t lock= PTHREAD_MUTEX_INITIALIZER;
int j=0;
void *do_process(){
    pthread_mutex_lock(&lock);//---------------------------lock
    int i=0;
    j++;
    while(i<5){
    printf("j = %d, id = %d\n",j,pthread_self());
    sleep(1);
    i++;
    }

    pthread_mutex_unlock(&lock);//---------------------------unlock
    return NULL;
}
int main(){
    int err=0;
    pthread_t t1,t2;
    if(pthread_mutex_init(&lock,NULL)!=0){
        printf("Mutex init fail \n");
        return 1;
    }
    j=0;
    pthread_create(&t1,NULL,do_process,NULL);
    pthread_create(&t2,NULL,do_process,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}