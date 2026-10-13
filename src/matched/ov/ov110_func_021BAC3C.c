/*
 * function: PMS_INPUT_VIEW_GetMenu
 * address:  0x021BAC3C
 * packet:   pkt_ov110_021BAC3C
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj22340.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

u32 PMS_INPUT_VIEW_GetMenu(u8 *p) { return ((struct Obj22340 *)p)->f64; }
