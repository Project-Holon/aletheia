/*
 * function: func_021BCE84
 * address: 0x021BCE84
 * packet: pkt_ov091_021BCE84
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B100 0x0204B100 arm
 */
#include "../include/Obj13261.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Bank;
extern struct Bank *func_0204B100(int,u8,unsigned int);
void func_021BCE84(char *p) { *(struct Bank * *)&((struct Obj13261 *)p)->f1EC=func_0204B100(36,8,((struct Obj13261 *)p)->f0); }
