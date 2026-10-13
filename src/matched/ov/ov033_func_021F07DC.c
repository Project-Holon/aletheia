/*
 * function: DOWSING_FreeBackground
 * address: 0x021F07DC
 * packet: pkt_ov033_021F07DC
 * region: ov033
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203FB44 0x0203FB44 arm
 */
#include "../include/Obj20475.h"
typedef unsigned int   u32;
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
void DOWSING_FreeBackground(char *p) { unsigned v = ((struct Obj20475 *)p)->f10; func_0203FB44(7, (unsigned short)v, (unsigned short)(v>>16)); }
