/*
 * function: OEKAKI_AnimatePalette
 * address:  0x02185F10
 * packet:   pkt_ov023_02185F10
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GF_STANDARD_SinFromDegreesWrapped  0x0203F684  arm
 *   GX_LoadOBJPltt  0x0207E51C  arm
 */

typedef unsigned short u16;
typedef int s32;

typedef signed short   s16;
extern short GF_STANDARD_SinFromDegreesWrapped(unsigned short x);
extern void GX_LoadOBJPltt(void *src, unsigned long offset, unsigned long size);

void OEKAKI_AnimatePalette(u16 *p)
{
    u16 col;

    *p += 20;
    if (*p > 360)
        *p = 0;
    col = (u16)((((GF_STANDARD_SinFromDegreesWrapped(*p) * 10) / 0x1000) + 15) << 5 | 0x1d);
    GX_LoadOBJPltt(&col, 0x18, 2);
}
