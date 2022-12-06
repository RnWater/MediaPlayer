//
// Created by Henry on 2022/12/5.
//

#ifndef MEDIAPLAYER_PLOGGER_H
#define MEDIAPLAYER_PLOGGER_H
class PLogger {

};
#define TAG "GCPlayer"
#ifdef ANDROID
#include <android/log.h>
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__)
#else
#define  LOGE(...) printf("GCPlayer",__VA_ARGS__)
#endif
#endif //MEDIAPLAYER_PLOGGER_H
