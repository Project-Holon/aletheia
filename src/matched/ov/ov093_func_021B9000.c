/*
 * function: func_021B9000
 * address: 0x021B9000
 * packet: pkt_ov093_021B9000
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9010 0x021B9010 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 func_021B9010(u8 *p, u8 k);
u8 func_021B9000(u8 *p) { return func_021B9010(p,p[0x46c]); }
