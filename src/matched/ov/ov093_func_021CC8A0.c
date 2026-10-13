/*
 * function: BTL_SERVER_FLOW_ResetSlotTable
 * address: 0x021CC8A0
 * packet: pkt_ov093_021CC8A0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned int u32;
void BTL_SERVER_FLOW_ResetSlotTable(u32 *p) { u32 i; for (i=0;i<24;i++) p[i]=6; }
