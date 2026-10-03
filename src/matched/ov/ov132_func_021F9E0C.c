/*
 * function: func_021F9E0C
 * address: 0x021F9E0C
 * packet: pkt_ov132_021F9E0C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F4F10 0x021F4F10 thumb ov112
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_021F4F10(u8 *);
u32 func_021F9E0C(u8 *p) { return func_021F4F10(*(u8 **)(p+56)); }
