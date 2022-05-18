#include<stdio.h>
#include<pthread.h>

void *call(){
    printf("thread id = %d\n", pthread_self());
    return NULL;
}

int main(){
    pthread_t thread;
    pthread_create(&thread,NULL,call,NULL);
    /*hàm này sẽ đứng đợi khi thread nó chạy xong thì main
    mới chạy tiếp*/
    pthread_join(thread,NULL);
    printf("main thread id = %d\n", thread);
    /*hàm này sẽ thoát khỏi main thread nhưng những 
    thread tạo từ main vẫn sẽ chạy đến khi hoàn tất*/
    pthread_exit(NULL);
    return 0;
}