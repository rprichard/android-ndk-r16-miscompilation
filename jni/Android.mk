LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := program
LOCAL_SRC_FILES := test.cpp test_fn.cpp
include $(BUILD_EXECUTABLE)
