/*
 * unit: no
 * function: func_021D63E4
 * address: 0x021D63E4
 * packet: pkt_ov123_021D63E4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
struct Obj;
extern void func_0204B3B4(struct Obj *);
void func_021D63E4(u8 *p){int i;for(i=0;i<16;i++){u8 *q=p+i*4;if(*(struct Obj **)(q+0x74)){func_0204B3B4(*(struct Obj **)(q+0x74));*(void **)(q+0x74)=0;}}}
