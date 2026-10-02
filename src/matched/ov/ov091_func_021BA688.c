/*
 * function: func_021BA688
 * address: 0x021BA688
 * packet: pkt_ov091_021BA688
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02007E50 0x02007E50 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_02007E50(u8 *, u16, u16, u16);
u32 func_021BA688(u8 *p, u16 id) { return func_02007E50(*(u8 **)(*(u8 **)(p+0x280)+4),id,1,*(u16 *)p); }
