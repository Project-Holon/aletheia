/*
 * function: func_021F1968
 * address: 0x021F1968
 * packet: pkt_ov194_021F1968
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
#include "../include/Obj10805.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
void func_021F1968(u8 *p) { int i; for(i=0;i<21;i++) { void *q=*(void **)((u32)p+(u32)i*4+12); if(q)func_0204B3B4(q); } func_0204ADA4(((struct Obj10805 *)p)->f0);func_0204A8D4((u32)(((struct Obj10805 *)p)->f4));func_0204AFD8(((struct Obj10805 *)p)->f8); }
