
#define LOG_TAG "CallStackExample"

#include <utils/CallStack.h>
#include <cutils/log.h>

extern "C" void dumpCallStack( char *label)
{
   android::CallStack cs;
   cs.update();
   cs.dump("CallStackExample");
   //cs.log("CallStackExample");
}

int main()
{
	ALOGD("Pavan Dump CallStack");
	dumpCallStack("callstacktrace");
}

