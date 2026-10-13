/*
 * function: BTL_POKEPARAM_GetMoveStreak
 * address: 0x021D679C
 * packet: pkt_ov093_021D679C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj21234.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
u16 BTL_POKEPARAM_GetMoveStreak(u8 *p) { return ((struct Obj21234 *)p)->f14E; }
