/*
 * function: func_020640DC
 * address:  0x020640DC
 * packet:   pkt_020640DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * The NNS G2D per-node SRT translate setter.  Four bytes short: the original
 * opens with a *predicated* early return (`bxne lr`) and leaves the guarded
 * block unpredicated, while this compiler if-converts the block
 * (`ldrheq`/`orreq`/`strheq`/`strheq`/`strheq`) and drops the `bxne lr`.
 *
 * The predication threshold was measured: a sixth instruction in the block
 * makes mwcc branch again, so the original's five-instruction block sits below
 * the threshold this front end uses.  Every spelling tried (early `return`,
 * `if (p->mode == 1) { ... }`, an explicit `goto done`, a hoisted mode read,
 * a spelled-out `p->dirty = (u16)(p->dirty | 8)`) predicates.
 *
 * `volatile` on the parameter is kept because it fixes a *second* difference:
 * without it the three stores are scheduled (dirty load, tx, ty, orr, dirty
 * store) instead of written in source order.  With it, the only residue is the
 * missing `bxne lr`.  See docs/notes/g2d_srt_setters.c.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020640DC.c \
 *       --func func_020640DC --addr 0x020640DC --arm --cc 1.1p1
 */

typedef unsigned short u16;
typedef signed short   s16;
typedef signed int     s32;
typedef unsigned int   u32;

struct Srt020640DC {
    u32 mode;       /* +0x00, 1 = SRT enabled */
    s32 scaleX;     /* +0x04 */
    s32 scaleY;     /* +0x08 */
    s16 tx;         /* +0x0C */
    s16 ty;         /* +0x0E */
    u16 rot;        /* +0x10 */
    u16 dirty;      /* +0x12: bit1 scale, bit2 rotation, bit3 translation */
};

void func_020640DC(volatile struct Srt020640DC *p, s16 x, s16 y)
{
    if (p->mode != 1) {
        return;
    }
    p->dirty |= 8;
    p->tx = x;
    p->ty = y;
}
