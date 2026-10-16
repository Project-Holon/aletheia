/*
 * unit:     no
 * address:  0x020304CC
 * packet:   pkt_020304CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: GFL_HEAP_IsHeapValid
 *
 * Heap validity probe: the same two guards that open the raw allocator
 * GFL_HEAP_AllocMemory, with the allocation itself removed.
 *
 *   BOOL GFL_HEAP_IsHeapValid(u32 heapId)
 *
 * It masks the heap id with 0x7fff (bit 15 is the allocator's high/low
 * direction flag, meaningless here but still masked off), bounds-checks it
 * against g_EnvModule.count, then resolves the arena through GFL_HEAP_GetHeap.
 * Each failure stamps its own code into g_EnvModule.error, 1 for an id out
 * of range and 2 for an id that maps to no live heap, exactly the codes
 * GFL_HEAP_AllocMemory uses, and returns 0; success writes 0 and returns 1. The
 * callers treat the return as a pointer-ish truth value (see
 * src/pending/GFL_HEAP_GetHeapHeadChecked.c), but the code here materialises a plain 1.
 *
 * Shape notes:
 *
 *  - The two failure returns share one `mov r0, #0` / `pop` epilogue at
 *    0x02030514 reached by branch, with statements (the error store, then
 *    the call) sitting between the guards. Plain `return 0;` in each arm
 *    inlines a `movhs r0, #0` / `pophs` pair instead and shifts the tail;
 *    only the explicit `goto fail;` reproduces the shared exit
 *    (docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md).
 *  - The mask is a pool word, not an immediate: 0x7fff has no ARM
 *    rotated-immediate encoding, which is why `ldr r1, [pc, #0x44]` is
 *    scheduled up beside the g_EnvModule load.
 *  - The out-of-range arm reuses r0 for both the error code and the
 *    `strh`, so the code constant 1 is written before the mask result is
 *    dead; that falls out of writing the store as the first statement of
 *    the arm.
 *
 * symbols:
 *   g_EnvModule   0x02146954  data
 *   GFL_HEAP_GetHeap  0x0202FBAC  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_HEAP_IsHeapValid.c \
 *       --func GFL_HEAP_IsHeapValid --addr 0x020304CC --cc 1.1p1 --arm
 */

#include "../include/G_EnvModule.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct EnvEntry {
    void *ptr00;
    u32 field04;
    u32 field08;
    u16 field0c;
    u8  field0e;
};

extern struct EnvModule g_EnvModule;

extern void *GFL_HEAP_GetHeap(u32 idx);

u32 GFL_HEAP_IsHeapValid(u32 heapId)
{
    void *arena;

    heapId &= 0x7FFF;
    if (heapId >= g_EnvModule.count) {
        g_EnvModule.error = 1;
        goto fail;
    }
    arena = GFL_HEAP_GetHeap(heapId);
    if (arena == 0) {
        g_EnvModule.error = 2;
        goto fail;
    }
    g_EnvModule.error = 0;
    return 1;

fail:
    return 0;
}
