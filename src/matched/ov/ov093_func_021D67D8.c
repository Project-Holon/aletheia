/*
 * function: BTL_POKEPARAM_SetWeight
 * address: 0x021D67D8
 * packet: pkt_ov093_021D67D8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj21235.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void BTL_POKEPARAM_SetWeight(u8 *p, u32 n) { if(n<1) n=1; ((struct Obj21235 *)p)->f13E=n; }
