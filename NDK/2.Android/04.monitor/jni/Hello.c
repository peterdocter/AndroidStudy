#include <stdio.h>
#include <stdlib.h>
#include "com_czt_ndk_monitor_DemoActivity.h"

int getPressure(){
    //由c工程师实现的了.
  return   rand()%300;
}

/**
 * 模拟获取硬件返回回来的数据
 */

JNIEXPORT jint JNICALL Java_com_czt_ndk_monitor_DemoActivity_getCurrentPressure
  (JNIEnv * env, jobject obj){

	return getPressure();
}
