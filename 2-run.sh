#!/bin/bash
set -e -o pipefail
cd $(dirname "$0")
adb push libs/armeabi-v7a/program /data/local/tmp
adb shell /data/local/tmp/program
