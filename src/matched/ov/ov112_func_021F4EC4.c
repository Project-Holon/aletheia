/*
 * function: MUSICAL_MCSS_SetElemRot
 * address: 0x021F4EC4
 * packet: pkt_ov112_021F4EC4
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
#include "../include/Obj01396.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
void MUSICAL_MCSS_SetElemRot(u32 unused,u32 p,s16 *a,s16 *b) { *a=((struct Obj01396 *)p)->f1C; *b=((struct Obj01396 *)p)->f1E; }
