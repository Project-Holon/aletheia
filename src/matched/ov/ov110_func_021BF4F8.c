/*
 * function: PMS_INPUT_SetSubHandler
 * address:  0x021BF4F8
 * packet:   pkt_ov110_021BF4F8
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj13795.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

void PMS_INPUT_SetSubHandler(u8 *p, u32 v) { ((struct Obj13795 *)p)->f30 = v; ((struct Obj13795 *)p)->f2C = 0; }
