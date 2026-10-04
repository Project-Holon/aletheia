/*
 * function: func_0206958C
 * address:  0x0206958C
 * packet:   pkt_020694D8
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02068030    0x02068030  arm
 *   func_020694D8    0x020694D8  arm
 *
 * The line loop of the text renderer, sitting between func_02069818 /
 * func_020696F4 (which pre-align the pen) and func_020694D8 (which draws one
 * line). Per line it optionally re-aligns the pen horizontally within the
 * measured line box -- bit 11 of the flags word right-aligns by the full
 * measured width, bit 10 centres by half -- then draws the line and steps the
 * pen down by one line height along the step normal.
 *
 * Per-file compiler pin, the "kept branches" tell in its CROSS-JUMP form
 * (docs/FRONTEND-PINS.md). The image writes the pen-delta tail out in BOTH
 * arms of the alignment dispatch: `mla r4, r0, sb, r4` / `mla r5, r0, r8, r5`
 * at 0x02069658/0x0206965C closed by `b 0x0206969C` (`0d 00 00 ea`) at
 * 0x02069660 for the bit-11 arm, and the byte-identical `mla r4, r0, sb, r4`
 * / `mla r5, r0, r8, r5` at 0x02069694/0x02069698 for the bit-10 arm.
 * dsi/1.1p1 -O4,p cross-jumps the two, branching the bit-11 arm straight
 * into the bit-10 arm's pair and dropping both instructions plus the join
 * branch: 352 bytes against the original's 360, 130 concrete bytes out with
 * everything before 0x020695F4 already identical. Under the pin the same C
 * is 360 bytes, 0 mismatches.
 *
 * One C lever needed under the pin: `px`/`py` must be declared BEFORE
 * `sx`/`sy`, which is what puts the per-line pen in r4/r5 and the running
 * line offset in r6/r7. Declared the other way round the same 360 bytes come
 * out with those four registers swapped, 21 concrete bytes out.
 */

typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    s32 f0C;
} Ctx;

typedef struct {
    signed char dx;
    signed char dy;
} Step;

typedef struct {
    u8 b00;
    signed char b01;
} Hdr;

struct NNSG2dFont;
extern int func_02068030(const struct NNSG2dFont *pFont, int hSpace, const void *txt, const void **pPos);
extern void func_020694D8(Ctx *ctx, s32 x, s32 y, s32 w2,
                          const void *cur, const void **slot, Step st);

void func_0206958C(Ctx *ctx, s32 x, s32 y, s32 w,
                   s32 w2, u32 flags, const void *s, Step st)
{
    const void *cur;
    s32 lead;
    s32 dx;
    s32 dy;
    s32 bit11;
    s32 bit10;
    s32 half;
    s32 px;
    s32 py;
    s32 sx;
    s32 sy;
    s32 n;

    lead = ctx->f0C + ((Hdr *)((void **)ctx->f04)[0])->b01;
    dx = lead * -st.dy;
    dy = lead * st.dx;

    cur = s;
    if (cur == 0) return;

    sx = 0;
    bit11 = flags & 0x800;
    half = (w + 1) / 2;
    bit10 = flags & 0x400;
    sy = 0;

    do {
        px = x + sx;
        py = y + sy;
        if (bit11 != 0) {
            n = w - func_02068030(ctx->f04, (int)ctx->f08, cur, 0);
            px = px + n * st.dx;
            py = py + n * st.dy;
        } else if (bit10 != 0) {
            n = half - (func_02068030(ctx->f04, (int)ctx->f08, cur, 0) + 1) / 2;
            px = px + n * st.dx;
            py = py + n * st.dy;
        }
        func_020694D8(ctx, px, py, w2, cur, &cur, st);
        sx = sx + dx;
        sy = sy + dy;
    } while (cur != 0);
}
