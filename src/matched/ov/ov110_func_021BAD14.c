/*
 * function: func_021BAD14
 * address:  0x021BAD14
 * packet:   pkt_ov110_021BAD14
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BFE24  0x021BFE24  thumb  ov110
 */
#include "../include/Obj22345.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021BFE24(u8 *p, int y);
void func_021BAD14(u8 *p, u32 v) { func_021BFE24((u8 *)(((struct Obj22345 *)p)->f5C), v); }
