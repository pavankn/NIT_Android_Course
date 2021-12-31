LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := com_project_jnigallery_NativeGallery.c
LOCAL_MODULE := libnativegallery
LOCAL_SHARED_LIBRARIES += liblog
LOCAL_LDFLAGS := -llog -landroid
LOCAL_MODULE_TAGS := optional
LOCAL_PRELINK_MODULE := false
LOCAL_CFLAGS := -Wno-unused-parameter
include $(BUILD_SHARED_LIBRARY)