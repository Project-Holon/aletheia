/*
 * function: RESEARCH_LIST_GetFadeWaitFrames
 * address:  0x021BB948
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   RESEARCH_LIST_GetFadeWaitFrames  0x021BB948  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25848.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;


u32 RESEARCH_LIST_GetFadeWaitFrames(u8 *a0)
{
    return ((struct Obj25848 *)(((u8*)a0)))->f28;
}

