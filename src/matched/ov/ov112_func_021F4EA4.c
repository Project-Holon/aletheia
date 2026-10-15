/*
 * function: MUSICAL_MCSS_SetElemScale
 * address: 0x021F4EA4
 * packet: pkt_ov112_021F4EA4
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
#include "../include/Obj01396.h"
#include "../include/Obj10300.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
void MUSICAL_MCSS_SetElemScale(u32 unused,u32 p,u32 q) { ((struct Obj10300 *)q)->f0=((struct Obj01396 *)p)->f10; ((struct Obj10300 *)q)->f4=((struct Obj01396 *)p)->f14; ((struct Obj10300 *)q)->f8=((struct Obj01396 *)p)->f18; }
