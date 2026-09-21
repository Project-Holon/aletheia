/*
 * function: func_020696F4
 * address:  0x020696F4
 * packet:   pkt_020694D8
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02068150    0x02068150  arm
 *   func_0206958C    0x0206958C  arm
 *
 * The block-alignment pre-pass, the two-dimensional counterpart of
 * func_02069818's single-line one. It measures the whole multi-line extent
 * with func_02068150 into a two-word local, copies that pair into a second
 * local (the one the caller-visible {w,h} box keeps), and then backs the pen
 * off along the step vector according to two pairs of flag bits:
 *   0x10 centre vertically, 0x20 bottom-align (measured width, +0x18)
 *   0x02 centre horizontally, 0x04 right-align (box height, +0x24)
 * Everything is then forwarded verbatim to func_0206958C, the same Step
 * struct by value that func_02069818 forwards.
 *
 * Per-file compiler pin, the "kept branches" tell (docs/FRONTEND-PINS.md).
 * The image keeps `tst r4, #0x20` at 0x02069768 (`20 00 14 e3`) and
 * `beq 0x02069784` at 0x0206976C (`04 00 00 0a`) over the FIVE-instruction
 * bottom-align arm at 0x02069770..0x02069780 (two `ldrsb` of the step pair,
 * `rsb r2, r2, #0`, and the two `mla`). dsi/1.1p1 -O4,p predicates the whole
 * arm to `ldrsbne/rsbne/ldrsbne/mlane/mlane`, and having done so schedules
 * the head one slot differently (`ldr r3, [r8, #0xc]` split out of the
 * `ldmib r8, {r1, r2, r3}`): the same 292 bytes, 93 concrete bytes out, with
 * everything from 0x02069784 onward already byte-identical. Under the pin
 * the same C is 292 bytes, 0 mismatches.
 *
 * The three {w,h} pairs at sp+0x10, sp+0x18 and sp+0x20 are three distinct
 * stack objects: the out buffer func_02068150 fills and two copies of it,
 * only one of which is read again. Both copies must be `volatile` or 1.1p1
 * and 2.0 alike dead-store-eliminate them and the frame comes out 0x18.
 */

typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u32 unk00;
    void *f04;
    void *f08;
    void *f0C;
} Ctx;

typedef struct {
    signed char dx;
    signed char dy;
} Step;

typedef struct {
    s32 w;
    s32 h;
} Ext;

extern void func_02068150(Ext *out, void *a, void *b, void *c, u32 s);
extern void func_0206958C(Ctx *ctx, s32 x, s32 y, s32 w,
                          u32 a4, u32 a5, u32 a6, Step st);

void func_020696F4(Ctx *ctx, s32 x, s32 y, s32 w,
                   u32 flags, u32 s, Step st)
{
    volatile Ext box2;
    Ext e;
    volatile Ext box;
    s32 d;

    func_02068150(&e, ctx->f04, ctx->f08, ctx->f0C, s);
    box.w = e.w;
    box.h = e.h;
    box2.w = e.w;
    box2.h = e.h;

    if (flags & 0x10) {
        d = -(e.w + 1) / 2;
        x = x + d * st.dx;
        y = y + d * st.dy;
    } else if (flags & 0x20) {
        d = -e.w;
        x = x + d * st.dx;
        y = y + d * st.dy;
    }

    if (flags & 2) {
        d = -(box2.h + 1) / 2;
        x = x + d * -st.dy;
        y = y + d * st.dx;
    } else if (flags & 4) {
        d = -box2.h;
        x = x + d * -st.dy;
        y = y + d * st.dx;
    }

    func_0206958C(ctx, x, y, box2.w, w, flags, s, st);
}
