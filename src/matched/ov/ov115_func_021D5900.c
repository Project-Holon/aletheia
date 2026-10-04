/*
 * function: func_021D5900
 * address: 0x021D5900
 * packet: pkt_ov115_021D5900
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040618 0x02040618 arm
 *   func_0204A648 0x0204A648 arm
 */
#include "../include/Obj10333.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0204A648(void);
void func_021D5900(void *task,u8 *p) { if(((struct Obj10333 *)p)->fB4A>0) { func_02040618(7,0,((struct Obj10333 *)p)->fB4A-1); func_02040618(2,0,((struct Obj10333 *)p)->fB4A-1); } func_0204A648(); }
