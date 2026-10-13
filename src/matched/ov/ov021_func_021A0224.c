/*
 * function: FIELD_FOG_FADE_InitEx
 * address:  0x021A0224
 * packet:   pkt_ov021_021A0224
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_FOG_FadeStart  0x021A0260  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void FIELD_FOG_FadeStart(u8 *p, u32 a, u32 b, u16 c, u16 d, u16 e);

void FIELD_FOG_FADE_InitEx(u8 *p, u32 a, u32 b, u32 c, u32 d, u16 e)
{
    FIELD_FOG_FadeStart(p + 0x2c, a, b, c, d, e);
}
