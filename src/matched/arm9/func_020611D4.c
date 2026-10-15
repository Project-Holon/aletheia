/*
 * function: NNS_FndFreeByStateToFrmHeap
 * address:  0x020611D4
 * packet:   pkt_020611D4
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * NitroSystem fnd frame heap, NNS_FndFreeByStateToFrmHeap: walk the saved
 * state list at heap+0x2c for the tag (or take the newest when the tag is 0)
 * and restore head/tail allocators and the state link from it.  Written in
 * the library's shape: the frame-heap head sits right after the 0x24-byte
 * NNSiFndHeapHead (GetFrmHeapHeadPtrFromHeapHead as an inline), and the
 * search is the library's `if (tagName) for (; pState; pState = prev) if
 * (match) break;`.  That shape under 1.1p1 is 84 bytes; under ../2.0/sp2 it is
 * 80 bytes, 0 mismatches (the predicated `ldrne/cmpne/bne` loop at
 * 0x020611E4..0x020611F4 is the 2.0 rotation).  Closes the "loop
 * if-conversion wall" of docs/notes/NNS_FndFreeByStateToFrmHeap.c.txt and
 * docs/notes/pkt_020611D4.c.txt.
 */

typedef unsigned int u32;
typedef int BOOL;

typedef struct NNSiFndFrmHeapState {
    u32 tagName;
    void *headAllocator;
    void *tailAllocator;
    struct NNSiFndFrmHeapState *pPrevState;
} NNSiFndFrmHeapState;

typedef struct NNSiFndFrmHeapHead {
    void *headAllocator;
    void *tailAllocator;
    NNSiFndFrmHeapState *pState;
} NNSiFndFrmHeapHead;

typedef struct NNSiFndHeapHead {
    u32 signature;
    void *link[2];      /* NNSFndLink: prev, next */
    u32 childList[3];   /* NNSFndList: head, tail, count/offset */
    void *heapStart;
    void *heapEnd;
    u32 attribute;
} NNSiFndHeapHead;

typedef NNSiFndHeapHead *NNSFndHeapHandle;

static inline NNSiFndFrmHeapHead *GetFrmHeapHeadPtrFromHeapHead(NNSiFndHeapHead *pHHead)
{
    return (NNSiFndFrmHeapHead *)((u32)pHHead + sizeof(NNSiFndHeapHead));
}

BOOL NNS_FndFreeByStateToFrmHeap(NNSFndHeapHandle heap, u32 tagName)
{
    NNSiFndFrmHeapHead *pFrmHeapHd = GetFrmHeapHeadPtrFromHeapHead(heap);
    NNSiFndFrmHeapState *pState = pFrmHeapHd->pState;

    if (tagName != 0) {
        for (; pState; pState = pState->pPrevState) {
            if (pState->tagName == tagName)
                break;
        }
    }

    if (pState == 0) {
        return 0;
    }

    pFrmHeapHd->headAllocator = pState->headAllocator;
    pFrmHeapHd->tailAllocator = pState->tailAllocator;
    pFrmHeapHd->pState = pState->pPrevState;

    return 1;
}
