/*
 * function: BTL_CLIENT_SET_Clear
 * address: 0x021D8230
 * packet: pkt_ov093_021D8230
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj13452.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
void BTL_CLIENT_SET_Clear(u8 *p) { u32 i; for(i=0;i<4;i++) p[4+i]=4; ((struct Obj13452 *)p)->f0=0; }
