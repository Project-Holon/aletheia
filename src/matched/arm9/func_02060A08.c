/*
 * unit:     no
 * function: func_02060A08
 * address:  0x02060A08
 * packet:   pkt_02060764
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02060888  0x02060888  arm
 *
 * The head-end half of the expanded-heap allocator that sits under the game's
 * own heap layer: src/matched/sub_02030098.c calls func_02060CA0, which
 * dispatches here for a non-negative alignment and to func_02060ABC for a
 * negative one.
 *
 * Walk the free list from the head keeping the smallest block that can still
 * hold the request once its data start is rounded up to the alignment, then
 * hand the winner to func_02060888, which carves the region out of the block
 * and moves it to the used list.  The search stops early on the first hit
 * when the heap's allocation mode is "first", and on an exact size fit in
 * either mode.
 *
 * The heap handle is 0x24 bytes of common header followed by the expanded
 * heap's own record: free-list head and tail at +0x24 and +0x28, used-list
 * head and tail at +0x2c and +0x30, group id at +0x34 and the feature
 * halfword at +0x36 whose bit 0 is the allocation mode.  A free block carries
 * a 0x10-byte header, which is why the data start is `block + 0x10`.
 *
 * The rounding mask is loop-invariant and the compiler hoists both halves of
 * it (`sub r2, r2, #1` / `mvn r5, r2`) above the loop on its own; writing it
 * as a local before the loop is the same code.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02060A08.c \
 *       --func func_02060A08 --addr 0x02060A08 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct MBlock {
    u16            signature;
    u16            attr;
    u32            size;
    struct MBlock *prev;
    struct MBlock *next;
};

struct MBlockList {
    struct MBlock *head;
    struct MBlock *tail;
};

struct ExpHeap {
    u8                pad_00[0x24];
    struct MBlockList freeList;
    struct MBlockList usedList;
    u16               groupId;
    u16               feature;
};

extern void *func_02060888(struct ExpHeap *heap, struct MBlock *block, void *ptr, u32 size, u16 fromTail);

void *func_02060A08(struct ExpHeap *heap, u32 size, s32 align)
{
    int            allocFirst;
    struct MBlock *found;
    struct MBlock *block;
    u32            foundSize;
    void          *foundPtr;

    allocFirst = (u16)(heap->feature & 1) == 0;
    found = 0;
    foundPtr = 0;
    foundSize = 0xFFFFFFFF;

    for (block = heap->freeList.head; block != 0; block = block->next) {
        u8   *base = (u8 *)block + 0x10;
        u8   *ptr = (u8 *)(((align - 1) + (u32)base) & ~(align - 1));
        u32   offset = (u32)(ptr - base);

        if (block->size >= size + offset && foundSize > block->size) {
            found = block;
            foundSize = block->size;
            foundPtr = ptr;
            if (allocFirst || foundSize == size) {
                break;
            }
        }
    }

    if (found == 0) {
        return 0;
    }
    return func_02060888((struct ExpHeap *)(&heap->freeList), found, foundPtr, size, 0);
}
