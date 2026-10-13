/*
 * function: PMS_INPUT_VIEW_GetClactUnit
 * address:  0x021BAC40
 * packet:   pkt_ov110_021BAC40
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj22341.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

u32 PMS_INPUT_VIEW_GetClactUnit(u8 *p) { return ((struct Obj22341 *)p)->f20; }
