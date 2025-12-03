#include "memory.h"

#include "logger.h"
#include <stdlib.h>

/**
 * @brief Amount of bytes required to store the size.
 */
#define HEADER_SIZE (sizeof(size_t))

#define KIB (1024)
#define MIB (KIB * 1024)
#define GIB (MIB * 1024)

static size_t allocated_bytes = 0;
static size_t allocation_count = 0;

void *memory_allocate(size_t size) {
    void *ptr = malloc(size + HEADER_SIZE);

    if (ptr) {
        allocation_count++;
        allocated_bytes += size;
        *((size_t *)ptr) = size;
        ptr = ((char *)ptr) + HEADER_SIZE;
    }

    return ptr;
}

void memory_free(void *ptr) {
    ptr = ((char *)ptr) - HEADER_SIZE;
    allocation_count--;
    allocated_bytes -= *((size_t *)ptr);
    free(ptr);
}

void print_memory_usage(void) {
    LOG_INFO("Allocation count: %lu", allocation_count);

    double size = allocated_bytes;
    char ext[] = {'X', 'i', 'B', 0};
    if (size > GIB) {
        size /= (double)GIB;
        ext[0] = 'G';
    } else if (size > MIB) {
        size /= (double)MIB;
        ext[0] = 'M';
    } else if (size > KIB) {
        size /= (double)KIB;
        ext[0] = 'K';
    } else {
        ext[0] = 'B';
        ext[1] = 0;
    }

    LOG_INFO("Allocation size: %.4lf%s", size, (char *)ext);
}

