/*
 * function: func_021B96B8
 * address: 0x021B96B8
 * packet: pkt_ov100_021B96B8
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202208C 0x0202208C thumb
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B95D8 0x021B95D8 thumb ov100
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_021B95B8(u8 *,u32);
extern void func_021B95D8(u8 *);
void func_021B96B8(u8 *a){func_0202208C(0,0,0,0,6,1,*(unsigned short *)(a+0x278));func_021B95B8(a,(u32)func_021B95D8);}
