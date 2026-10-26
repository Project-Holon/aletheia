/*
 * file:     wf2dmap_cmdq.c
 * unit:     yes
 * function: WF2DMAP_CMDQ_CreateStore, WF2DMAP_CMDQ_DeleteStore, WF2DMAP_CMDQ_Push, WF2DMAP_CMDQ_Pop
 * address:  0x021C5EEC
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   sWf2dmapCmdqFileName 0x021C6158 data a1
 *   GFL_HEAP_Free  0x020307B0  arm
 *   _u32_div_f 0x0209C2B0 arm
 */

#include "../types.h"

/* A cell coordinate (the command queue carries grid positions). */
typedef struct Wf2dmapCmdPos {
    u16 x;
    u16 y;
} Wf2dmapCmdPos;

/* Ring buffer of positions; readIndex == writeIndex means empty. */
typedef struct Wf2dmapCmdRing {
    Wf2dmapCmdPos *entries;
    u32 slotCount;
    u16 readIndex;
    u16 writeIndex;
} Wf2dmapCmdRing;

/* Heap store the queue allocates through; entries is a 4-byte slot array. */
typedef struct Wf2dmapCmdStore {
    void *entries;
    u32 slotCount;
    u16 usedCount;
    u16 capacity;
} Wf2dmapCmdStore;

#ifdef __MWERKS__
#define GFL_HEAP_Alloc GFL_HEAP_Alloc_hdr
#endif
#include "../arm9/gfl_heap_wrap.h"
#ifdef __MWERKS__
#undef GFL_HEAP_Alloc
void * GFL_HEAP_Alloc(u16, u32, int, const char *, u16);
#endif
extern u32 _u32_div_f(u32, u32);
extern int WF2DMAP_CMDQ_Pop(Wf2dmapCmdRing *, Wf2dmapCmdPos *);
extern const char sWf2dmapCmdqFileName[];

Wf2dmapCmdStore *WF2DMAP_CMDQ_CreateStore(int n, int heap)
{
    Wf2dmapCmdStore *p;
    p = GFL_HEAP_Alloc(heap, sizeof(Wf2dmapCmdStore), 1, sWf2dmapCmdqFileName, 211);
    p->slotCount = n + 1;
    p->entries = GFL_HEAP_Alloc(heap, p->slotCount * 4, 1, sWf2dmapCmdqFileName, 216);
    p->usedCount = 0;
    p->capacity = 0;
    return p;
}

/*
 * Addresses are Black-image addresses.
 */
void WF2DMAP_CMDQ_DeleteStore(u8 *p)
{
    GFL_HEAP_Free(((Wf2dmapCmdStore *)p)->entries);
    GFL_HEAP_Free(p);
}

void WF2DMAP_CMDQ_Push(Wf2dmapCmdRing *p, const Wf2dmapCmdPos *q) { Wf2dmapCmdPos tmp; if ((p->writeIndex + 1u) % p->slotCount == p->readIndex) WF2DMAP_CMDQ_Pop(p, &tmp); p->entries[p->writeIndex] = *q; p->writeIndex = (p->writeIndex + 1u) % p->slotCount; }

int WF2DMAP_CMDQ_Pop(Wf2dmapCmdRing *a, Wf2dmapCmdPos *out)
{
    if (a->writeIndex == a->readIndex)
        return 0;
    *out = a->entries[a->readIndex];
    a->readIndex = (a->readIndex + 1) % a->slotCount;
    return 1;
}
