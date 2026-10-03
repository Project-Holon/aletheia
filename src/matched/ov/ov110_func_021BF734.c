/*
 * function: func_021BF734
 * address: 0x021BF734
 * packet: pkt_ov110_021BF734
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B999C 0x021B999C thumb ov110
 *   func_021BB1C0 0x021BB1C0 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_021B999C(u8 *,int);
extern u8 func_021BB1C0(u8 *);
u32 func_021BF734(u8 *p) {
    if(p[0x69]==0) return func_021B999C(*(u8 **)(p+0x18),*(u16 *)(p+0x4c))+2;
    else return func_021BB1C0(*(u8 **)(p+0x1c))+2;
}
