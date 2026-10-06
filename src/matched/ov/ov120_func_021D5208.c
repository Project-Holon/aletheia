/*
 * function: func_021D5208
 * address: 0x021D5208
 * packet: pkt_ov120_021D5208
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_021D6D94 0x021D6D94 thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D588C 0x021D588C thumb ov120
 */
#include "../include/Obj22831.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02040588(unsigned char which, unsigned char enable); extern void func_021D6D94(u8 *); extern void func_021D4244(int,void (*)(int),int); extern void func_021D588C(int);
void func_021D5208(u8 *p) { func_02040588(4,0); func_021D6D94(*(u8 * *)&((struct Obj22831 *)p)->f3C); func_021D4244((int)p,func_021D588C,0x64e); }
