/*
 * function: RESEARCH_TOP_CreateFont
 * address:  0x021BA5BC
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
 *   RESEARCH_TOP_CreateFont  0x021BA5BC  thumb  ov217
 *   GF_FONT_Create  0x0201D7EC  thumb  arm9
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14725.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct GfFont;
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
void RESEARCH_TOP_CreateFont(u32 a0)
{
    u8 s[4];
    ((struct Obj14725 *)(((u8*)a0)))->f8 = (u32)GF_FONT_Create(23, 0, 0, 0, (u32)(((struct Obj14725 *)(((u8*)a0)))->f4));
}

