# ���� ���丮 �Է� 
LOCAL_PATH := $(call my-dir)

# ������ ����� ������ ��� �����. 
include $(CLEAR_VARS)

# libcris.so �̸����� 
LOCAL_MODULE    := cris
# so�� ���Ե� ���� �ڵ� ����  
LOCAL_SRC_FILES := iClebo.cpp
# c/c++���� android�� log�� ���� ���̺귯�� ����.
LOCAL_LDLIBS := -llog
# -I�� ���� , include ������ include path�� �����Ѵ�. 
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include
# libcris.so�� �����. 
include $(BUILD_SHARED_LIBRARY)
