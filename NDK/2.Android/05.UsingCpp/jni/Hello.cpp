#include <stdio.h>
#include <jni.h>
#include "com_czt_usingcpp_MainActivity.h"
#include <android/log.h>
#include <malloc.h>
#include <string.h>
#define LOG_TAG "System.out"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
char* Jstring2CStr(JNIEnv* env, jstring jstr)
{
	 char* rtn = NULL;
	 jclass clsstring = env->FindClass("java/lang/String");
	 jstring strencode =  env->NewStringUTF("GB2312");
	 jmethodID mid = env->GetMethodID(clsstring,   "getBytes",   "(Ljava/lang/String;)[B");
	 jbyteArray barr= (jbyteArray)env->CallObjectMethod(jstr,mid,strencode); // String .getByte("GB2312");
	 jsize alen = env->GetArrayLength(barr);
	 jbyte* ba = env->GetByteArrayElements(barr,JNI_FALSE);
	 if(alen > 0)
	 {
	  rtn = (char*)malloc(alen+1);         //"\0"
	  memcpy(rtn,ba,alen);
	  rtn[alen]=0;
	 }
	 env->ReleaseByteArrayElements(barr,ba,0);  //
	 return rtn;
}
JNIEXPORT jstring JNICALL Java_com_czt_usingcpp_MainActivity_helloFromCpp
  (JNIEnv * env, jobject obj){
	//C´úÂë
	//return (*env)->NewStringUTF(env,"haha from c");
	//c++´úÂë
	return env->NewStringUTF("Hell From Cpp");
}
JNIEXPORT void JNICALL Java_com_czt_usingcpp_MainActivity_sayHelloInCpp
  (JNIEnv * env, jobject, jstring jstr){
	char* cstr = Jstring2CStr(env, jstr);
	LOGI("cstr=%s",cstr);
}
