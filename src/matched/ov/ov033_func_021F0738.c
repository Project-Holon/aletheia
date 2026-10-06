/*
 * function: func_021F0738
 * address: 0x021F0738
 * packet: pkt_ov033_021F0738
 * region: ov033
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B1CC 0x0204B1CC arm
 *   func_020403F4 0x020403F4 arm
 *   d_021F0DF0 0x021F0DF0 data ov033 a4
 */
#include "../include/Obj20474.h"
typedef struct { unsigned f00; unsigned f04[8]; unsigned f24; unsigned f28; } E;
extern E d_021F0DF0[];
struct Bank;
extern unsigned int func_0204B1CC(struct Bank *bank);
typedef unsigned int   u32;
extern void func_020403F4(u32 i);
void func_021F0738(char *p) { unsigned i; func_0204B1CC((struct Bank *)(((struct Obj20474 *)p)->fC)); for(i=0;i<2;i++) func_020403F4((unsigned char)d_021F0DF0[i].f00); }
