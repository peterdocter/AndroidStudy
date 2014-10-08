#include <stdio.h>
#include <jni.h>
#include "com_czt_usingcpp_MainActivity.h"
JNIEXPORT jstring JNICALL Java_com_czt_usingcpp_MainActivity_helloFromCpp
  (JNIEnv * env, jobject obj){
	return env->NewStringUTF("Hell From Cpp");
}
