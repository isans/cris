LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := cris
LOCAL_SRC_FILES := iClebo.cpp
LOCAL_LDLIBS := -llog
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include
LOCAL_STATIC_LIBRARIES := boost_program_options
include $(BUILD_SHARED_LIBRARY)

$(call import-module,boost)