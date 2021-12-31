#include <jni.h>
#include <unistd.h>


void
Java_rtrk_pnrs_anr_ANRExample_anrSleep( JNIEnv* env, jobject thiz )
{
    //sleep(20);
    sleep(3);
}

unsigned
Java_rtrk_pnrs_anr_ANRExample_anrCrash( JNIEnv* env, jobject thiz )
{
	return 10;
    //unsigned* x = 0x12345678;
    //*x = 10;
    //return *x;
}
