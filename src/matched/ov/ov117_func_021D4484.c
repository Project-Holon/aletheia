/*
 * function: POKETRADE_DEMO_COMMON_SetFrame
 * address:  0x021D4484
 * packet:   pkt_ov117_021D4484
 * region:   ov117
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj22643.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

void POKETRADE_DEMO_COMMON_SetFrame(u8 *p, u32 v) { ((struct Obj22643 *)p)->fF2C = v; }
