#!/bin/bash
set -e -o pipefail
cd $(dirname "$0")
ndk-build V=1
