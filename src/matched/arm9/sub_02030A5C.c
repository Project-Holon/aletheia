/*
 * unit:     no
 * address:  0x02030A5C
 * packet:   pkt_020307E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: GFL_HEAP_DumpIfLive
 *
 * Dumps a heap, but only if the heap actually has live allocations.
 *
 *   void GFL_HEAP_DumpIfLive(u32 heapId)
 *
 * sub_0203046C returns the heap's +0xc record halfword, which
 * sub_02030098 increments on every successful allocation, so a zero answer
 * means an empty heap and there is nothing to report. Note that the
 * out-of-range answer from sub_0203046C is 0xffff, not zero, so a bad id
 * still reaches sub_02030B50; the range check is left to that call.
 *
 * The id has to survive the first call, which is what spends r4.
 *
 * symbols:
 *   sub_0203046C    0x0203046C  arm
 *   sub_02030B50    0x02030B50  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_HEAP_DumpIfLive.c \
 *       --func GFL_HEAP_DumpIfLive --addr 0x02030A5C --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u16 sub_0203046C(u32 heapId);
extern void sub_02030B50(void *p);

void GFL_HEAP_DumpIfLive(u32 heapId)
{
    if (sub_0203046C(heapId) != 0) {
        sub_02030B50((void *)heapId);
    }
}
