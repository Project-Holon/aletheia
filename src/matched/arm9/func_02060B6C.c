/*
 * function: func_02060B6C
 * address:  0x02060B6C
 * packet:   pkt_02060764
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02060790  0x02060790  arm
 *   func_020607B8  0x020607B8  arm
 *   func_020607E8  0x020607E8  arm
 *
 * NitroSystem fnd expanded heap, RecycleRegion: return a region to the free
 * list, coalescing with the free block that starts at its end and the one
 * that ends at its start, and drop it if it is smaller than a block header
 * (0x10).  func_02060790 is RemoveMBlock, func_020607B8 InsertMBlock and
 * func_020607E8 InitMBlock (called with the 'FR' free-block signature 0x4652
 * through an inline InitFreeMBlock).
 *
 * docs/notes/pkt_02060B6C.c.txt stood at 52 bytes with a volatile region
 * pointer and a hand-built loop.  The library's own shape closes it: the
 * region is copied BY VALUE (`MemRegion freeRgn = *pRegion;`, which is the
 * image's two loads before `mov r6, r0`), the walk is a plain `for` with
 * `continue` (the predicated `movlo` is the one-statement arm), the pointer
 * is NOT volatile, and the block end address goes through small inline
 * helpers whose add is written `val + (u32)ptr` -- `(u32)ptr + val` swaps
 * the two registers of both end-address sums (4 bytes).  1.1p1; ../2.0/sp2
 * is also byte-exact on this source.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02060B6C.c \
 *       --func func_02060B6C --addr 0x02060B6C --arm --cc 1.1p1
 */
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            BOOL;
typedef struct MBlockHead MBlockHead;
struct MBlockHead {
    u16         signature;
    u16         attribute;
    u32         blockSize;
    MBlockHead *pMBHeadPrev;
    MBlockHead *pMBHeadNext;
};
typedef struct { MBlockHead *head; MBlockHead *tail; } MBlockList;
typedef struct { void *start; void *end; } MemRegion;
typedef struct { MBlockList mbFreeList; } ExpHeapHead;
extern void *func_02060790(int *p, int *node);
extern void *func_020607B8(int *p, void *node, int *a);
extern void *func_020607E8(int *p, int v);
static inline void *AddU32ToPtr(void *ptr, u32 val) { return (void *)(val + (u32)ptr); }
static inline void *GetMemPtrForMBlock(MBlockHead *p) { return AddU32ToPtr(p, sizeof(MBlockHead)); }
static inline void *GetMBlockEndAddr(MBlockHead *p) { return AddU32ToPtr(GetMemPtrForMBlock(p), p->blockSize); }
static inline u32 GetOffsetFromPtr(void *start, void *end) { return (u32)end - (u32)start; }
static inline MBlockHead *InitFreeMBlock(MemRegion *r) { return func_020607E8((int *)r, 0x4652); }
BOOL func_02060B6C(ExpHeapHead *pEHHead, const MemRegion *pRegion)
{
    MBlockHead *pBlkPrFree = 0;
    MemRegion freeRgn = *pRegion;

    {
        MBlockHead *pBlk;
        for (pBlk = pEHHead->mbFreeList.head; pBlk; pBlk = pBlk->pMBHeadNext)
        {
            if ((void *)pBlk < pRegion->start)
            {
                pBlkPrFree = pBlk;
                continue;
            }
            if ((void *)pBlk == pRegion->end)
            {
                freeRgn.end = GetMBlockEndAddr(pBlk);
                (void)func_02060790((int *)(&pEHHead->mbFreeList), (int *)pBlk);
            }
            break;
        }
    }

    if (pBlkPrFree && GetMBlockEndAddr(pBlkPrFree) == pRegion->start)
    {
        freeRgn.start = pBlkPrFree;
        pBlkPrFree = func_02060790((int *)(&pEHHead->mbFreeList), (int *)pBlkPrFree);
    }

    if (GetOffsetFromPtr(freeRgn.start, freeRgn.end) < sizeof(MBlockHead))
    {
        return 0;
    }

    (void)func_020607B8((int *)(&pEHHead->mbFreeList), InitFreeMBlock(&freeRgn), (int *)pBlkPrFree);
    return 1;
}
