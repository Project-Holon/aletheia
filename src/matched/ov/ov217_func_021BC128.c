/*
 * function: RESEARCH_LIST_ShowEntryLabels
 * address:  0x021BC128
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   BgTextLabel_SetVisible  0x021C0FF8  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00025.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 BgTextLabel_SetVisible();
u32 RESEARCH_LIST_ShowEntryLabels(u32 a0)
{
    BgTextLabel_SetVisible(((struct Obj00025 *)((u8*)a0))->fE4, 1);
    BgTextLabel_SetVisible(((struct Obj00025 *)((u8*)a0))->fE8, 1);
    BgTextLabel_SetVisible(((struct Obj00025 *)((u8*)a0))->fEC, 1);
    BgTextLabel_SetVisible(((struct Obj00025 *)((u8*)a0))->fF0, 1);
    return BgTextLabel_SetVisible(((struct Obj00025 *)((u8*)a0))->fF4, 1);
}

