/*
 * unit:     no
 * function: func_02060ABC
 * address:  0x02060ABC
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
 * The tail-end half of the expanded-heap allocator, the mirror of
 * func_02060A08: func_02060CA0 dispatches here when the caller asked for a
 * negative alignment, which is how src/matched/sub_02030098.c spells "take
 * this block from the high end of the heap".
 *
 * The walk runs from the free list's tail through the `prev` link at +0x08
 * (the head walk uses `next` at +0x0c), and the candidate address is the end
 * of the block minus the request rounded *down* to the alignment, so the
 * rejection test is a signed `subs`/`bmi` against the block's own data start
 * rather than the head walk's unsigned size comparison.  The same
 * smallest-block-wins rule and the same two early exits apply.
 *
 * The rounding mask is one register here, not two: rounding down needs only
 * `~(align - 1)` and the compiler rewrites `sub`/`mvn` in place on the
 * alignment argument.
 *
 * The last argument of func_02060888 is the direction flag, 0 from the head
 * walk and 1 here, which is what tells the carve which side of the block the
 * remainder stays on.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02060ABC.c \
 *       --func func_02060ABC --addr 0x02060ABC --cc 1.1p1 --arm
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

extern void *func_02060888(struct MBlockList *list, struct MBlock *block,
                           void *ptr, u32 size, int fromTail);

void *func_02060ABC(struct ExpHeap *heap, u32 size, s32 align)
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

    for (block = heap->freeList.tail; block != 0; block = block->prev) {
        u8   *base = (u8 *)block + 0x10;
        u8   *end = (u8 *)(block->size + (u32)base);
        u8   *ptr = (u8 *)(((u32)end - size) & ~(align - 1));

        if ((s32)(ptr - base) >= 0 && foundSize > block->size) {
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
    return func_02060888(&heap->freeList, found, foundPtr, size, 1);
}
