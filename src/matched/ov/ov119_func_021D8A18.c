/*
 * function: POKETRADE_PROC_GetStoredBoxIndex
 * address:  0x021D8A18
 * packet:   pkt_ov119_021D8A18
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj22701.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

u8 POKETRADE_PROC_GetStoredBoxIndex(u8 *p) { return ((struct Obj22701 *)p)->f11F2; }
