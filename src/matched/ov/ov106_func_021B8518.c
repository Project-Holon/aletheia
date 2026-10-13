/*
 * function: IRC_RANKING_ListGetScrollMax
 * address:  0x021B8518
 * packet:   pkt_ov106_021B8518
 * region:   ov106
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj22264.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

s16 IRC_RANKING_ListGetScrollMax(u8 *p) { return ((struct Obj22264 *)p)->f55A; }
