/*
 * function: BTL_SERVER_FLOW_ResetHandExBuffer
 * address: 0x021CC8C8
 * packet: pkt_ov093_021CC8C8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 */
typedef unsigned int u32;
extern void MI_CpuFill8(void *, int, u32);
void BTL_SERVER_FLOW_ResetHandExBuffer(u32 *p) { *p++=0; MI_CpuFill8(p,0,500); }
