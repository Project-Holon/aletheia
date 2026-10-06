/*
 * file:     unit_02067FE4_p05.c
 * unit:     yes
 * function: func_02068A18, func_02068A68
 * address:  0x02068A18
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082AC0    0x02082AC0  arm
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

extern void func_02082AC0(u32 data, void *dst, int size);


/*
 * Clear a linear surface to one pixel value: expand the value to a full word
 * (4bpp doubles the nibble, then the byte; 8bpp doubles the byte; both then
 * double the halfword) and hand w * h * bytes-per-pixel-row-unit to
 * func_02082AC0 (MIi_CpuClearFast(data, dest, size) in the SDK map).
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
void func_02068A18(struct Surface *s, u32 arg)
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
    func_02082AC0(arg, s->base, n * ((bpp << 6) / 8));
}


/*
 * Row-by-row twin of func_02068A18: the same pixel expansion, then one
 * func_02082AC0 (MIi_CpuClearFast) per row of w * tile-size bytes, stepping
 * the destination by stride * tile-size.  The row count is re-read from +0x08
 * each iteration (the call may alias it) and compared signed.
 *
 * Two levers: the `| (t << 16)` step is written in BOTH arms (see
 * func_02068A18), and `dst = s->base` is assigned AFTER the two products,
 * immediately before the loop.  Initialising dst in its declaration gives the
 * same bytes with dst in r5 instead of sb (24 bytes out); the late assignment
 * is what makes it the last value the allocator colours.
 */
void func_02068A68(struct Surface *s, u32 arg)
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
        func_02082AC0(arg, dst, n);
        dst += adv;
    }
}
