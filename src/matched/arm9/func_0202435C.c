/*
 * function: func_0202435C
 * address:  0x0202435C
 * packet:   pkt_0202435C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   sub_02024368  0x02024368  thumb
 *
 * sub_02024368 with a count of 2: a tail call through the pool.  Seeded in
 * layout/function_starts.txt from the bl sites in ov010, ov069 and ov093
 * (w6_fix18).
 */

typedef unsigned short u16;
typedef unsigned int   u32;
extern void *sub_02024368(u16 *slots, u32 heap, int count);

void *func_0202435C(void *slots, unsigned int heap)
{
    return sub_02024368(slots, heap, 2);
}
