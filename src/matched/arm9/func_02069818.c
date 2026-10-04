/*
 * function: func_02069818
 * address:  0x02069818
 * packet:   pkt_020694D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020680DC    0x020680DC  arm
 *   func_0206958C    0x0206958C  arm
 *
 * The two trailing `signed char` parameters are ONE 2-byte struct passed by
 * value, not two separate char arguments. Spelled as two arguments the ABI
 * gives each its own word slot and the image's `ldrsb r2, [sp, #0x39]` /
 * `strb ip, [sp, #0xd]` become +0x3C and +0x10; the struct form packs them
 * adjacently and is what makes the file byte-correct. The same pair is
 * forwarded verbatim to func_0206958C, which therefore takes it the same
 * way.
 *
 * VERDICT: MATCH. Byte-correct -- 224 bytes, ZERO concrete mismatches, the
 * full extent -- and capped only for lack of an outside witness.
 *
 * BLOCKING EVIDENCE CLASS: none available for the two calls to 0x020680DC
 * at +0x0030 and +0x0068. `label` refuses it: 0x020680DC has exactly two
 * branch witnesses anywhere in the image (arm9 and every overlay), at
 * 0x02069848 and 0x02069880, and BOTH are the two `bl`s in this function,
 * so every witness is inside the compared range. There is no `matched`
 * manifest entry for 0x020680DC either (it is in another packet), and it
 * is ordinary compiled C, so neither `runtime` nor `veneer` applies.
 * `--suggest-split` was run and reports "the whole range as one file is
 * NOT viable / best partition: 0 piece(s), 1 function(s) left out": both
 * sites are calls from a single function section, so there is no cut that
 * leaves either one a witness outside a smaller range.
 *
 * The third site, the tail call to 0x0206958C at +0x00D4, IS resolved
 * (`label x3, e.g. 0206980C`). Unblocking this file therefore needs one
 * thing only: an EXACT manifest entry covering 0x020680DC, which would
 * give both sites the `matched` class. That address is outside
 * pkt_020694D8 and cannot be filed from here.
 *
 * The horizontal/vertical alignment pre-pass for the text renderer.
 * Depending on two bits of the flags word (the third stack argument) it
 * measures the string with func_020680DC and shifts the pen:
 *   bit 8  (0x100): right/bottom align -- back the pen off by the full
 *                   measured extent, `(limit - measured)`;
 *   bit 7  (0x080): centre align -- back it off by half, with the
 *                   +1/asr-1 rounding pair on BOTH operands, which is what
 *                   produces the four `add rN, rM, rM, lsr #31` / `asr #1`
 *                   instructions at 0x02069888..0x020698A4.
 * The pen delta is applied as `pen += extent * (-dy)` and
 * `pen += extent * dx` through the two `mla`s, then everything is
 * forwarded verbatim to func_0206958C.
 */

typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u32 unk00;
    void *f04;
    u32 unk08;
    void *f0C;
} Ctx;

typedef struct {
    signed char dx;
    signed char dy;
} Step;

struct NNSG2dFont;
extern int func_020680DC(const struct NNSG2dFont *pFont, int vSpace, const void *txt);
extern void func_0206958C(Ctx *ctx, s32 x, s32 y, s32 w,
                          u32 a4, u32 a5, u32 a6, Step st);

void func_02069818(Ctx *ctx, s32 x, s32 y, s32 w,
                   u32 a4, u32 a5, u32 flags, u32 s, Step st)
{
    s32 n;
    s32 d;

    if (flags & 0x100) {
        n = func_020680DC(ctx->f04, (int)ctx->f0C, (const void *)s);
        d = (s32)a4 - n;
        x = x + d * -st.dy;
        y = y + d * st.dx;
    } else if (flags & 0x80) {
        n = func_020680DC(ctx->f04, (int)ctx->f0C, (const void *)s);
        d = ((s32)a4 + 1) / 2 - (n + 1) / 2;
        x = x + d * -st.dy;
        y = y + d * st.dx;
    }
    func_0206958C(ctx, x, y, w, a5, flags, s, st);
}
