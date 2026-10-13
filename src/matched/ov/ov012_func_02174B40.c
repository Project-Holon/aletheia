/*
 * function: COLOSSEUM_AddCommandTable
 * address: 0x02174B40
 * packet: pkt_ov012_02174B40
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   gColosseumCommandTable 0x02175588 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void GFL_NET_COMMAND_AddCommandTable(u32,u32,u32,u32);
extern u32 gColosseumCommandTable[];
void COLOSSEUM_AddCommandTable(u32 p)
{
    GFL_NET_COMMAND_AddCommandTable(0x1500, (u32)gColosseumCommandTable, 14, p);
}
