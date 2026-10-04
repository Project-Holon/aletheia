/*
 * function: func_020606D0
 * address:  0x020606D0
 * packet:   pkt_020606D0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_02060468         0x02060468  arm
 *   func_020606A8         0x020606A8  arm
 *   func_020604AC         0x020604AC  arm
 *   sRootListInitialized  0x02146B60  data
 *   sRootList             0x02146B64  data
 *
 * NitroSystem fnd heapcommon.c, NNSi_FndInitHeapHead: fill the heap header,
 * set the option byte of the attribute (SetOptForHeap as an inline over the
 * NNSi_FndSetBitValue macro), init the child list (link offset 4), create the
 * root heap list once, and append the heap to the list FindListContainHeap
 * (func_020606A8) picks.  The kept-constants tell (docs/FRONTEND-PINS.md): the
 * image passes the offset 4 as a fresh `mov r1, #4` at both NNS_FndInitList
 * calls (+0x2C, +0x4C) and reloads the latch address from the pool at +0x38
 * and +0x54 under `push {r4, lr}`.  docs/notes/func_020606D0.c.txt measured
 * the pin on an arena-registry reading of this body and found it worse; in
 * the library's shape (attribute cleared then set through the macro, signed
 * BOOL latch, header struct from heapcommon.h) ../2.0/sp2 gives 124 bytes,
 * 0 mismatches, where 1.1p1 gives 73 out.
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef int BOOL;

typedef struct NNSFndLink { void *prevObject; void *nextObject; } NNSFndLink;
typedef struct NNSFndList { void *headObject; void *tailObject; u16 numObjects; u16 offset; } NNSFndList;

typedef struct NNSiFndHeapHead {
    u32 signature;
    NNSFndLink link;
    NNSFndList childList;
    void *heapStart;
    void *heapEnd;
    u32 attribute;
} NNSiFndHeapHead;

extern void func_02060468(NNSFndList *list, u16 offset);           /* NNS_FndInitList */
extern void *func_020606A8(u32 a);        /* FindListContainHeap */
extern void func_020604AC(NNSFndList *list, void *object);        /* NNS_FndAppendListObject */

extern BOOL sRootListInitialized;
extern NNSFndList sRootList;

#define NNSi_FndSetBitValue(data, st, bits, val) \
    ((data) = (((data) & ~(((1u << (bits)) - 1) << (st))) | (((val) & ((1u << (bits)) - 1)) << (st))))

static inline void SetOptForHeap(NNSiFndHeapHead *pHeapHd, u16 optFlag)
{
    NNSi_FndSetBitValue(pHeapHd->attribute, 0, 8, optFlag);
}

void func_020606D0(NNSiFndHeapHead *pHeapHd, u32 signature, void *heapStart, void *heapEnd, u16 optFlag)
{
    pHeapHd->signature = signature;
    pHeapHd->heapStart = heapStart;
    pHeapHd->heapEnd = heapEnd;
    pHeapHd->attribute = 0;
    SetOptForHeap(pHeapHd, optFlag);

    func_02060468(&pHeapHd->childList, 4);

    if (!sRootListInitialized) {
        func_02060468(&sRootList, 4);
        sRootListInitialized = 1;
    }

    func_020604AC(func_020606A8((u32)pHeapHd), pHeapHd);
}
