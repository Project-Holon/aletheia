/*
 * function: func_021F056C
 * address: 0x021F056C
 * packet: pkt_ov031_021F056C
 * region: ov031
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 */
struct Obj;
extern void func_0204B3B4(struct Obj *p);
void func_021F056C(char *p) { int i; for (i=0;i<6;i++) func_0204B3B4((struct Obj *)(*(unsigned *)(p+i*4+0x18))); }
