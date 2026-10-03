/*
 * function: func_021BF08C
 * address: 0x021BF08C
 * packet: pkt_ov110_021BF08C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035CB8 0x02035CB8 arm
 *   func_021BAD14 0x021BAD14 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned int   u32;
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern void func_021BAD14(u8 *,unsigned);
int func_021BF08C(u8 *p) {
 unsigned x,y;
 if(func_02035CB8(&x,&y)==1 && p[0x6a]==1) { func_021BAD14(*(u8 **)(p+0x14),y); return 1; }
 p[0x6a]=0;
 return 0;
}
