#pragma once

#include <stddef.h>

/**
 * @brief Allocate memory (same as malloc()).
 *
 * @param size Bytes to allocate
 *
 * @return Pointer to allocated memory.
 */
void *memory_allocate(size_t size);

/**
 * @brief Free memory (same as free()).
 *
 * @param ptr Pointer to allocated memory
 */
void memory_free(void *ptr);

/**
 * @brief Print the memory usage.
 */
void print_memory_usage(void);

