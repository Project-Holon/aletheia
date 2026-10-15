/*
 * function: RESEARCH_TOP_CreateCommon
 * address:  0x021B9874
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing.
 *
 * symbols:
 *   RESEARCH_COMMON_Create  0x021C097C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01438.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern int RESEARCH_COMMON_Create(int a0, int a1);
void RESEARCH_TOP_CreateCommon(u32 a0)
{
    ((struct Obj01438 *)(((u8*)a0 + 0)))->fC = RESEARCH_COMMON_Create(((struct Obj01438 *)((u8*)a0))->f0, ((struct Obj01438 *)(((u8*)a0 + 0)))->f4);
}

