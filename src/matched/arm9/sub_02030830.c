/*
 * unit:     no
 * address:  0x02030830
 * packet:   pkt_020307E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: GFL_HEAP_GetHeapHead
 *
 * Asserting wrapper around GFL_HEAP_GetTotalFreeSize: forwards its single argument,
 * terminates if the result is NULL, and hands the result back either way.
 *
 *   void *GFL_HEAP_GetHeapHead(u32 heapId)
 *
 * The `movs r4, r0` that both saves and tests the result is the tell that
 * the value is bound to a local before being compared, not compared as a
 * call expression; the value has to survive the OS_Terminate call, which
 * is what spends r4.
 *
 * symbols:
 *   GFL_HEAP_GetTotalFreeSize    0x02030344  arm
 *   OS_Terminate    0x02088234  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_HEAP_GetHeapHead.c \
 *       --func GFL_HEAP_GetHeapHead --addr 0x02030830 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void *GFL_HEAP_GetTotalFreeSize(u32 heapId);
extern void OS_Terminate(void);

void *GFL_HEAP_GetHeapHead(u32 heapId)
{
    void *p;

    p = GFL_HEAP_GetTotalFreeSize(heapId);
    if (p == 0) {
        OS_Terminate();
    }
    return p;
}
