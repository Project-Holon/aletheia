/*
 * file:     nns_fnd_frameheap.c
 * unit:     yes
 * function: NNSi_FndInitFrmHeap, NNSi_FndAllocFromFrmHeapHead, NNSi_FndAllocFromFrmHeapTail, NNSi_FndResetFrmHeapHead, NNSi_FndResetFrmHeapState, NNS_FndCreateFrmHeap, NNS_FndDestroyFrmHeap, NNS_FndAllocFromFrmHeapEx, NNS_FndFreeToFrmHeap, NNS_FndRecordStateForFrmHeap, NNS_FndFreeByStateToFrmHeap
 * address:  0x02060FA4
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *
 * symbols:
 *   NNSi_FndInitHeapHead  0x020606D0  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 */
#include "nns_fnd_types.h"

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
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

static inline NNSiFndFrmHeapHead *GetFrmHeapHeadPtrFromHeapHead(NNSiFndHeapHead *pHHead)
{
    return (NNSiFndFrmHeapHead *)((u32)pHHead + sizeof(NNSiFndHeapHead));
}

extern void NNSi_FndInitHeapHead(NNSiFndHeapHead *pHeapHd, u32 signature, void *pHint, u32 heapStart, u32 heapEnd);
extern void MIi_CpuClear32(u32 data, void *dest, u32 size);
extern void MIi_CpuClear32(int a, int b, int c);
extern void FNDHEAP_Finalize(void *heap);
NNSiFndHeapHead *NNSi_FndInitFrmHeap(NNSiFndHeapHead *pHeapHd, u32 heapStart, u32 heapEnd);
u32 NNSi_FndAllocFromFrmHeapHead(NNSiFndFrmHeapHead *pFrmHeapHd, u32 size, u32 align);
u32 NNSi_FndAllocFromFrmHeapTail(NNSiFndFrmHeapHead *pFrmHeapHd, u32 size, u32 align);
void NNSi_FndResetFrmHeapHead(NNSiFndHeapHead *pHeapHd);
void NNSi_FndResetFrmHeapState(NNSiFndHeapHead *pHeapHd);
void *NNS_FndCreateFrmHeap(void *mem, u32 size, u32 opt);
void NNS_FndDestroyFrmHeap(void *heap);
u32 NNS_FndAllocFromFrmHeapEx(char *p, int size, int align);
void NNS_FndFreeToFrmHeap(void *heap, int flags);
int NNS_FndRecordStateForFrmHeap(NNSiFndHeapHead *pHeapHd, u32 tagName);
BOOL NNS_FndFreeByStateToFrmHeap(NNSFndHeapHandle heap, u32 tagName);



/*
 * Frame-heap init ('FRMH' tag 0x46524D48): the common heap header through
 * NNSi_FndInitHeapHead, then the two cursors copied from the block bounds and the
 * state word cleared.  The load/store interleave tell of the 2.0 front end
 * (docs/FRONTEND-PINS.md, pkt_02060480 family): the image writes
 * ldr/mov/str/ldr/mov/str/str at 0x02060FC4..0x02060FDC; 1.1p1 hoists both
 * loads above the stores (17 bytes out, docs/notes/pkt_02060FA4.c.txt).
 * Under ../2.0/sp2 the same C is 68 bytes, 0 mismatches.
 */
NNSiFndHeapHead *NNSi_FndInitFrmHeap(NNSiFndHeapHead *pHeapHd, u32 heapStart, u32 heapEnd)
{
    NNSi_FndInitHeapHead(pHeapHd, 0x46524D48, (char *)pHeapHd + 0x30, heapStart, heapEnd);
    GetFrmHeapHeadPtrFromHeapHead(pHeapHd)->headAllocator = pHeapHd->heapStart;
    GetFrmHeapHeadPtrFromHeapHead(pHeapHd)->tailAllocator = pHeapHd->heapEnd;
    GetFrmHeapHeadPtrFromHeapHead(pHeapHd)->pState = 0;
    return pHeapHd;
}





u32 NNSi_FndAllocFromFrmHeapHead(NNSiFndFrmHeapHead *pFrmHeapHd, u32 size, u32 align)
{
    u32 amask = align - 1;
    u32 p = (amask + (u32)pFrmHeapHd->headAllocator) & ~amask;
    u32 e = size + p;
    u32 sz;

    if (e > (u32)pFrmHeapHd->tailAllocator) {
        return 0;
    }

    sz = e - (u32)pFrmHeapHd->headAllocator;
    if ((u8)((u32 *)pFrmHeapHd)[-1] & 1) {
        MIi_CpuClear32(0, pFrmHeapHd->headAllocator, sz);
    }

    pFrmHeapHd->headAllocator = (void *)e;
    return p;
}




u32 NNSi_FndAllocFromFrmHeapTail(NNSiFndFrmHeapHead *pFrmHeapHd, u32 size, u32 align)
{
    u32 v = ((u32)pFrmHeapHd->tailAllocator - size) & ~(align - 1);
    u32 clearedSize;
    u8 attribute;
    if (v < (u32)pFrmHeapHd->headAllocator)
        return 0;
    clearedSize = (u32)pFrmHeapHd->tailAllocator - v;
    attribute = (u8)((u32 *)pFrmHeapHd)[-1];
    if (attribute & 1)
        MIi_CpuClear32(0, (int)v, (int)clearedSize);
    pFrmHeapHd->tailAllocator = (void *)v;
    return v;
}





void NNSi_FndResetFrmHeapHead(NNSiFndHeapHead *pHeapHd){ GetFrmHeapHeadPtrFromHeapHead(pHeapHd)->headAllocator = pHeapHd->heapStart; GetFrmHeapHeadPtrFromHeapHead(pHeapHd)->pState = 0; }




void NNSi_FndResetFrmHeapState(NNSiFndHeapHead *pHeapHd)
{
    NNSiFndFrmHeapState *pState = GetFrmHeapHeadPtrFromHeapHead(pHeapHd)->pState;
    if (pState != 0) {
        do {
            pState->tailAllocator = pHeapHd->heapEnd;
            pState = pState->pPrevState;
        } while (pState != 0);
    }
    GetFrmHeapHeadPtrFromHeapHead(pHeapHd)->tailAllocator = pHeapHd->heapEnd;
}





/*
 * Frame-heap create guard (twin of 0x02060C5C): word-align both ends of the
 * block, refuse anything under 0x30 bytes, else hand (start, end, opt) to
 * NNSi_FndInitFrmHeap.  Two levers closed the old 2-register residue of
 * docs/notes/pkt_020610E0.c.txt: the third parameter is passed straight
 * through in r2 (which is why `end - start` lands in r3), and the end sum is
 * spelled size + mem (`add r1, r1, r0`).
 */
void *NNS_FndCreateFrmHeap(void *mem, u32 size, u32 opt)
{
    u32 end = (size + (u32)mem) & ~3u;
    u32 start = ((u32)mem + 3) & ~3u;
    if (start > end || end - start < 0x30)
        return 0;
    return NNSi_FndInitFrmHeap((NNSiFndHeapHead *)start, end, opt);
}




void NNS_FndDestroyFrmHeap(void *heap){ FNDHEAP_Finalize(heap); }




u32 NNS_FndAllocFromFrmHeapEx(char *p, int size, int align)
{
    if (size == 0)
        size = 1;
    size = (size + 3) & ~3;
    p += 0x24;
    if (align >= 0)
        return NNSi_FndAllocFromFrmHeapHead((NNSiFndFrmHeapHead *)p, (u32)size, (u32)align);
    else
        return NNSi_FndAllocFromFrmHeapTail((NNSiFndFrmHeapHead *)p, (u32)size, (u32)-align);
}




void NNS_FndFreeToFrmHeap(void *heap, int flags)
{
    if (flags & 1)
        NNSi_FndResetFrmHeapHead(heap);
    if (flags & 2)
        NNSi_FndResetFrmHeapState(heap);
}





int NNS_FndRecordStateForFrmHeap(NNSiFndHeapHead *pHeapHd, u32 tagName)
{
    NNSiFndFrmHeapHead *pFrmHeapHd = GetFrmHeapHeadPtrFromHeapHead(pHeapHd);
    NNSiFndFrmHeapState *pState;
    u32 savedHeadAllocator = (u32)pFrmHeapHd->headAllocator;

    pState = (NNSiFndFrmHeapState *)NNSi_FndAllocFromFrmHeapHead(pFrmHeapHd, 0x10, 4);
    if (pState == 0) {
        return 0;
    }

    pState->tagName = tagName;
    pState->headAllocator = (void *)savedHeadAllocator;
    pState->tailAllocator = pFrmHeapHd->tailAllocator;
    pState->pPrevState = pFrmHeapHd->pState;
    pFrmHeapHd->pState = pState;
    return 1;
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
