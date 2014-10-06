#include <stdio.h>
#include <jni.h>
#include <android/log.h>
#include "com_czt_ndkcallback_DataProvider.h"
#define LOG_TAG "clog"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
/**
 * env JNIEnv* java虚拟机环境的指针.
 *
 *jobject obj ,哪个对象调用的这个native的方法 , obj就代表的是哪个对象
 */
JNIEXPORT void JNICALL Java_com_czt_ndkcallback_DataProvider_callMethod1
  (JNIEnv * env, jobject obj){
	//思考 java中的反射
	//1.找到某一个类的字节码
	//   jclass      (*FindClass)(JNIEnv*, const char*);
	jclass jclazz = (*env)->FindClass(env,"com/czt/ndkcallback/DataProvider");
	if(jclazz==0){
		LOGI("LOAD CLAZZ ERROR");
	}else{
		LOGI("LOAD CLAZZ success");
	}
	//2.找到类的字节码里面的方法.
	// jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);

	jmethodID  methodid = (*env)->GetMethodID(env,jclazz,"helloFromJava","()V");
	if(methodid==0){
		LOGI("LOAD methodid ERROR");
	}else{
		LOGI("LOAD methodid success");
	}

	//3.调用方法
	//void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
	(*env)->CallVoidMethod(env,obj,methodid);


}
/*
 * Class:     com_czt_ndkcallback_DataProvider
 * Method:    callMethod2
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_czt_ndkcallback_DataProvider_callMethod2
(JNIEnv * env, jobject obj){

}

/*
 * Class:     com_czt_ndkcallback_DataProvider
 * Method:    callMethod3
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_czt_ndkcallback_DataProvider_callMethod3
(JNIEnv * env, jobject obj){

}
