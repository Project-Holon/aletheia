/*
 * function: func_021D4FD0
 * address: 0x021D4FD0
 * packet: pkt_ov120_021D4FD0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D761C 0x021D761C thumb ov120
 *   func_021D883C 0x021D883C thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4FC0 0x021D4FC0 thumb ov120
 */
#include "../../../matched/include/Obj13930.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021D761C(u8 *); extern void func_021D883C(char *); extern void func_021D4244(int,void (*)(int),int); extern void func_021D4FC0(int);
void func_021D4FD0(u8 *p) { func_021D761C(*(u8 * *)&((struct Obj13930 *)p)->f3C); func_021D883C(*(char * *)&((struct Obj13930 *)p)->f40); func_021D4244((int)p,func_021D4FC0,0x5c5); }
