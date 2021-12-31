LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_PACKAGE_NAME := JNIGallery
LOCAL_MODULE_TAGS := optional
LOCAL_DEX_PREOPT := false
LOCAL_PRIVATE_PLATFORM_APIS := true
LOCAL_MIN_SDK_VERSION := 23  # M
LOCAL_CERTIFICATE := platform
LOCAL_SRC_FILES := $(call all-java-files-under, src)

include $(BUILD_PACKAGE)

include $(call all-makefiles-under,$(LOCAL_PATH))
