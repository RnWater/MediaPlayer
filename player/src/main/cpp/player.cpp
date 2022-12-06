#include <jni.h>
#include <string>
#include "PLogger.h"
#include "pthread.h"
#include "queue"
pthread_t thread;
void *normalThread(void *data){
    LOGE("线程创建成功");
    pthread_exit(&thread);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_henry_player_GCPlayer_normalThread(JNIEnv *env, jobject thiz) {
    pthread_create(&thread, NULL, normalThread, NULL);
}
pthread_t custom,product;
pthread_cond_t cond;
pthread_mutex_t mutex;
std::queue<int> queue;
void *productThread(void *data){

    while (1){
        pthread_mutex_lock(&mutex);
        queue.push(1);
        LOGE("生产者线程生产");
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(&thread);
}
void *customThread(void *data){
    LOGE("消费者线程创建成功");
    while (1){
        pthread_mutex_lock(&mutex);
        if (queue.size() > 1) {
            queue.pop();
        }else{

        }
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(&thread);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_henry_player_GCPlayer_queueThread(JNIEnv *env, jobject thiz) {
    for (int i = 0; i < 10; i++) {
        queue.push(i);
    }
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
    pthread_create(&product, NULL, productThread, NULL);
    pthread_create(&custom, NULL, customThread, NULL);

}