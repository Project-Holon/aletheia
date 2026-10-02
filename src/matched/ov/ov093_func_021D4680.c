/*
 * function: func_021D4680
 * address: 0x021D4680
 * packet: pkt_ov093_021D4680
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F3B88 0x021F3B88 data ov093 a4
 *   func_0203D3F8 0x0203D3F8 arm
 */
typedef unsigned int u32;
extern u32 *d_021F3B88;
extern u32 func_0203D3F8(u32,u32,u32,u32,u32,u32,u32,u32);
u32 func_021D4680(u32 *a) { return func_0203D3F8(*d_021F3B88,255,0x104,(*a>>8)+4,(u32)a,0,1,1); }
