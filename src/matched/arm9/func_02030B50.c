/*
 * function: func_02030B50
 * address:  0x02030B50
 * packet:   pkt_02030A7C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  PC24 MSL_C_LIB_SetTwlFlag at +0x28 and +0x48: the only 2 call sites of 0x0209128C image-wide are these two, both inside this extent
 * blocker:  ABS32 func_02030A7C at +0x50: 0x02030A7C's only pool word image-wide is at 0x02030BA0, inside this extent, and nothing branches to it
 * symbols:
 *   func_02030A7C   0x02030A7C  arm
 *   GFL_HEAP_GetHeapSize   0x020303D8  arm
 *   GFL_HEAP_GetTotalFreeSize   0x02030344  arm
 *   GFL_HEAP_GetAllocatableSize   0x0203038C  arm
 *   GFL_HEAP_GetAllocCountById   0x0203046C  arm
 *   GFL_HEAP_GetHeapHandle   0x02030428  arm
 *   MSL_C_LIB_SetTwlFlag   0x0209128C  arm
 *   NNSi_FndWalkHeapBlocks   0x02060F50  arm
 *
 * Tears the object down and then runs func_02030A7C over every block in the
 * allocator list: the five per-object teardown calls, the global
 * "shutting down" flag set through MSL_C_LIB_SetTwlFlag(1), then NNSi_FndWalkHeapBlocks with
 * the callback and the context the teardown returned, and the flag cleared
 * again with MSL_C_LIB_SetTwlFlag(0).  The callback is passed a zero context, which
 * is why the constant is materialised once in r4 and copied to r2 rather
 * than emitted twice.
 *
 * All 84 bytes of the extent match, relocation fields aside: 80 bytes of
 * code plus the function's own pool word, exactly the original's shape.  The
 * blocker is not the C -- it is that this function is the only evidence for
 * two of the addresses it names:
 *
 *  - 0x0209128C (the "shutting down" flag setter at the head of packet
 *    pkt_020911D8) is branched to from exactly two sites in the whole image,
 *    and both of them are this function's own two `bl`s.  The `label` class
 *    needs a branch from *outside* the compared range, so the range being
 *    this function makes the only witnesses in the image inadmissible.
 *  - 0x02030A7C (the callback, and this packet's other function) is named by
 *    a single pool word image-wide, at 0x02030BA0, and that word is inside
 *    this function's own extent; nothing anywhere `b`/`bl`s to it, so the
 *    `label` class has no site to offer either.  It is also why the two
 *    functions cannot attest each other: func_02030A7C is this file's
 *    sibling in pkt_02030A7C, but it is itself MATCH-capped on three data
 *    sites (see src/pending/func_02030A7C.c), so no `matched` entry exists
 *    to witness this call.
 *
 * `--suggest-split` returns 0 pieces and leaves the single function out:
 * both blockers are inside the range and no cut can free them.  Every
 * unresolved site here clears the moment the function it names is matched
 * by somebody else -- 0x0209128C is an entry point of pkt_020911D8, and
 * 0x02030A7C is blocked on bss evidence rather than on anything this file
 * could do differently.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02030B50.c \
 *       --func func_02030B50 --addr 0x02030B50 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

typedef unsigned short u16;
extern u32 GFL_HEAP_GetHeapSize(u32 heapId);
extern void *GFL_HEAP_GetTotalFreeSize(u32 heapId);
extern void *GFL_HEAP_GetAllocatableSize(u32 heapId);
extern u16 GFL_HEAP_GetAllocCountById(u32 heapId);
extern void *GFL_HEAP_GetHeapHandle(u32 heapId);
extern void MSL_C_LIB_SetTwlFlag(int x);
extern void NNSi_FndWalkHeapBlocks(int *p, void (*fn)(void *, void *, int), int ctx);
extern void func_02030A7C(void *heap);

void func_02030B50(void *p)
{
    GFL_HEAP_GetHeapSize((u32)p);
    GFL_HEAP_GetTotalFreeSize((u32)p);
    GFL_HEAP_GetAllocatableSize((u32)p);
    GFL_HEAP_GetAllocCountById((u32)p);
    MSL_C_LIB_SetTwlFlag(1);
    NNSi_FndWalkHeapBlocks(GFL_HEAP_GetHeapHandle((u32)p), (void (*)(void *, void *, int))func_02030A7C, 0);
    MSL_C_LIB_SetTwlFlag(0);
}
