#pragma once

#if defined(__gnu_linux__) || defined(__linux__)
#define OS_LINUX
#elif defined(_WIN32)
#define OS_WINDOWS
#endif
