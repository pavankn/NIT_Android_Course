LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES:= libhello.c
LOCAL_MODULE := libhelloworld
LOCAL_MODULE_TAGS := optional
LOCAL_PRELINK_MODULE := false
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES:= helloworld.c
LOCAL_MODULE := helloworld
LOCAL_SHARED_LIBRARIES:= libhelloworld 
LOCAL_MODULE_TAGS := optional

include $(BUILD_EXECUTABLE)
