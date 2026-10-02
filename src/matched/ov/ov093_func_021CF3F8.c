/*
 * function: func_021CF3F8
 * address: 0x021CF3F8
 * packet: pkt_ov093_021CF3F8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021CF3B8 0x021CF3B8 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021CF3B8(u8 *,u8);
void func_021CF3F8(u8 *p) { u32 i; if(p[0x1aa]==0) for(i=0;i<3;i++) func_021CF3B8(p,i); }
