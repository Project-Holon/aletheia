/*
 * function: func_021AF494
 * address:  0x021AF494
 * packet:   pkt_ov013_021AF494
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * IMA ADPCM encoder: n s16 samples to n/2 bytes, first sample in the low
 * nibble, predictor and step index carried in *st. Index table (s8[16])
 * at 0x021B3A0C, step table (s16[89]) at 0x021B3A1C. Same tables and
 * state struct as the decoders func_021AF340 and func_021AF628.
 *
 * 2026-10-05 (wave P5 T10): size exact (404 B), prologue, loop and every
 * statement match. Residue is colour only: the halved count is in r5 here
 * and r8 in the image (image temps: code r5, idx r6, pred r7, step sb; ours
 * code r6, step r7, idx r8, pred sb). Declaration order of half/i/lo/hi, n /= 2,
 * u8 code, int return, and the six per-function pragmas were tried (best 226 B
 * differ; opt_propagation off 188 B but also changes code). The tail needs
 * lo | (u8)(hi << 4) to get the and/lsl/and; the late and on lo is still missing.
 *
 * 2026-10-05 final push G9L8: still DIFF, 107 B differ of 404 (was 226). Two real levers found:
 * (1) walk the source with `*src++` for both samples (not src[0], src[1], src += 2): 226 to 131;
 * (2) store pred before index in the helper (the image does strh then strb): 126; (3) declare the
 * helper locals step, pred, idx, diff, code, vp (vreg numbering follows declaration order): 107.
 * Now only half is wrong: the image colours it last (r8, the one register no temp uses), we colour
 * it second (r5), which shifts code/idx/pred/step down by one. Per mwcc Coloring.c, half must be
 * pushed on the simplify stack before the temps, i.e. one more neighbour on the temps or one fewer
 * on half; no source form found. Tried with no gain: macro ENCODE (203), half/i/lo/hi declaration
 * order, n /= 2 and n/2 in the loop test (133, half lands in r2), do-while with guard, opt_propagation
 * off (136), the other pragmas, int helper return, return dst, block-scoped lo/hi, for-init half,
 * u32 lo/hi (size 396), reverse helper order (200), diff-first order (220). 37 compiles.
 * No matched ARM twin: grep for `lsrs r8, r2, #1` and `lsrs rN, rM, #k` in asm/overlays finds only
 * Thumb forms elsewhere. Idioms read: of-two-equal-temps-the-later-born-one-gets-the-lower-register.md,
 * opt-propagation-off-with-named-locals-pins-argument-constants-against-stack-stores.md.
 *
 * 2026-10-05 final push G10L8: still DIFF, 68 B differ of 404 (was 107). Lever from the sibling
 * encoder ov013 021B01FC: a separate new-predictor local `np = pred + vp` with the clamps on np and
 * `st->pred = (s16)np`, plus a non-const `s16 *src` (107 to 68). The step local is kept here (the
 * image reads the table once, unlike 021B01FC). Residue is still only half's colour: image half r8,
 * ours r5 (everything else is the same shifted by one). 40 compiles, no gain below 68: half as int,
 * long, n >> 1, n /= 2, const half, `i < n/2` (half hoisted into r2), while/do-while/guard forms,
 * for(i=0,half=...), counter before bound, all 24-ish declaration orders of half/i/lo/hi (68 or 72),
 * single-expression and `b |=` forms, s16/int sample parameter, int helper return, a shared-local
 * macro (108+), each per-function pragma (lifetimes, common_subs, scheduling, peephole = 68;
 * propagation 105; dead_assignments 78; propagation/lifetimes with do-while 342+). The decoder
 * twins loop on n directly and the only other ARM `lsrs rN, rM, #1; mov r5, #0` hit, matched
 * func_0203F328, has no register pressure, so neither shows the form.
 *
 * symbols:
 *   d_021B3A0C     0x021B3A0C  data  ov013  a1
 *   d_021B3A1C     0x021B3A1C  data  ov013  a2
 */

typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned int u32;

typedef struct AdpcmState {
    s16 pred;
    u8 index;
} AdpcmState;

extern const s8 d_021B3A0C[16];
extern const s16 d_021B3A1C[89];

static inline u8 AdpcmEncodeSample(AdpcmState *st, int sample)
{
    int step;
    int pred;
    int idx;
    int diff;
    int code;
    int vp;
    int np;

    idx = st->index;
    pred = st->pred;
    step = d_021B3A1C[idx];
    diff = sample - pred;
    if (diff < 0) {
        code = 8;
        diff = -diff;
    } else {
        code = 0;
    }
    if (diff >= step) {
        code |= 4;
        diff -= step;
    }
    if (diff >= (step >> 1)) {
        code |= 2;
        diff -= step >> 1;
    }
    if (diff >= (step >> 2)) {
        code |= 1;
    }
    vp = step >> 3;
    if (code & 4) {
        vp += step;
    }
    if (code & 2) {
        vp += step >> 1;
    }
    if (code & 1) {
        vp += step >> 2;
    }
    if (code & 8) {
        vp = -vp;
    }
    np = pred + vp;
    if (np < -32768) {
        np = -32768;
    }
    if (np > 32767) {
        np = 32767;
    }
    idx += d_021B3A0C[code];
    if (idx < 0) {
        idx = 0;
    } else if (idx > 88) {
        idx = 88;
    }
    st->pred = (s16)np;
    st->index = idx;
    return code;
}

void func_021AF494(u8 *dst, s16 *src, u32 n, AdpcmState *st)
{
    u32 i;
    u32 half;
    u8 lo;
    u8 hi;

    half = n / 2;
    for (i = 0; i < half; i++) {
        lo = AdpcmEncodeSample(st, *src++);
        hi = AdpcmEncodeSample(st, *src++);
        *dst++ = lo | (u8)(hi << 4);
    }
}
