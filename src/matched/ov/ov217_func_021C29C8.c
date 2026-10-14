/*
 * function: PALETTE_ANIME_Create
 * address:  0x021C29C8
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
 *   PALETTE_ANIME_Alloc  0x021C2DA0  thumb  ov217
 *   PALETTE_ANIME_Clear  0x021C2DCC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 PALETTE_ANIME_Alloc(u32 a0);
extern void PALETTE_ANIME_Clear(char *p);
u32 PALETTE_ANIME_Create(u32 a0)
{
    u32 v1 = PALETTE_ANIME_Alloc(a0);
    PALETTE_ANIME_Clear((char *)v1);
    return v1;
}

