LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES:= hellolog.c
LOCAL_MODULE := hellolog
LOCAL_MODULE_TAGS := optional
LOCAL_LDFLAGS += -llog

include $(BUILD_EXECUTABLE)
