/*
 * function: MUSICAL_MCSS_GetArcFileCount
 * address: 0x021F4AA8
 * packet: pkt_ov112_021F4AA8
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   ARC_TOOL_GetArchiveFileCount 0x02049030 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 ARC_TOOL_GetArchiveFileCount(u32 a);
u16 MUSICAL_MCSS_GetArcFileCount(int i)
{
    u32 n = (u16)ARC_TOOL_GetArchiveFileCount(45) - 2;
    if (i >= (int)n) return 100;
    return (u16)i;
}
