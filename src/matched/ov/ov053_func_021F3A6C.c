/*
 * function: func_021F3A6C
 * address: 0x021F3A6C
 * packet: pkt_ov053_021F3A6C
 * region: ov053
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_SetBgmTrackVolume 0x02005F24 thumb
 */
#include "../include/Obj13117.h"

typedef unsigned int u32;
extern void GFL_USE_SetBgmTrackVolume(u32, u32);
void func_021F3A6C(int *p) { GFL_USE_SetBgmTrackVolume(((struct Obj13117 *)p)->f58, ((struct Obj13117 *)p)->f64); }
