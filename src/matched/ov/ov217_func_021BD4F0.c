/*
 * function: RESEARCH_LIST_CreatePaletteAnime
 * address:  0x021BD4F0
 * packet:   pkt_021BD4F0
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PALETTE_ANIME_Create  0x021C29C8  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00025.h"

typedef unsigned short u16;

typedef unsigned int   u32;
extern u32 PALETTE_ANIME_Create(u32 a0);

void RESEARCH_LIST_CreatePaletteAnime(char *p)
{
    int i;
    for (i = 0; i < 6; i++)
        ((int *)(p + 0x9c))[i] = PALETTE_ANIME_Create(((struct Obj00025 *)p)->f8);
}
