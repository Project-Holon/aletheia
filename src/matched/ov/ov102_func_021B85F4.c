/*
 * function: func_021B85F4
 * address: 0x021B85F4
 * packet: pkt_ov102_021B85F4
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_02051C6C 0x02051C6C arm
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj13728.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02051C6C(void *);
extern void func_02082BCC(void *, int, u32);
void func_021B85F4(u8 *p) { int i; for(i=0;i<((struct Obj13728 *)p)->f2C;i++)func_020452E8(*(void **)(p+4+i*4)); func_02051C6C(((struct Obj13728 *)p)->f0); func_02082BCC(p,0,60); }
