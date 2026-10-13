/*
 * function: func_021DCB78
 * address: 0x021DCB78
 * packet: pkt_ov137_021DCB78
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   d_021E1A68 0x021E1A68 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u8 d_021E1A68[];
extern void GFL_NET_COMMAND_AddCommandTable(u32,u32,u32,u32);
void func_021DCB78(u32 a) {GFL_NET_COMMAND_AddCommandTable(0x2800,(u32)d_021E1A68,16,a);}
