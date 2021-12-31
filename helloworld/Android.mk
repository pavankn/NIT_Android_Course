LOCAL_PATH:= $(call my-dir)

# libhello
include $(CLEAR_VARS)
LOCAL_SRC_FILES:= libhello.c
LOCAL_CFLAGS := -O2 -g
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE := libhello 
include $(BUILD_STATIC_LIBRARY)

#helloWorld
include $(CLEAR_VARS)
LOCAL_SRC_FILES:= helloworld.c
LOCAL_CFLAGS := -O2 -g
LOCAL_STATIC_LIBRARIES := libhello
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE := helloworld 
include $(BUILD_EXECUTABLE)
