This project illustrates a compiler bug in Android clang version 5.0.300080,
part of android-ndk-r16.  When using optimisation level Oz, the compiler
may generate ARM unwinding/exception handling tables that differ in
intent to the ordinary execution of the optimised code.

An analysis is provided in <analysis.pdf>, detailing the difference
between optimisation levels Os and Oz.
