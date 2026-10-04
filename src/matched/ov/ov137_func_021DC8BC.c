/*
 * function: func_021DC8BC
 * address: 0x021DC8BC
 * packet: pkt_ov137_021DC8BC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 */
#include "../include/Obj23666.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S020314B8;
extern void func_0203133C(struct S020314B8 *p);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
int func_021DC8BC(void *obj,int a,int b,u8 *p) { func_0203133C(((struct Obj23666 *)p)->f20); func_020315D4(obj); return 1; }
