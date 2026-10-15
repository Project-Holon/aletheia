/*
 * function: NAMEIN_GRAPHIC_LoadArcMember
 * address:  0x021F4D20
 * packet:   pkt_021F4D20
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ARC_UTIL_LoadMember  0x0204A1BC  arm  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int ARC_UTIL_LoadMember(int a0, int a1, int a2, int a3);

int NAMEIN_GRAPHIC_LoadArcMember(u32 a, u32 b)
{
    return ARC_UTIL_LoadMember(0x77, a, 0, b);
}

