/*
 * function: IRCBATTLEMATCH_SetStep
 * address:  0x021B95B8
 * packet:   pkt_ov100_021B95B8
 * region:   ov100
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj22063.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

void IRCBATTLEMATCH_SetStep(u8 *p, u32 v) { ((struct Obj22063 *)p)->f248 = v; }
