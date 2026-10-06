/*
 * function: func_02185F10
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
 *   func_0203F684  0x0203F684  arm
 *   GX_LoadOBJPltt  0x0207E51C  arm
 */

typedef unsigned short u16;
typedef int s32;

typedef signed short   s16;
extern short func_0203F684(unsigned short x);
extern void GX_LoadOBJPltt(void *src, unsigned long offset, unsigned long size);

void func_02185F10(u16 *p)
{
    u16 col;

    *p += 20;
    if (*p > 360)
        *p = 0;
    col = (u16)((((func_0203F684(*p) * 10) / 0x1000) + 15) << 5 | 0x1d);
    GX_LoadOBJPltt(&col, 0x18, 2);
}
