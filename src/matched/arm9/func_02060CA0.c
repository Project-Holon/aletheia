/*
 * unit:     no
 * function: NNS_FndAllocFromExpHeapEx
 * address:  0x02060CA0
 * packet:   pkt_02060764
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_FndAllocFromExpHeapHead  0x02060A08  arm
 *   NNSi_FndAllocFromExpHeapTail  0x02060ABC  arm
 *
 * The expanded-heap allocator's front door, and the function
 * src/matched/sub_02030098.c calls once it has picked the arena: round the
 * request up to a word (a zero-byte request still costs one word, which is
 * what makes an empty allocation a distinct pointer), then walk the free list
 * from the head for a non-negative alignment or from the tail for a negative
 * one, the sign being how the caller spells "high end of the heap".
 *
 * The sign test is scheduled into the rounding: `cmp r2, #0` sits between the
 * `add` and the `bic` because both halves of the rounding are on the critical
 * path of neither branch.  The two calls are not tail calls even though
 * nothing follows them, since each is reached through its own `pop`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_FndAllocFromExpHeapEx.c \
 *       --func NNS_FndAllocFromExpHeapEx --addr 0x02060CA0 --cc 1.1p1 --arm
 */

typedef unsigned int u32;
typedef signed int   s32;

struct ExpHeap;

extern void *NNSi_FndAllocFromExpHeapHead(struct ExpHeap *heap, u32 size, s32 align);
extern void *NNSi_FndAllocFromExpHeapTail(struct ExpHeap *heap, u32 size, s32 align);

void *NNS_FndAllocFromExpHeapEx(struct ExpHeap *heap, u32 size, s32 align)
{
    if (size == 0) {
        size = 1;
    }
    size = (size + 3) & ~3;

    if (align >= 0) {
        return NNSi_FndAllocFromExpHeapHead(heap, size, align);
    }
    return NNSi_FndAllocFromExpHeapTail(heap, size, -align);
}
