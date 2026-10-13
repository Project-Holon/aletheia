/*
 * function: FIELD_FOG_FadeGetSlope
 * address:  0x021A02A8
 * packet:   pkt_ov021_021A02A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct {
    u16 f0;
    u16 f2;
    u32 f4;
    int f8;
    u32 fc;
    int f10;
} Lerp;

u16 FIELD_FOG_FadeGetSlope(Lerp *s)
{
    int q = s->f10 * s->f0 / s->f2;
    return q + s->fc;
}
