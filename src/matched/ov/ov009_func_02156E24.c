/*
 * function: DWC_RAPCOMMON_CreateSubHeapUnlimited
 * address:  0x02156E24
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls DWC_RAPCOMMON_CreateSubHeap with a zero third argument.
 *
 * symbols:
 *   DWC_RAPCOMMON_CreateSubHeap  0x02156E30  thumb  ov009
 */

typedef unsigned int   u32;
extern void DWC_RAPCOMMON_CreateSubHeap(u32 a, u32 b, u32 c, u32 d);

void DWC_RAPCOMMON_CreateSubHeapUnlimited(int a, int b, int c)
{
    DWC_RAPCOMMON_CreateSubHeap(a, b, 0, c);
}

