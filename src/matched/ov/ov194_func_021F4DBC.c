/*
 * function: NAMEIN_GRAPHIC_LoadCharMember
 * address:  0x021F4DBC
 * packet:   pkt_021F4DBC
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

int NAMEIN_GRAPHIC_LoadCharMember(int a, int b)
{
    return ARC_UTIL_LoadMember(0x77, a + 5, 0, b);
}

