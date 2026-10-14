/*
 * function: PALETTE_ANIME_IsRunningImpl
 * address:  0x021C2D9C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter: word at +0x14.
 *
 * symbols:
 *   (none)

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 PALETTE_ANIME_IsRunningImpl(u32 *p);
u32 PALETTE_ANIME_IsRunningImpl(u32 *p)
{
    return p[5];
}

