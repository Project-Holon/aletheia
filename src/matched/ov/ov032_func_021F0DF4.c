/*
 * function: func_021F0DF4
 * address: 0x021F0DF4
 * packet: pkt_ov032_021F0DF4
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B878 0x0204B878 arm
 *   func_0204B9A0 0x0204B9A0 arm
 */
typedef unsigned short u16;
struct Actor;
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B9A0(struct Actor *a);
void func_021F0DF4(void *p, unsigned short v) { func_0204B878(p,v); func_0204B9A0(p); }
