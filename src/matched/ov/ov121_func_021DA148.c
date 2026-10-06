/*
 * function: func_021DA148
 * address: 0x021DA148
 * packet: pkt_ov121_021DA148
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj06448.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
struct Obj;
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern u32 func_0201F868(void *p);
extern void func_0201F7A8(void *,u32);
extern void func_020456F8(struct Descriptor *d);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_020307B0(void *p);
void func_021DA148(u8 *p) { func_0202020C(((struct Obj06448 *)p)->f10,0,0); func_0201F868(((struct Obj06448 *)p)->f14); func_0201F7A8(((struct Obj06448 *)p)->f0,0); func_020456F8(((struct Obj06448 *)p)->f0); func_020452E8(((struct Obj06448 *)p)->f0); func_020307B0(p); }
