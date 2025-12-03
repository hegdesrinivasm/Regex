#pragma once

/**
 * @enum LogLevel
 * @brief Different levels of logging.
 */
typedef enum LogLevel {
    LOG_LEVEL_FATAL,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_WARN,
    LOG_LEVEL_INFO,
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_TRACE
} LogLevel;

/**
 * @brief Log a message of given log level.
 *
 * @param level LogLevel of message
 * @param msg The format string
 * @param ... Arguments for format string
 */
void logger_log(LogLevel level, const char *restrict msg, ...);

/**
 * @brief Log a Fatal message
 *
 * @param msg The format message
 * @param .. Arguments for the format message
 */
#define LOG_FATAL(msg, ...) logger_log(LOG_LEVEL_FATAL, msg, ##__VA_ARGS__)

/**
 * @brief Log a Error message
 *
 * @param msg The format message
 * @param .. Arguments for the format message
 */
#define LOG_ERROR(msg, ...) logger_log(LOG_LEVEL_ERROR, msg, ##__VA_ARGS__)

#ifndef LOG_DISABLE_WARN
/**
 * @brief Log a Warning message
 *
 * @param msg The format message
 * @param .. Arguments for the format message
 */
#define LOG_WARN(msg, ...) logger_log(LOG_LEVEL_WARN, msg, ##__VA_ARGS__)
#else
#define LOG_WARN(msg, ...)
#endif

#ifndef LOG_DISABLE_INFO
/**
 * @brief Log a Info message
 *
 * @param msg The format message
 * @param .. Arguments for the format message
 */
#define LOG_INFO(msg, ...) logger_log(LOG_LEVEL_INFO, msg, ##__VA_ARGS__)
#else
#define LOG_INFO(msg, ...)
#endif

#ifndef LOG_DISABLE_DEBUG
/**
 * @brief Log a Debug message
 *
 * @param msg The format message
 * @param .. Arguments for the format message
 */
#define LOG_DEBUG(msg, ...) logger_log(LOG_LEVEL_DEBUG, msg, ##__VA_ARGS__)
#else
#define LOG_DEBUG(msg, ...)
#endif

#ifndef LOG_DISABLE_TRACE
/**
 * @brief Log a Trace message
 *
 * @param msg The format message
 * @param .. Arguments for the format message
 */
#define LOG_TRACE(msg, ...) logger_log(LOG_LEVEL_TRACE, msg, ##__VA_ARGS__)
#else
#define LOG_TRACE(msg, ...)
#endif

