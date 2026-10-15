/*
 * file:     nns_gfd_vram_transfer.c
 * unit:     yes
 * function: NNS_GfdDoVramTransfer, NNS_GfdRegisterNewVramTransferTask, NNSi_GfdMergeAdjacentFreeBlocks, func_02061DF0, NNSi_GfdInitBlockPool, NNSi_GfdAddBlock, NNSi_GfdAllocBlockUnaligned
 * address:  0x02061C44
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Own object: EXACT with 1.1p1 and dsi/1.2, DIFF with ../2.0/sp2 (the build of
 * nns_gfd_vram_load_3.c before it and nns_gfd_lnk_vram_man.c after it) and with ../1.2/sp2.
 *
 * symbols:
 *   sVramTransferTaskQueue  0x02146B80  data
 *   NNSi_GfdGetHeadVramTransferTask  0x02061BB0  arm
 *   NNSi_GfdPopVramTransferTask  0x02061BD0  arm
 *   NNSi_GfdRunVramTransferTask  0x02061B2C  arm
 *   NNSi_GfdRingIsFull  0x02061860  arm
 *   NNSi_GfdGetTailVramTransferTask  0x02061BC0  arm
 *   NNSi_GfdPushVramTransferTask  0x02061B74  arm
 *   NNSi_GfdAllocLnkVram 0x02061EB8 arm
 */
struct Obj02061BD0;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef signed int    s32;

struct GfdTransferTask {
    void *pTaskFunc;    /* 0x00 */
    u32 srcAddr;        /* 0x04, source address (third argument) */
    u32 dstOffset;      /* 0x08, destination offset in VRAM (second argument) */
    s32 szByte;         /* 0x0c, byte size consumed */
};

struct GfdTransferTaskQueue {
    u8 ring[0x10];
    s32 totalSzByte;  /* 0x10, running byte total */
};

struct GfdLnkBlock {
    u32 start;                  /* 0x0 */
    u32 size;                   /* 0x4 */
    struct GfdLnkBlock *prev;   /* 0x8 */
    struct GfdLnkBlock *next;   /* 0xc */
};

struct GfdLnkRange {
    u32 start;
    u32 end;
};

typedef unsigned short u16;

struct GfdLnkBlockPool {
    struct GfdLnkBlock *freeList;
};

struct GfdLnkBlockList {
    struct GfdLnkBlock *head;
};

extern u32 NNSi_GfdGetHeadVramTransferTask(u8 *p);
extern u32 NNSi_GfdPopVramTransferTask(struct Obj02061BD0 *p);
extern void NNSi_GfdRunVramTransferTask(u32 *s);
extern int NNSi_GfdRingIsFull(u8 *p);
extern u32 NNSi_GfdGetTailVramTransferTask(u8 *p);
extern int NNSi_GfdPushVramTransferTask(char *p);
extern int NNSi_GfdAllocLnkVram(struct GfdLnkBlock **ppList, struct GfdLnkBlock **ppPool, u32 *pAddr, u32 size, u32 alignment);
void NNS_GfdDoVramTransfer(void);
s32 NNS_GfdRegisterNewVramTransferTask(void *pTaskFunc, u32 dstOffset, u32 srcAddr, s32 szByte);
u32 NNSi_GfdMergeAdjacentFreeBlocks(struct GfdLnkBlock **ppList, struct GfdLnkBlock **ppPool, struct GfdLnkRange *range);
void NNSi_GfdClearBlockListHead(struct GfdLnkBlock **ppHead);
struct GfdLnkBlock *NNSi_GfdInitBlockPool(struct GfdLnkBlock *blocks, u32 count);
u32 NNSi_GfdAddBlock(struct GfdLnkBlockList *list, struct GfdLnkBlockPool *pool, u32 start, u32 size);
int NNSi_GfdAllocBlockUnaligned(struct GfdLnkBlock **ppList, struct GfdLnkBlock **ppPool, u32 *pAddr, u32 size);
extern struct GfdTransferTaskQueue sVramTransferTaskQueue;


/*
 * Drain loop over the 0x02146B80 work record: fetch the head node, pump the
 * record's one-step state machine, and for as long as it reports progress
 * dispose of the node and subtract its size field from the record's running
 * byte total at +0x10, then fetch the next head.
 *
 * Blocked at MATCH on the `matched` class: NNSi_GfdRunVramTransferTask (PC24 at +0x0028)
 * and NNSi_GfdPopVramTransferTask (PC24 at +0x0018 and +0x004c) each have their only
 * branch inside 0x02061C44..0x02061CA0, so both sites stay wildcarded.  Both
 * callees are documented dead ends in docs/notes/pkt_02061B2C.c.txt and
 * docs/notes/pkt_02061BD0.c.txt (16 and 6 concrete bytes of instruction
 * selection residue respectively), so neither can ever be filed EXACT and
 * neither can attest this file.  Every concrete byte here reproduces.
 */
void NNS_GfdDoVramTransfer(void)
{
    struct GfdTransferTask *task = (struct GfdTransferTask *)NNSi_GfdGetHeadVramTransferTask((u8 *)(&sVramTransferTaskQueue));

    while (NNSi_GfdPopVramTransferTask((struct Obj02061BD0 *)(&sVramTransferTaskQueue)) != 0) {
        NNSi_GfdRunVramTransferTask((u32 *)task);
        sVramTransferTaskQueue.totalSzByte -= task->szByte;
        task = (struct GfdTransferTask *)NNSi_GfdGetHeadVramTransferTask((u8 *)(&sVramTransferTaskQueue));
    }
}




/*
 * Pushes one four-word request onto the queue object at 0x02146B80 and adds
 * its size field to the queue's running byte total at +0x10. NNSi_GfdRingIsFull
 * is the "queue full" test: a non-zero answer makes this return 0 without
 * touching anything, which is why the failure path is a `movne r0, #0` fused
 * into the conditional epilogue rather than a branch.
 *
 * The middle two stores land as one `stmib r4, {r7, r8}` and that ordering is
 * the whole tell for the argument mapping: `stm` writes the lowest-numbered
 * register to the lowest address, so +4 takes r7 (the third argument) and +8
 * takes r8 (the second). Writing the two fields in numeric field order
 * instead swaps the two arguments and still produces an `stmib`, so the
 * verdict stays SIZE-clean and the diff is only two bytes.
 *
 * This was capped at MATCH until 0x02061B74, the queue push, was matched in
 * src/matched/NNSi_GfdPushVramTransferTask.c; that entry is the witness the `bl` needed.
 * NNSi_GfdGetTailVramTransferTask is likewise a matched entry now.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_GfdRegisterNewVramTransferTask.c \
 *       --func NNS_GfdRegisterNewVramTransferTask --addr 0x02061CA4 --cc 1.1p1 --arm
 */
s32 NNS_GfdRegisterNewVramTransferTask(void *pTaskFunc, u32 dstOffset, u32 srcAddr, s32 szByte)
{
    struct GfdTransferTask *req;

    if (NNSi_GfdRingIsFull((u8 *)(&sVramTransferTaskQueue)) != 0) {
        return 0;
    }

    req = (struct GfdTransferTask *)NNSi_GfdGetTailVramTransferTask((u8 *)(&sVramTransferTaskQueue));
    req->pTaskFunc = pTaskFunc;
    req->srcAddr = srcAddr;
    req->dstOffset = dstOffset;
    req->szByte = szByte;
    NNSi_GfdPushVramTransferTask((char *)(&sVramTransferTaskQueue));
    sVramTransferTaskQueue.totalSzByte += req->szByte;
    return 1;
}





u32 NNSi_GfdMergeAdjacentFreeBlocks(struct GfdLnkBlock **ppList, struct GfdLnkBlock **ppPool, struct GfdLnkRange *range) {
    struct GfdLnkBlock *block = *ppList;
    struct GfdLnkBlock *nextBlock;
    u32 merged = 0;
    u32 zeroA = merged;
    u32 zeroB = merged;

    if (block != 0) {
        while (block != 0) {
            nextBlock = block->next;

            if (block->start == range->end) {
                struct GfdLnkBlock *next;
                struct GfdLnkBlock *prev;
                struct GfdLnkBlock *poolHead;

                range->end = block->start + block->size;
                merged |= 1;

                prev = block->prev;
                next = block->next;
                if (prev != 0) {
                    prev->next = next;
                } else {
                    *ppList = next;
                }
                if (next != 0) {
                    next->prev = prev;
                }

                poolHead = *ppPool;
                if (poolHead != 0) {
                    poolHead->prev = block;
                }
                block->next = *ppPool;
                block->prev = (struct GfdLnkBlock *)zeroA;
                *ppPool = block;
            }

            if (range->start == block->start + block->size) {
                struct GfdLnkBlock *next;
                struct GfdLnkBlock *prev;
                struct GfdLnkBlock *poolHead;

                range->start = block->start;
                merged |= 1;

                prev = block->prev;
                next = block->next;
                if (prev != 0) {
                    prev->next = next;
                } else {
                    *ppList = next;
                }
                if (next != 0) {
                    next->prev = prev;
                }

                poolHead = *ppPool;
                if (poolHead != 0) {
                    poolHead->prev = block;
                }
                block->next = *ppPool;
                block->prev = (struct GfdLnkBlock *)zeroB;
                *ppPool = block;
            }

            block = nextBlock;
        }
    }

    return merged;
}





void NNSi_GfdClearBlockListHead(struct GfdLnkBlock **ppHead)
{
    *ppHead = 0;
}





/*
 * note:     closed 2026-09-21 by tools/permuter.py (hill, --types, ret-var): the function
 *           returns the array pointer it was given; the void version freed r0 too early (2 bytes)
 */
struct GfdLnkBlock *NNSi_GfdInitBlockPool(struct GfdLnkBlock *blocks, u32 count)
{
    u32 last = count - 1;
    u32 i = 0;
    u32 *end;

    if (last != 0) {
        struct GfdLnkBlock *prevBlock = blocks;
        do {
            struct GfdLnkBlock *nextBlock = &blocks[i + 1];
            blocks[i].next = nextBlock;
            (&blocks[i])[1].prev = prevBlock;
            i++;
            prevBlock++;
        } while (i < last);
    }

    blocks[0].prev = 0;
    end = (u32 *)&blocks[count];
    end[-1] = 0;
    return blocks;
}





u32 NNSi_GfdAddBlock(struct GfdLnkBlockList *list, struct GfdLnkBlockPool *pool, u32 start, u32 size)
{
    struct GfdLnkBlock *block = pool->freeList;

    if (block != 0) {
        pool->freeList = block->next;
    }

    if (block == 0) {
        goto err;
    }

    block->start = start;
    block->size = size;
    block->prev = 0;
    block->next = 0;

    if (list->head != 0) {
        list->head->prev = block;
    }

    block->next = list->head;
    block->prev = 0;
    list->head = block;

    return 1;

err:
    return 0;
}


int NNSi_GfdAllocBlockUnaligned(struct GfdLnkBlock **ppList, struct GfdLnkBlock **ppPool, u32 *pAddr, u32 size)
{
    return NNSi_GfdAllocLnkVram(ppList, ppPool, pAddr, size, 0);
}
