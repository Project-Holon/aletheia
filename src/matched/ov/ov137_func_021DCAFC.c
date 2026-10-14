/*
 * function: GURU2_GetUnionApp
 * address: 0x021DCAFC
 * packet: pkt_ov137_021DCAFC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:

 */
#include "../include/Obj23670.h"
#include "../include/Obj23671.h"
typedef unsigned char u8;
typedef unsigned int u32;
void *GURU2_GetUnionApp(u8 *p) { return **(void ** *)&((struct Obj23671 *)(*(u8 * *)&((struct Obj23670 *)p)->f0))->f14; }
