#!/bin/bash
set -e -o pipefail
cd $(dirname "$0")
adb push libs/armeabi-v7a/libc++_shared.so libs/armeabi-v7a/program /data/local/tmp
adb shell 'cd /data/local/tmp && LD_LIBRARY_PATH=. ./program'
