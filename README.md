# robutils - utilities for networking, crypto, data structures, etc.

These are a bunch of source files pulled from my other projects. They code has few or
zero dependencies -- even on each other. You should be able to pull a single `.c` file
(and it's corresponding `.h` header) from this project and use it somewhere else without
having to pull in this entire project. Sometimes one or two other files may be needed,
but most are standalone.

This project is focused on unit tests for these files. Most files contains a "selftest"
function the bottom that does a simple/quick selftest of the module. Some contain
a more complex/time-consuming `test-xxxx.c` file to do a more thorough test.

These self-tests are run with Microsoft's compiler on Windows, gcc, and clang. They
are tested on Windows, Linux, and macOS. On Linux, they are tested with both glibc and musl.

