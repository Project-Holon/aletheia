/*
 * function: MUSICAL_MCSS_ElemHasAltDepth
 * address:  0x021F4B24
 * packet:   pkt_ov112_021F4B24
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MUSICAL_MCSS_ElemDataHasAltDepth  0x021F50D0  thumb  ov112
 */
#include "../include/Obj22521.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int MUSICAL_MCSS_ElemDataHasAltDepth(const unsigned char *p);
int MUSICAL_MCSS_ElemHasAltDepth(u8 *p) { return MUSICAL_MCSS_ElemDataHasAltDepth((const unsigned char *)(((struct Obj22521 *)p)->f20)); }
