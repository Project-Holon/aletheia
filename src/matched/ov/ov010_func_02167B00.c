/*
 * function: BSUBWAY_COMM_AddCommandTable
 * address: 0x02167B00
 * packet: pkt_ov010_02167B00
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Trailing extent is already matched BSUBWAY_COMM_DeleteCommandTable.
 * symbols:
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   d_02171FD4 0x02171FD4 data ov010 a4
 */
typedef unsigned int u32;
extern void GFL_NET_COMMAND_AddCommandTable(u32, u32, u32, u32);
extern const u32 d_02171FD4[];
void BSUBWAY_COMM_AddCommandTable(u32 a)
{
    GFL_NET_COMMAND_AddCommandTable(0x2c00, (u32)d_02171FD4, 0x2c08, a);
}
