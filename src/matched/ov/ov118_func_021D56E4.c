/*
 * function: POKETRADE_DEMO_UP_SetFrame
 * address:  0x021D56E4
 * packet:   pkt_ov118_021D56E4
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj22673.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

void POKETRADE_DEMO_UP_SetFrame(u8 *p, u32 v) { ((struct Obj22673 *)p)->fF2C = v; }
