/*
 * function: PALETTE_ANIME_StartImpl
 * address:  0x021C2A18
 * packet:   pkt_ov217_021C09D8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled 14-byte ov217 leaf in a .word run; target of the veneer at
 * 0x021C29F8 and the bottom of the RESEARCH_TOP_StartPaletteAnime blocker chain.  Store order
 * in the source is +0x14, +0x18, +0x1c, +0x12.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj08447.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void PALETTE_ANIME_StartImpl(u8 *p, u32 b, u16 c)
{
    ((struct Obj08447 *)p)->f14 = 1;
    ((struct Obj08447 *)p)->f18 = b;
    ((struct Obj08447 *)p)->f1C = 0;
    ((struct Obj08447 *)p)->f12 = c;
}
