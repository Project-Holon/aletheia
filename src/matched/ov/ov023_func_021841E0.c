/*
 * function: OEKAKI_RegisterNetCommands
 * address: 0x021841E0
 * packet: pkt_ov023_021841E0
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   gOekakiCommandTable 0x02186A6C data ov023 a4
 */
typedef unsigned int u32;
extern char gOekakiCommandTable[];
extern void GFL_NET_COMMAND_AddCommandTable(u32 a, u32 b, u32 c, u32 d);
void OEKAKI_RegisterNetCommands(u32 a)
{
    GFL_NET_COMMAND_AddCommandTable(0x2900, (u32)gOekakiCommandTable, 8, a);
}
