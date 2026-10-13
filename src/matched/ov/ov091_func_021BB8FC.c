/*
 * function: PLIST_MESSAGE_IsIdle
 * address: 0x021BB8FC
 * packet: pkt_ov091_021BB8FC
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj13252.h"
typedef unsigned int u32;
int PLIST_MESSAGE_IsIdle(void *unused, u32 p) { if (((struct Obj13252 *)p)->fC==0 && ((struct Obj13252 *)p)->f24==0) return 1; return 0; }
