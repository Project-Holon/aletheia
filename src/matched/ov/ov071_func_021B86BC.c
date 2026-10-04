/*
 * function: func_021B86BC
 * address: 0x021B86BC
 * packet: pkt_ov071_021B86BC
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020498F4 0x020498F4 arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../include/Obj20735.h"

typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020409B4(unsigned int);
void func_021B86BC(char *p) { func_020498F4((void *)(((struct Obj20735 *)p)->f30),12,2,0,0,1,0x61); func_020409B4(0); func_020409B4(2); }
