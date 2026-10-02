/*
 * function: func_021B90F8
 * address: 0x021B90F8
 * packet: pkt_ov093_021B90F8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
int func_021B90F8(u8 *p) { u8 *q; q=*(u8 **)p; if(*(u32 *)(q+0x94)!=0 && q[0x23]==0) return 1; return 0; }
