/*
 * function: FIELD_G3D_MAP_Reset
 * address: 0x0216990C
 * packet: pkt_ov010_0216990C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELD_G3D_MAP_ClearPlacements 0x02169880 thumb ov010
 */
#include "../include/Obj00306.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void FIELD_G3D_MAP_ClearPlacements(u8 *);
void FIELD_G3D_MAP_Reset(u8 *p) { ((struct Obj00306 *)p)->f0=0; ((struct Obj00306 *)p)->f4=0; ((struct Obj00306 *)p)->f8=0; ((struct Obj00306 *)p)->fC=0; ((struct Obj00306 *)p)->fB0=0; ((struct Obj00306 *)p)->f14=0; FIELD_G3D_MAP_ClearPlacements(p); }
