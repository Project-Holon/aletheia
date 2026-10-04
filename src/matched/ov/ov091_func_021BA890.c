/*
 * function: func_021BA890
 * address: 0x021BA890
 * packet: pkt_ov091_021BA890
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B084 0x0204B084 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj03678.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bank;
struct Descriptor;
struct Obj;
extern void func_020452E8(struct Descriptor *d);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204B084(void *);
extern void func_0204B1CC(struct Bank *bank);
extern void func_0204A8D4(u32);
extern void func_020307B0(void *);
void func_021BA890(void *ignored,u8 *p) { if (!((struct Obj03678 *)p)->f14) { func_020452E8(((struct Obj03678 *)p)->f20); func_0204B3B4(((struct Obj03678 *)p)->f30); func_0204B3B4(((struct Obj03678 *)p)->f34); func_0204B3B4(((struct Obj03678 *)p)->f38); func_0204B084(((struct Obj03678 *)p)->f24); func_0204B1CC(((struct Obj03678 *)p)->f28); func_0204A8D4(((struct Obj03678 *)p)->f2C); } func_020307B0(p); }
