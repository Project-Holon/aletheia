/*
 * function: NNS_FndResizeForMBlockExpHeap
 * address:  0x02060CD0
 * packet:   pkt_02060C5C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * isa:      arm
 * status:   EXACT
 *
 * NNS_FndResizeForMBlockExpHeap shape: resize a used block of the expanded
 * heap in place.  Grow: find the free block that starts at this block's end,
 * take its region, unlink it, give the caller what it asked for (absorbing a
 * remainder under 0x10), re-insert the rest as a new 'FR' (0x4652) block, and
 * clear the grown part when heap attribute bit 0 asks for it.  Shrink: hand
 * the tail back through RecycleRegion and restore the old size on failure.
 * Returns the block's resulting size.
 *
 * Closed wave 12 from the 26-bytes-out source in
 * docs/notes/sub_02060CD0.c.txt.  The residue was the COMPILER, not the loop:
 * under ../2.0/sp2 the plain NitroSystem search
 *     for (p = head; p; p = p->next) { if (p == end) break; }
 * compiles to the image's `cmp / ldrne / cmpne / bne` loop, and the shrink
 * arm's volatile re-read is no longer needed (plain field read, EXACT).
 * dsi/1.1p1 with that loop is 356 bytes; this cluster's first sp2 pin.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNS_FndResizeForMBlockExpHeap.c \
 *       --func NNS_FndResizeForMBlockExpHeap --addr 0x02060CD0 --arm --cc ../2.0/sp2
 *   EXACT, 352 bytes, 6 of 6 relocation sites resolved (sp2p2 EXACT too).
 *
 * symbols:
 *   sub_02060764   0x02060764  arm
 *   sub_02060790   0x02060790  arm
 *   sub_020607B8   0x020607B8  arm
 *   sub_020607E8   0x020607E8  arm
 *   sub_02060B6C   0x02060B6C  arm
 *   MIi_CpuClear32 0x02082A7C  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

struct MBlockHead {
    u16 signature;
    u16 attribute;
    u32 blockSize;
    struct MBlockHead *prev;
    struct MBlockHead *next;
};

struct MBlockList {
    struct MBlockHead *head;
    struct MBlockHead *tail;
};

struct ExpHeapHead {
    struct MBlockList freeList;
    struct MBlockList usedList;
    u16 groupId;
    u16 feature;
};

struct HeapHead {
    u32 pad[8];
    u32 attribute;
    struct ExpHeapHead exp;
};

struct Region {
    u32 start;
    u32 end;
};

extern void sub_02060764(int *out, int *blk);
extern void *sub_02060790(int *p, int *node);
extern void *sub_020607E8(int *p, int v);
extern void *sub_020607B8(int *p, void *node, int *a);
extern s32 sub_02060B6C(struct ExpHeapHead *heap, struct Region *rgn);
extern void MIi_CpuClear32(u32 data, void *dest, u32 size);

u32 NNS_FndResizeForMBlockExpHeap(struct HeapHead *heap, void *memBlock, u32 size)
{
    struct ExpHeapHead *pEHHead;
    struct MBlockHead *pMBlkFr;
    u32 crBlockSize;
    struct MBlockHead *pMBHead;
    struct Region rgnFree;
    struct Region rgn;

    pEHHead = &heap->exp;
    pMBHead = (struct MBlockHead *)memBlock - 1;
    size = (size + 3) & ~3;
    crBlockSize = pMBHead->blockSize;

    if (size == crBlockSize) {
        return size;
    }

    if (size > crBlockSize) {
        struct MBlockHead *crUsedEnd = (struct MBlockHead *)(crBlockSize + (u32)(pMBHead + 1));
        u32 oldStart;
        struct MBlockHead *pMBlkFrPrev;
        u32 fillSize;
        u8 attr;

        for (pMBlkFr = pEHHead->freeList.head; pMBlkFr; pMBlkFr = pMBlkFr->next) {
            if (pMBlkFr == crUsedEnd)
                break;
        }
        if (pMBlkFr == 0 || size > crBlockSize + 0x10 + pMBlkFr->blockSize) {
            return 0;
        }

        sub_02060764((int *)(&rgnFree), (int *)pMBlkFr);
        pMBlkFrPrev = sub_02060790((int *)(&pEHHead->freeList), (int *)pMBlkFr);

        oldStart = rgnFree.start;
        rgnFree.start = size + (u32)memBlock;
        if (rgnFree.end - rgnFree.start < 0x10) {
            rgnFree.start = rgnFree.end;
        }
        pMBHead->blockSize = rgnFree.start - (u32)memBlock;
        if (rgnFree.end - rgnFree.start >= 0x10) {
            sub_020607B8((int *)(&pEHHead->freeList), sub_020607E8((int *)(&rgnFree), 0x4652), (int *)pMBlkFrPrev);
        }
        attr = (u8)heap->attribute;
        fillSize = rgnFree.start - oldStart;
        if ((attr & 1) != 0) {
            MIi_CpuClear32(0, (void *)oldStart, fillSize);
        }
    } else {
        rgn.start = size + (u32)memBlock;
        rgn.end = pMBHead->blockSize + (u32)(pMBHead + 1);
        pMBHead->blockSize = size;
        if (sub_02060B6C(pEHHead, &rgn) == 0) {
            pMBHead->blockSize = crBlockSize;
        }
    }

    return pMBHead->blockSize;
}
