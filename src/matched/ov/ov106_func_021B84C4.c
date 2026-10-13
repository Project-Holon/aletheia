/*
 * function: IRC_RANKING_ListGetScrollPos
 * address:  0x021B84C4
 * packet:   pkt_ov106_021B84C4
 * region:   ov106
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj22262.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

s16 IRC_RANKING_ListGetScrollPos(u8 *p) { return ((struct Obj22262 *)p)->f556; }
