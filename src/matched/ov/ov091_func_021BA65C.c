/*
 * function: func_021BA65C
 * address: 0x021BA65C
 * packet: pkt_ov091_021BA65C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02007FB8 0x02007FB8 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_02007FB8(u8 *, u16, u16);
u32 func_021BA65C(u8 *p, u16 id) { return func_02007FB8(*(u8 **)(*(u8 **)(p+0x280)+4), id, *(u16 *)p); }
