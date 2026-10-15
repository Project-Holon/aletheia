/*
 * function: NNSi_G2dSurfaceFill
 * address:  0x02068A18
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
 * Clear a linear surface to one pixel value: expand the value to a full word
 * (4bpp doubles the nibble, then the byte; 8bpp doubles the byte; both then
 * double the halfword) and hand w * h * bytes-per-pixel-row-unit to
 * MIi_CpuClearFast (MIi_CpuClearFast(data, dest, size) in the SDK map).
 *
 * THE LEVER that closed this row after five DIFF passes
 * (docs/notes/pkt_02068808.c.txt): the final `| (t << 16)` step is written
 * INSIDE BOTH ARMS, not after the if/else.  Written once after the join, the
 * two arms' shared `| (x << 8)` step is tail-merged (68 bytes) or the arms
 * write the parameter in place and the orrne is sunk (76 bytes).  With the
 * <<16 duplicated, the compiler tail-merges exactly that one step back out
 * and the arms stay predicated into a temporary (orreq/orreq/orrne r0) with
 * the result landing in the parameter's own register (orr r1, r0, r0, lsl
 * #16), which is the image.  The `n = w * h` partial product must be its own
 * statement.
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

void NNSi_G2dSurfaceFill(struct Surface *s, u32 arg)
{
    int bpp = s->bpp;
    u32 t;
    int n;

    if (bpp == 4) {
        t = arg | (arg << 4);
        t = t | (t << 8);
        arg = t | (t << 16);
    } else {
        t = arg | (arg << 8);
        arg = t | (t << 16);
    }
    n = s->w * s->h;
    MIi_CpuClearFast(arg, s->base, n * ((bpp << 6) / 8));
}
