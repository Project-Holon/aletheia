/*
 * function: POKETRADE_DEMO_COMMON_SetFinishFlag
 * address:  0x021D4490
 * packet:   pkt_ov117_021D4490
 * region:   ov117
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj22644.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

void POKETRADE_DEMO_COMMON_SetFinishFlag(u8 *p) { ((struct Obj22644 *)p)->f1094 = 1; }
