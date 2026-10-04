/*
 * function: func_02070524
 * address:  0x02070524
 * packet:   pkt_02070360
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Scalar keyframe sampler for the animation track engine (the callee
 * func_02070730 uses for the two scale tracks and the two translation
 * tracks).  `flags` is the track descriptor word: bit 29 means the value is
 * inline (return `off` unchanged), bits 31:30 select the key stride
 * (full / half / quarter), bit 28 selects s16 keys over u32 keys, and bits
 * 15:0 are the key count.  A half-stride odd index averages the two
 * neighbouring keys; a quarter-stride index is either that average or the
 * 3:1 weighted average, depending on the low two bits.
 *
 * Per-file compiler pin, "kept branches" tell (docs/FRONTEND-PINS.md): under
 * the project default dsi/1.1p1 -O4,p this body is 4 bytes LONG, because
 * 1.1p1 keeps the `two:` block's u32 arm as a branch where the image
 * predicates it.  Under ../2.0/sp2 the same C is byte-exact.
 *
 * Three source levers, all measured, all needed (see
 * docs/notes/func_02070524.c.txt for the full history):
 *   1. the quad tail spelled as three statements (`v0 *= 3; v0 += v1;
 *      return v0 >> 2;`), not as the single expression `(v0*3 + v1) >> 2`,
 *      which normalises the accumulate into `add r0, r1, r0`;
 *   2. in the `two:` block the s16 (bit-28 set) arm is written FIRST and the
 *      u32 arm as the `else`.  Writing the u32 arm first emits the two
 *      trailing s16 address computations in the other order
 *      (`lsl` before `add`), which no respelling of that arm reaches;
 *   3. the u32 arm's pointer `w` is computed INSIDE that arm.  Hoisting it
 *      above the `if` (the shape the note had reached) emits the `add`
 *      unpredicated where the image has `addeq`.
 *
 * No relocation sites: the function is self-contained.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02070524.c \
 *       --func func_02070524 --addr 0x02070524 --cc ../2.0/sp2 --arm
 */
#include "../include/Obj16643.h"
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

s32 func_02070524(u32 *base, u32 flags, u32 off, u32 idx)
{
    u32 n;
    u32 i0;
    s32 v0, v1;
    s16 *h;
    u32 *w;

    if (flags & 0x20000000)
        return off;

    base = (u32 *)((int)base + off);

    if (flags & 0xc0000000) {
        n = flags & 0xffff;
        if (flags & 0x40000000) {
            if (idx & 1) {
                if (idx > n) {
                    idx = (n >> 1) + 1;
                    goto plain;
                }
                idx = idx >> 1;
                goto two;
            }
            idx = idx >> 1;
            goto plain;
        } else {
            u32 r = idx & 3;
            if (r != 0) {
                if (idx > n) { idx = r + (n >> 2); goto plain; }
                if (idx & 1) {
                    if (idx & 2) { idx = idx >> 2; i0 = idx + 1; }
                    else { i0 = idx >> 2; idx = i0 + 1; }
                    if (!(flags & 0x10000000)) {
                        v0 = base[i0];
                        v1 = base[idx];
                        goto quad;
                    }
                    h = (s16 *)base;
                    v0 = h[i0];
                    v1 = h[idx];
                quad:
                    v0 *= 3;
                    v0 += v1;
                    return v0 >> 2;
                }
                idx = idx >> 2;
                goto two;
            }
            idx = idx >> 2;
        }
    }

plain:
    if (!(flags & 0x10000000))
        return base[idx];
    return ((s16 *)base)[idx];

two:
    if (flags & 0x10000000) {
        s16 *g = (s16 *)base + idx;
        u32 o = idx << 1;
        v0 = *(s16 *)((char *)base + o);
        v1 = g[1];
    } else {
        w = base + idx;
        v0 = base[idx];
        v1 = ((struct Obj16643 *)w)->f4;
    }
    return (v0 + v1) >> 1;
}
