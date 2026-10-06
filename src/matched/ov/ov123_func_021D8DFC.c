/*
 * function: func_021D8DFC
 * address: 0x021D8DFC
 * packet: pkt_ov123_021D8DFC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D62B4 0x021D62B4 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8D98 0x021D8D98 thumb ov123
 */
#include "../include/Obj10451.h"
typedef unsigned char  u8;
extern void func_021D62B4(u8 *p, unsigned int i);
typedef unsigned int   u32;
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D8D98(char *p);
void func_021D8DFC(char *p) { if(--((struct Obj10451 *)p)->f60==0) { func_021D62B4(((struct Obj10451 *)p)->f14,4); ((struct Obj10451 *)p)->f60=60; func_021D6EE0((u8 *)p,(int)func_021D8D98,0x9b9); } }
