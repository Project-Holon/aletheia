/*
 * function: MUSICAL_MCSS_IsMCAnimHidden
 * address:  0x021F62D0
 * packet:   pkt_ov112_021F62D0
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj22547.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

u32 MUSICAL_MCSS_IsMCAnimHidden(u8 *p) { return (((struct Obj22547 *)p)->fEC << 29) >> 31; }
