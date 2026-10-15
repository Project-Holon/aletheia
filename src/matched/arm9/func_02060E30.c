/*
 * function: NNS_FndFreeToExpHeap
 * address:  0x02060E30
 * packet:   pkt_02060CD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_FndGetMBlockRegion   0x02060764  arm
 *   NNSi_FndRemoveMBlock   0x02060790  arm
 *   NNSi_FndRecycleRegion   0x02060B6C  arm
 *
 * The expanded heap's free primitive: read the block's own extent with
 * NNSi_FndGetMBlockRegion, unlink its header from the heap's used list (+0x2c) and hand
 * the extent to NNSi_FndRecycleRegion, which splices it back into the free list at
 * +0x24 and merges it with any adjacent free block.
 *
 * The 2-word extent is two separate scalars, not an int[2] and not a struct,
 * and that is load-bearing: mwcc caches the address of one object in a
 * callee-saved register (r4) across the second call when the two call sites
 * name the same object, collapsing `add r0, sp, #0` / `add r1, sp, #0` into
 * one `add r4, sp, #0` plus a `mov`, four bytes longer.  Two distinct
 * variables are different objects to its alias analysis, so each site
 * rematerialises `sp + 0` and the original's 60 bytes come out.
 *
 * The second site spells the base as `&end - 1`, since `end` is the *later*
 * declaration and mwcc lays locals out with the later declaration at the
 * lower address: `end` sits at sp+0 and `start` at sp+4, so `&end - 1` and the
 * block's own base (`&start`, as NNSi_FndGetMBlockRegion must be handed) are the same
 * word.  The pair is not a struct or an array: with one object named at both
 * sites the compiler folds the two addresses into one value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_FndFreeToExpHeap.c \
 *       --func NNS_FndFreeToExpHeap --addr 0x02060E30 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

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

extern void NNSi_FndGetMBlockRegion(int *out, int *blk);
extern void *NNSi_FndRemoveMBlock(int *p, int *node);
extern int            NNSi_FndRecycleRegion(struct MBlockList *list, int *info);

void NNS_FndFreeToExpHeap(struct ExpHeap *heap, void *block)
{
    struct MBlock *hdr = (struct MBlock *)((u8 *)block - 0x10);
    int            end;
    int            start;

    NNSi_FndGetMBlockRegion(&start, (int *)hdr);
    NNSi_FndRemoveMBlock((int *)(&heap->usedList), (int *)hdr);
    NNSi_FndRecycleRegion(&heap->freeList, &end - 1);
}
