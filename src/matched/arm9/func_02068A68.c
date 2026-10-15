/*
 * function: NNSi_G2dSurfaceFillTiled
 * address:  0x02068A68
 * packet:   pkt_02068808
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MIi_CpuClearFast    0x02082AC0  arm
 *
 * Row-by-row twin of NNSi_G2dSurfaceFill: the same pixel expansion, then one
 * MIi_CpuClearFast (MIi_CpuClearFast) per row of w * tile-size bytes, stepping
 * the destination by stride * tile-size.  The row count is re-read from +0x08
 * each iteration (the call may alias it) and compared signed.
 *
 * Two levers: the `| (t << 16)` step is written in BOTH arms (see
 * NNSi_G2dSurfaceFill), and `dst = s->base` is assigned AFTER the two products,
 * immediately before the loop.  Initialising dst in its declaration gives the
 * same bytes with dst in r5 instead of sb (24 bytes out); the late assignment
 * is what makes it the last value the allocator colours.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Surface {
    char *base;   /* +0x00 */
    int   w;      /* +0x04 */
    int   h;      /* +0x08 */
    u8    bpp;    /* +0x0C  4 or 8 */
    int   stride; /* +0x10 */
};

extern void MIi_CpuClearFast(u32 data, void *dst, int size);

void NNSi_G2dSurfaceFillTiled(struct Surface *s, u32 arg)
{
    int i, n, adv, tsz;
    int bpp = s->bpp;
    char *dst;
    u32 t;

    if (bpp == 4) {
        t = arg | (arg << 4);
        t = t | (t << 8);
        arg = t | (t << 16);
    } else {
        t = arg | (arg << 8);
        arg = t | (t << 16);
    }
    tsz = (bpp << 6) / 8;
    adv = tsz * s->stride;
    n = tsz * s->w;
    dst = s->base;
    for (i = 0; i < s->h; i++) {
        MIi_CpuClearFast(arg, dst, n);
        dst += adv;
    }
}
