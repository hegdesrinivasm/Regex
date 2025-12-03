#pragma once

#include "logger.h"
#include <stdlib.h>

#define QUIT_WITH_FATAL_MSG(msg, ...) do {\
    LOG_FATAL(msg, ##__VA_ARGS__);      \
    exit(EXIT_FAILURE);               \
    } while (0)

