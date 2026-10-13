/*
 * function: FIELD_LIGHT_FADE_InitHold
 * address:  0x021A0C60
 * packet:   pkt_ov021_021A0C60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

void FIELD_LIGHT_FADE_InitHold(u16 *p, u16 a, u16 b)
{
    p[0] = 1;
    p[1] = a;
    p[3] = b;
    p[2] = 0xFFFF;
}
