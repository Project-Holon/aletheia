/*
 * function: func_021C6DF8
 * address: 0x021C6DF8
 * packet: pkt_ov128_021C6DF8
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B92C 0x0204B92C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
void func_021C6DF8(u8 *p,u32 a) {int i; for(i=0;i<2;i++) func_0204B92C(*(void **)((u32)p+i*4+0x15c),a);}
