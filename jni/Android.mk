# 현재 디렉토리 입력 
LOCAL_PATH := $(call my-dir)

# 이전에 선언된 변수를 모두 지운다. 
include $(CLEAR_VARS)

# libcris.so 이름으로 
LOCAL_MODULE    := cris
# so에 포함될 구현 코드 파일  
LOCAL_SRC_FILES := iClebo.cpp
# c/c++에서 android로 log를 보낼 라이브러리 포함.
LOCAL_LDLIBS := -llog
# -I의 역할 , include 폴더를 include path로 포함한다. 
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include
# libcris.so로 만든다. 
include $(BUILD_SHARED_LIBRARY)
