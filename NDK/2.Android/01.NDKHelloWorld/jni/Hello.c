#include <stdio.h>
#include <jni.h>
//2.实现Java里面定义的c方法。
//函数的声明包括两个部分：1.函数名称2.函数的返回值和接受的参数
jstring Java_com_czt_ndk_helloworld_MainActivity_helloFromC(JNIEnv* env,jobject obj){
	//返回一个Java的string
//	   jstring     (*NewStringUTF)(JNIEnv*, const char*);

	//return (*(*env)).NewStringUTF(env, "hello from c!");
	return (*env)->NewStringUTF(env, "hello from c!");
}
jstring Java_com_czt_ndk_helloworld_MainActivity_hello_1from_1c(JNIEnv* env,jobject obj){
	//返回一个Java的string
//	   jstring     (*NewStringUTF)(JNIEnv*, const char*);

	//return (*(*env)).NewStringUTF(env, "hello from c!");
	return (*env)->NewStringUTF(env, "hello_from_c!");
}
//3.c代码写好后，需要把c代码编译成一个可执行的二进制文件。--->.so
//4.编写android.mk文件把c代码编译成一个so文件。
