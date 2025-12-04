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

static double format_ext_and_get_size(size_t bytes, char *ext) {
    double size = bytes;
    ext[0] = 'X';
    ext[1] = 'i';
    ext[2] = 'B';
    ext[3] = 0;

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

    return size;
}

void print_memory_usage(void) {
    LOG_INFO("Allocation count: %lu", allocation_count);

    char ext[4];
    double size;

    size = format_ext_and_get_size(allocated_bytes, ext);
    LOG_INFO("Allocation size: %.4lf %s", size, ext);

    size = format_ext_and_get_size(HEADER_SIZE * allocation_count, ext);
    LOG_INFO("Memory used for the header: %.4lf %s", size, ext);

    size = format_ext_and_get_size(allocated_bytes + (HEADER_SIZE * allocation_count), ext);
    LOG_INFO("Total memory used: %.4lf %s", size, ext);
}

