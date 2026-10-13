/*
 * function: GPOWER_LoadPowerTable
 * address:  0x02010F7C
 * packet:   pkt_02010F18
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads archive 0x26 member 0 on the given heap.
 *
 * symbols:
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *ARC_TOOL_LoadMember(u32 arc, u32 member, u32 heap);

void *GPOWER_LoadPowerTable(u32 heap)
{
    return ARC_TOOL_LoadMember(0x26, 0, heap);
}
