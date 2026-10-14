/*
 * function: func_021C083C
 * address:  0x021C083C
 * packet:   pkt_ov217_021C083C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PALETTE_ANIME_Create  0x021C29C8  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25970.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef unsigned int   u32;
extern u32 PALETTE_ANIME_Create(u32 a0);

void func_021C083C(u8 *p)
{
    int i;
    for (i = 0; i < 8; i++)
        *(int *)(p + i * 4 + 0x324) = PALETTE_ANIME_Create(((struct Obj25970 *)p)->f4);
}
