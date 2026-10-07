/*
 * function: func_021BA014
 * address: 0x021BA014
 * packet: pkt_ov213_021BA014
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
void func_021BA014(u8 *p) {int i;for(i=0;i<p[11];i++)func_0204B3B4((struct Obj *)(*(u32 *)(p+12+i*4)));}
