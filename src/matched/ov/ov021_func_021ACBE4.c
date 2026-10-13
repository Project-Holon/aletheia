/*
 * function: FLDEFF_NAMIPOKE_GetWakeScale
 * address:  0x021ACBE4
 * packet:   pkt_ov021_021ACBE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int FLDEFF_NAMIPOKE_GetWakeScale(int n)
{
    if (n > 0x40000)
        n = 0x40000;
    return n / 0xA3D * 0x28;
}
