/* DO NOT EDIT THIS FILE - it is machine generated */
/* Header for class rtrk_pnrs_jniexample_FibonacciNative */

#define LOG_TAG "PavanknJNI"
#include "com_project_jnigallery_NativeGallery.h"
#include <unistd.h>

#define ALOGD(...) __android_log_print

JNIEXPORT jint JNICALL 
Java_com_project_jnigallery_NativeGallery_get(JNIEnv* env , jobject thisObj , jint num)
{
	jint val = 1025;
	__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "The value is %d", val);
		

	return val;
}

size_t read_bin(int fd, uint8_t* array, size_t arrayBytes) {
	return read(fd, array, arrayBytes);
}

JNIEXPORT jint JNICALL 
Java_com_project_jnigallery_NativeGallery_GetJPEGData(JNIEnv* env , jobject thisObj, jint flag)
{
	__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "Landed in JPEGDATA URL: %d ",  flag);
	int fd = ASharedMemory_create("jpegashmem", MAX_JPEG_BUF_SIZE);
	char *url;
	char *imgbuf = (char *) mmap(NULL, MAX_JPEG_BUF_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if(imgbuf == MAP_FAILED){
		__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "nativegallery mmap failed");
		return -1;
	}

	if(flag == 1){
		url = "/system/rohit.jpg";
	}else if(flag == 2){
		url = "/system/Anna.jpg";
	}else if(flag == 3){
		url = "/system/Messi.jpg";
	}

	int nativeFD = open(url, O_RDONLY);
	memset(imgbuf, 0x0, sizeof(MAX_JPEG_BUF_SIZE));

	if(nativeFD >= 0){
		ALOGD("Pavankn FpImage is NOT NULL");
		__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "nativeFD is NOT NULL");
		int bytesRead = read_bin(nativeFD, imgbuf, MAX_JPEG_BUF_SIZE);
		__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "bytesRead: %d", bytesRead);
	}else{
		__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "Pavankn FpImage is NULL!!!!!");
		perror("Error: ");
		return -1;
	}
	
	__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "Pavankn FileDesc is ", fd);

	ASharedMemory_setProt(fd, PROT_READ);

	return fd;
}

