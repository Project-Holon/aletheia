/*
 * function: GDS_RAP_IsIdle
 * address: 0x021D730C
 * packet: pkt_ov125_021D730C
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 */
#include "../include/Obj02838.h"
int GDS_RAP_IsIdle(char *p) { if (*(unsigned int *)&((struct Obj02838 *)p)->f3D8==0x55f4 && ((struct Obj02838 *)p)->f3DC==0x55f4) return 1; return 0; }
