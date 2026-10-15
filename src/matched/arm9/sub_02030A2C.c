/*
 * unit:     no
 * address:  0x02030A2C
 * packet:   pkt_020307E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: GFL_HEAP_NotifyFree
 *
 * The free-side watch filter, exactly the shape of GFL_HEAP_NotifyAlloc on the
 * allocation side: the audit runs only when the global watch id names this
 * block's heap.
 *
 *   void GFL_HEAP_NotifyFree(void *p)
 *
 * The heap id is not a parameter here, it is read back out of the block's
 * own header by sub_020304B8, which is why the call is scheduled before
 * the global is even loaded: its result has to be in r0, and only then can
 * the conditional-compare pair `cmp r1, #0` / `cmpge r0, r1` fold the two
 * conjuncts. The source order of the conjuncts is still watch-id-first,
 * the order the comparisons appear in.
 *
 * symbols:
 *   g_020A7820      0x020A7820  data
 *   sub_020304B8    0x020304B8  arm
 *   GFL_HEAP_AuditFree    0x020309B8  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_HEAP_NotifyFree.c \
 *       --func GFL_HEAP_NotifyFree --addr 0x02030A2C --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 g_020A7820;
extern u16 sub_020304B8(void *p);
extern void GFL_HEAP_AuditFree(void *p);

void GFL_HEAP_NotifyFree(void *p)
{
    u32 heapId;

    heapId = sub_020304B8(p);
    if (g_020A7820 >= 0 && heapId == (u32)g_020A7820) {
        GFL_HEAP_AuditFree(p);
    }
}
