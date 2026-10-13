/*
 * function: TALKMSGWIN_GetBmpWin
 * address:  0x02194990
 * packet:   pkt_02194990
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

u32 TALKMSGWIN_GetBmpWin(u32 a, u32 b)
{
return *(u32 *)((u8 *)((a + (b * 100))) + 36);
}

