#include <stdio.h>
#include <jni.h>
#include "com_czt_lame_MainActivity.h"
#include "lame.h"
#include <malloc.h>
#include <string.h>

/**
 * 标志位，1为转换，0为停止转换。
 */
int flag = 1;
/**
 * 工具方法
 */
char* Jstring2CStr(JNIEnv* env, jstring jstr) {
	char* rtn = NULL;
	jclass clsstring = (*env)->FindClass(env, "java/lang/String");
	jstring strencode = (*env)->NewStringUTF(env, "GB2312");
	jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes",
			"(Ljava/lang/String;)[B");
	jbyteArray barr = (jbyteArray)(*env)->CallObjectMethod(env, jstr, mid,
			strencode); // String .getByte("GB2312");
	jsize alen = (*env)->GetArrayLength(env, barr);
	jbyte* ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
	if (alen > 0) {
		rtn = (char*) malloc(alen + 1); //"\0"
		memcpy(rtn, ba, alen);
		rtn[alen] = 0;
	}
	(*env)->ReleaseByteArrayElements(env, barr, ba, 0); //
	return rtn;
}
/**
 * 获取lame版本号
 */
JNIEXPORT jstring JNICALL Java_com_czt_lame_MainActivity_getVersion
  (JNIEnv * env, jobject obj){
	return (*env)->NewStringUTF(env, get_lame_version());
}
/**
 * 停止转换。
 */
JNIEXPORT void JNICALL Java_com_czt_lame_MainActivity_stopConvert
  (JNIEnv *env, jobject obj){
	flag = 0;
}
/**
 * 调用java代码
 */
void updateUI(JNIEnv * env, jobject obj,int process){
	//  jclass      (*FindClass)(JNIEnv*, const char*);
	jclass jclazz = (*env)->FindClass(env,"com/czt/lame/MainActivity");
// jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
	jmethodID methodid = (*env)->GetMethodID(env,jclazz,"setCurrentProcess","(I)V");

	// void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
	(*env)->CallVoidMethod(env,obj,methodid,process);
}
/**
 * 将wav转为MP3
 */
JNIEXPORT void JNICALL Java_com_czt_lame_MainActivity_convert
  (JNIEnv * env, jobject obj , jstring jWavPath, jstring jMp3Path){
	flag = 1;
	char* cWavPath = Jstring2CStr(env, jWavPath);
	char* cMp3Path = Jstring2CStr(env,jMp3Path);

	FILE* wav = fopen(cWavPath, "rb");
	FILE* mp3 = fopen(cMp3Path, "wb"); //打开两个文件

	short int wav_buffer[8192*2];//获取左右声道的数据,缓冲区
	unsigned char mp3_buffer[8192];//输出的mp3的缓冲区

	//1.读文件 2.转化 3.转化后存到mp3文件.
	//初始化 lame编码器
	lame_global_flags * lame = lame_init();
	//设置采样率
	lame_set_in_samplerate(lame, 44100);
	//设置声道数
	lame_set_num_channels(lame, 2);

	//设置编码方式.
	lame_set_VBR(lame, vbr_default);
	lame_init_params(lame);
	int read;//成功的读了多少个字节
	int write;//写了多少个字节

	int process = 0;

	do {
		if(flag == 0){
			return;
		}
		read = fread(wav_buffer, sizeof(short int)*2, 8192, wav);
		if(read == 0) {
			//使用do-while是为了在0的时候flush一下。 最后一块的操作是不一样的。
			write = lame_encode_flush(lame, mp3_buffer, 8192);
		}else{
			write = lame_encode_buffer_interleaved(lame, wav_buffer, read, mp3_buffer, 8192);
		}
		fwrite(mp3_buffer, sizeof(unsigned char), write, mp3);
		process += sizeof(short int)*2*read;
		//c调用java代码 通知界面更新
		updateUI(env,obj,process);
	}while(read != 0);
	lame_close(lame);
	fclose(wav);
	fclose(mp3);
}
