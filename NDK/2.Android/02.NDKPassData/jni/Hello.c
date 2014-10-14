#include <stdio.h>
#include <jni.h>
#include <android/log.h>
#include <malloc.h>
#include <string.h>
#include "com_czt_ndkpassdata_DataProvider.h"
#define LOG_TAG "clog"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
/**
 *Jstring2CStr 把java中的string 转化成 c中的char数组.
 *jstring   jstr 要被转化的java string
 *char*  代表的是字符串数组名称(字符串数组的首地址)
 */
char*   Jstring2CStr(JNIEnv*   env,   jstring   jstr)
{
	 char*   rtn   =   NULL;
	 jclass   clsstring   =   (*env)->FindClass(env,"java/lang/String");//寻找 java里面String.class
	 jstring   strencode   =   (*env)->NewStringUTF(env,"GB2312");//创建java字符串 "gb2312"
	 jmethodID   mid   =   (*env)->GetMethodID(env,clsstring,   "getBytes",   "(Ljava/lang/String;)[B");//寻找到java String getbytes();
	 jbyteArray   barr=   (jbyteArray)(*env)->CallObjectMethod(env,jstr,mid,strencode); // String .getByte("GB2312");
	 jsize   alen   =   (*env)->GetArrayLength(env,barr);
	 jbyte*   ba   =   (*env)->GetByteArrayElements(env,barr,JNI_FALSE);
	 if(alen   >   0)
	 {
	  rtn   =   (char*)malloc(alen+1);         //"\0"
	  memcpy(rtn,ba,alen);
	  rtn[alen]=0;
	 }
	 (*env)->ReleaseByteArrayElements(env,barr,ba,0);  //
	 return rtn;
}
JNIEXPORT jint JNICALL Java_com_czt_ndkpassdata_DataProvider_add
  (JNIEnv * env, jobject obj, jint x, jint y){
	LOGI("x=%d",x);
	LOGD("y=%d",y);
	int result = x+y;
	LOGD("result=%d",result);
	return result;
}
JNIEXPORT jstring JNICALL Java_com_czt_ndkpassdata_DataProvider_sayHelloInC
  (JNIEnv * env, jobject obj, jstring jstr){
//需求：需要把java中的string转化成那个c语言中的char*
	char* cstr = Jstring2CStr(env, jstr);
	LOGI("cstr=%s", cstr);
	char* chello = " ni hao";
	strcat(cstr, chello);
	LOGI("cstr=%s", cstr);
	return (*env)->NewStringUTF(env, cstr);
}
/**
 * 把java传递过来的int数组里面的每一个元素值都加10
 * 再返回给java代码
 */
JNIEXPORT jintArray JNICALL Java_com_czt_ndkpassdata_DataProvider_intMethod
  (JNIEnv * env, jobject obj, jintArray jintarr){
    /**
     * 在jni.h中可以找到下面的方法：
     * jint* (*GetIntArrayElements)(JNIEnv*, jintArray, jboolean*);
     * 获取一个int类型数组 第一个元素的首地址。
     * 最后一个参数官方解释不明，一般填0即可。
     *  jsize (*GetArrayLength)(JNIEnv*, jarray);
     *  获取一个数组的长度 返回值 是jsize类型
     *  可以看到 jsize就是jint jint就是int
     */
	int len = (*env)->GetArrayLength(env,jintarr);
	LOGI("len=%d",len);
	jint* intarr =  (*env)->GetIntArrayElements(env,jintarr,0);
	int i;
	for(i=0;i<len;i++){
		LOGI("intarr[%d]=%d",i,intarr[i]);//int 数组原来每一个元素的初始值
		*(intarr+i) += 10;
	}

	return jintarr;
}

