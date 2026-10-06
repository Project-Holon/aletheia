/*
 * function: func_021B9010
 * address: 0x021B9010
 * packet: pkt_ov093_021B9010
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B8B9C 0x021B8B9C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021B8B9C(unsigned char *p, unsigned char k);
u8 func_021B9010(u8 *p, u8 k) { u8 n; n=(k+2)&3; if(!func_021B8B9C(p,n)) n=4; return n; }
