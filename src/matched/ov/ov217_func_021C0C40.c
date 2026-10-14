/*
 * function: RESEARCH_COMMON_CreatePalAnm
 * address:  0x021C0C40
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reconstructed from the listing.
 *
 * symbols:
 *   RESEARCH_COMMON_CreatePalAnm  0x021C0C40  thumb  ov217
 *   PALANM_Create  0x02021518  thumb  arm9
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00791.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void *PALANM_Create(u32 heap);
void RESEARCH_COMMON_CreatePalAnm(u32 a0)
{
    *(u32 *)&((struct Obj00791 *)(((u8*)a0 + 0)))->f28 = (u32)PALANM_Create(((struct Obj00791 *)((u8*)a0))->f0);
}

