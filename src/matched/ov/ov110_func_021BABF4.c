/*
 * function: func_021BABF4
 * address:  0x021BABF4
 * packet:   pkt_ov110_021BABF4
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unblocked by matching func_021BC6E0 in ov110 (pkt_ov110_021BC6E0).
 *
 * symbols:
 *   func_021BC6E0  0x021BC6E0  thumb  ov110
 */
#include "../include/Obj22337.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern u16 func_021BC6E0(u8 *p, int i);
u16 func_021BABF4(u8 *p, int i) { return func_021BC6E0(*(u8 * *)&((struct Obj22337 *)p)->f54, i); }
