#ifndef GAME_SDK_NNSFND_H
#define GAME_SDK_NNSFND_H

#include "types.h"

/* Foundation library of NitroSystem (nnsfnd): the allocator handle. */

typedef struct NNSFndAllocator {
    const void *funcs;
    void *heap;
    u32 heapParam1;
    u32 heapParam2;
} NNSFndAllocator;

#endif
