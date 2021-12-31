LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES:= callstackexample.cpp
LOCAL_MODULE := callstackexample 
LOCAL_MODULE_TAGS := optional
LOCAL_LDFLAGS += -llog
LOCAL_LDFLAGS += -lutils

include $(BUILD_EXECUTABLE)
