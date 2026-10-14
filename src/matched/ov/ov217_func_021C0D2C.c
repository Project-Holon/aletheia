/*
 * function: RESEARCH_COMMON_ExitPaletteAnime
 * address:  0x021C0D2C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 44)) to PALETTE_ANIME_Restore.
 *
 * symbols:
 *   PALETTE_ANIME_Restore  0x021C2A08  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25995.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int PALETTE_ANIME_Restore(char *p);

void RESEARCH_COMMON_ExitPaletteAnime(u8 *a0)
{
    PALETTE_ANIME_Restore((char *)((u32)(((struct Obj25995 *)a0)->f2C)));
}

