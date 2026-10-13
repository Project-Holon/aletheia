/*
 * function: PLIST_PLATE_IsOccupied
 * address: 0x021BB3C4
 * packet: pkt_ov091_021BB3C4
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
#include "../include/Obj20880.h"
typedef unsigned int u32;
int PLIST_PLATE_IsOccupied(void *unused, u32 p) { if (((struct Obj20880 *)p)->f14 != 1) return 1; return 0; }
