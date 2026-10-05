/*
 * function: func_021B01FC
 * address: 0x021B01FC
 * packet: pkt_ov013_021B01FC
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: DIFF
 * 2-bit ADPCM encoder (twin of the decoder func_021AFFE4): n/4 groups of four
 * s16 samples to one byte, low pair first.
 * 2026-10-05 (wave P3 R6): DIFF, 576 B compiled (size, push list, frame and 2-literal
 * pool match; 323 B differ). Draft of the 4-bit-twin shape: u8 helper, accumulator byte
 * `a |= code << 2k`, loop test `i < n / 4`. Residue: register colours (image: step table r5,
 * index table ip, -32768 r4, 32767 lr; ours r4, r2, lr, ip) and pool word order (image
 * 3A1C first, ours 3A00 first; same residue as the 3-bit encoder func_021AFABC).
 * Tries (16 compiles): four u8 locals then one OR (580 B, frame 0xc); int helper return
 * (564 B); declaration order of step/idx; diff before step load; inner j<4 loop (not
 * unrolled, 260 B, but flips the pool order to 3A1C first); *src++ walk (250 B differ,
 * but the image indexes src with offsets and adds 8 once); six per-function pragmas
 * (no gain). Idioms checked: a-pool-word-order-residue-is-a-list-scheduler-tie.md
 * (matches the diagnosis, no source lever found).
 * 2026-10-05 (wave P3 R6b): DIFF, still 576 B, 323 B differ (about 16 compiles, none closes).
 * Residue is only the preheader load order and the colours that follow it (image: step
 * table r5, index table ip, -32768 r4, 32767 lr; ours index r2, step r4, lr, ip). Tried:
 * macro ENCODE with a { } block (572 B, 463 differ, pool order unchanged); four hand-written
 * bodies with shared function-level locals (564 B, 382, same order); table pointers as locals
 * at function top (pool order flips to step first, but the loads move above the zero test,
 * 402); table pointers as locals inside the loop or helper (step first or not, but spills,
 * 556 to 565); s16 sample parameter (same 323); non-inlined helper (not inlined, 140 B);
 * index update before the predictor update (430); stores in decoder order index then pred
 * (321); sample pairs through a nested pair helper (596, 521); a = 0 then a |= (584, 483).
 * Measured: with 1 sample body per iteration the index table loads first, with 2 bodies the
 * step table loads first, with 4 bodies the index table again, so the order is not source
 * statement order. The EXACT decoder twin 021AFFE4 also has index table before step table
 * in its preheader, so the image encoder differs by something in IR creation order that no
 * human-plausible spelling reached. No stand-in used. Idioms checked:
 * a-pool-word-order-residue-is-a-list-scheduler-tie.md (diagnosis fits, no lever);
 * inline-functions-allocate-differently-from-macros.md (macro 463 B, worse);
 * two-live-pool-global-bases-swap-ip-and-lr.md (first-use order; step is already first in
 * source, no change); a-table-load-hoisted-past-the-loop-guard-names-a-const-extern-table.md
 * (tables already const, loads already in the preheader); a-hoisted-array-base-is-a-named-local-in-a-guarded-do-while.md
 * (named base locals: spills); a-register-carried-index-means-the-arms-were-spelled-out.md
 * (n/a, no register-carried index in the image).
 * symbols:
 *   d_021B3A00 0x021B3A00 data ov013 a1
 *   d_021B3A1C 0x021B3A1C data ov013 a2
 */
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned int u32;
typedef struct AdpcmState {
    s16 pred;
    u8 index;
} AdpcmState;
extern const s8 d_021B3A00[4];
extern const s16 d_021B3A1C[89];
static inline u8 Adpcm2EncodeSample(AdpcmState *st, int sample)
{
    int pred;
    int idx;
    int step;
    int diff;
    int code;
    int delta;
    idx = st->index;
    pred = st->pred;
    diff = sample - pred;
    step = d_021B3A1C[idx];
    if (diff < 0) {
        code = 2;
        diff = -diff;
    } else {
        code = 0;
    }
    if (diff >= step) {
        code |= 1;
    }
    delta = step;
    if (!(code & 1)) delta = 0;
    if (code & 2) delta = -delta;
    pred += delta;
    if (pred < -32768) pred = -32768;
    if (pred > 32767) pred = 32767;
    idx += d_021B3A00[code];
    if (idx < 0) idx = 0;
    else if (idx > 88) idx = 88;
    st->pred = (s16)pred;
    st->index = idx;
    return code;
}
void func_021B01FC(u8 *dst, const s16 *src, u32 n, AdpcmState *st)
{
    u32 i;
    u8 a;
    for (i = 0; i < n / 4; i++) {
        a = Adpcm2EncodeSample(st, src[0]);
        a |= Adpcm2EncodeSample(st, src[1]) << 2;
        a |= Adpcm2EncodeSample(st, src[2]) << 4;
        a |= Adpcm2EncodeSample(st, src[3]) << 6;
        *dst++ = a;
        src += 4;
    }
}
