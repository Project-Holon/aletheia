/*
 * unit:     no
 * address:  0x02030A00
 * packet:   pkt_020307E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: GFL_HEAP_NotifyAlloc
 *
 * Success-side bookkeeping for the allocation entry point GFL_HEAP_Alloc,
 * and a debug filter: the whole body is gated on a global watch id.
 *
 *   void GFL_HEAP_NotifyAlloc(u32 heapId, void *p, u32 size)
 *
 * g_020A7820 is a signed watch id, -1 (or any negative value) meaning
 * "watch nothing". Only when it is non-negative and equal to the heap id
 * of this allocation does the block get handed to GFL_HEAP_AuditAlloc, which
 * validates the provenance name stamped by GFL_HEAP_StampAllocSite.
 *
 * The `cmp r3, #0` / `cmpge r0, r3` pair is the conditional-compare fold
 * of a single `&&`: the first comparison is the first-written conjunct,
 * and the guard must be one expression, not two sequential `if`s, for the
 * `popne` to serve both.
 *
 * symbols:
 *   g_020A7820      0x020A7820  data
 *   GFL_HEAP_AuditAlloc    0x02030984  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_HEAP_NotifyAlloc.c \
 *       --func GFL_HEAP_NotifyAlloc --addr 0x02030A00 --cc 1.1p1 --arm
 */

typedef unsigned int u32;
typedef signed int s32;

extern s32 g_020A7820;
extern void GFL_HEAP_AuditAlloc(void *p, u32 size);

void GFL_HEAP_NotifyAlloc(u32 heapId, void *p, u32 size)
{
    if (g_020A7820 >= 0 && heapId == (u32)g_020A7820) {
        GFL_HEAP_AuditAlloc(p, size);
    }
}
