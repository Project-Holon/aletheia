/*
 * function: func_021BC5F0
 * address:  0x021BC5F0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)) to RESEARCH_COMMON_UpdatePaletteAnime.
 *
 * symbols:
 *   RESEARCH_COMMON_UpdatePaletteAnime  0x021C09D0  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25861.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void RESEARCH_COMMON_UpdatePaletteAnime(u32);

void func_021BC5F0(u8 *a0)
{
    RESEARCH_COMMON_UpdatePaletteAnime((u32)(((struct Obj25861 *)a0)->f0));
}

