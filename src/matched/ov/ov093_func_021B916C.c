/*
 * function: BTL_MAIN_SetOutcomeIfUnset
 * address: 0x021B916C
 * packet: pkt_ov093_021B916C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj13275.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void BTL_MAIN_SetOutcomeIfUnset(u8 *p,u32 x) { if(((struct Obj13275 *)p)->f444==7) ((struct Obj13275 *)p)->f444=x; }
