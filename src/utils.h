#pragma once

#include "logger.h"
#include <stdlib.h>

/**
 * @brief Quit after printing a fatal message.
 *
 * @param msg The format message
 * @param ... Arguments to the format message
 */
#define QUIT_WITH_FATAL_MSG(msg, ...) do {\
    LOG_FATAL(msg, ##__VA_ARGS__);      \
    exit(EXIT_FAILURE);               \
    } while (0)

