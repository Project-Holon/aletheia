/*
 * function: func_021AFABC
 * address: 0x021AFABC
 * packet: pkt_ov013_021AFABC
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: DIFF
 * 3-bit ADPCM encoder (twin of the decoder func_021AF628): n/8 groups of eight
 * s16 samples to three bytes each, high bits first. Predictor and step index
 * are carried in *st.
 * 2026-10-05 (wave D9r P3): DIFF, 1312 B compiled (size and prologue match, 1147 B
 * differ). Semantics and structure are right (u8 dst stores alias st->index, so the
 * index reloads after each dst store as in the image). Residue: register colours and
 * spills. The image keeps n and i in two stack slots, c2 and c5 in two more (frame
 * 0x10); this build uses 0x18. Calls evaluate the assignment operand first, so
 * (c2 = E2) inside the OR expression puts sample 2 before samples 0 and 1.
 * Tries (about 20 compiles): int vs u8 helper return; all codes as u8 locals then one
 * packing expression (hoists mov fp,#4 like the image but spills 0x28); interleaved
 * dst stores with u8 accumulators (matches order, but mov #4 is not hoisted, frame
 * 0x14); single nested-call OR expressions (this file: hoists 4, 1312 B); ternary and
 * if-first sign forms; six per-function pragmas (no change, not allowed anyway).
 * 2026-10-05 (wave D9r P3b): DIFF, 1320 B compiled (size, frame 0x10 and push list now
 * match; 627 B differ, was 1147). The lever: the loop test as `i < n / 8` (as the decoder
 * has `i < n / 3`), not `n >>= 3`; then n and i spill to [sp,#8],[sp,#0xc] and mov fp,#4
 * hoists as in the image. Body: u8 locals c0..c7 in order, byte accumulators a,b,c, dst
 * stores after samples 2, 5, 7. Residue: register colours (image: step table r4, index
 * table r2, -32768 lr, 32767 ip; ours r2, r4, r4, lr) and the pool word order (image
 * 3A1C first, ours 3A04 first), and the caller's `and #0xff; lsl #5` of a code sits before
 * the state stores in the image but after the next sample's loads here. Six per-function
 * pragmas on this form: opt_lifetimes off 637 B (no better than 627 B), others worse or
 * same. No effect: extern order, helper return int, pred/idx load order, ret local before
 * stores, table pointers as params (worse, 686 B). 23 compiles.
 * Idioms checked: the-block-constant-in-a-callee-saved-register-follows-the-order-of-the-stores.md
 * (no fit, one constant); a-constant-loaded-at-entry-...-declaration-initialiser.md (n/a).
 * 2026-10-05 (wave D9r P3c): DIFF, 1320 B, 627 B differ (unchanged, 15 compiles). Real
 * residue: the two hoisted table loads. The registers are the same as the image (step
 * table r4, index table r2); only the preheader load order differs (image: step table
 * first, pool word 0x520 = 0x021B3A1C; ours: index table first). That order then moves
 * idx/pred/step to r7/r8/r6 (image r6/r7/r8) and the code shift and and-0xff of a sample
 * sits after the state stores here (before them in the image). New tries, no effect on
 * pool order: tables renamed so each sorts first or last; table array sizes [] and [200];
 * char instead of s8; extern order swapped; index-table statement moved before the delta
 * code; calls as `a = E(0) << 5; a |= E(1) << 2;` with only c2 and c5 as locals (same
 * bytes); table pointers as locals assigned at function top and passed to the helper
 * (681 B); stores in decoder order index then pred (628 B); decoder-style sign-split
 * clamp (1420 B, size changes). The listing clamp is two sequential ifs, so the decoder
 * spelling does not apply. Pool order seems fixed by LICM encounter order, not by names,
 * sizes or declaration order; the only source lever left is making the index table the
 * first table touched in the loop body, which has no human form.
 * Idioms checked: a-pool-word-order-residue-is-a-list-scheduler-tie.md (matches the
 * diagnosis, no source lever); a-constant-pair-pools-the-one-used-first-...md (n/a, two
 * tables); two-live-pool-global-bases-swap-ip-and-lr.md (store order of first use: not
 * applicable, tables are loop-hoisted); a-clamp-with-both-stores-in-each-arm-...md (n/a);
 * a-data-pair-load-hoisted-into-locals-before-a-clamp.md (n/a).
 * final push 2026-10-05 G10L3: DIFF, 1320 B, 383 B differ (was 627; 40 compiles). Applied the
 * closed sibling 021B01FC forms: separate np local, non-const src read as *src++ in the
 * call arguments (no src += 8), no named table-value temp for the delta. A named step
 * local assigned first (before diff) is still needed: the whole first sample then matches
 * the image byte for byte (idx r6, pred r7, step r8, diff sb); without the step local the
 * pool order is right (3A1C first) but colours are off (691 B). Step read as
 * step = d_021B3A1C[st->index] before idx and pred gives 383 (plain idx form 422). Residue:
 * (1) pool order of the two hoisted table loads (image step table first; any step local
 * puts the index table first; step assigned after the sign diamond gives the right order
 * but wrong colours, 680 B); (2) from the second sample on, the image schedules
 * strh, the a-byte mask, strb, the idx mask after the stores and loads pred and sample before the
 * step load (subs before lsl); ours hoists the idx mask and the step load above the pred
 * and sample loads, and the idx lands in r5 where the image uses sl. No effect: pred/idx
 * read order, int/u32/u8/s16 spellings of sample, pred, code, return, accumulators
 * (int or u32 accumulators 979 B), c0..c7 locals vs call-argument form, one accumulator
 * reused, *dst++, one big OR expression (972 B), accumulate-then-store (1214 B), stores
 * index then pred, idx clamp as two ifs (997 B), pred += delta (390 B), extern order,
 * pragmas opt_lifetimes and opt_strength_reduction (same), opt_propagation and
 * opt_common_subs (worse, 1144 and 1163 B).
 * Idioms checked: of-two-equal-temps-the-later-born-one-gets-the-lower-register.md,
 * opt-propagation-off-with-named-locals-pins-argument-constants-against-stack-stores.md
 * (propagation off is much worse here). Matched hits: 021B01FC (source of the forms),
 * 021AFFE4, 021AF340, 021AF628 read.
 * symbols:
 *   d_021B3A04 0x021B3A04 data ov013 a1
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
extern const s8 d_021B3A04[8];
extern const s16 d_021B3A1C[89];
static inline u8 Adpcm3EncodeSample(AdpcmState *st, int sample)
{
    int pred;
    int idx;
    int diff;
    int code;
    int delta;
    int np;
    int step;
    step = d_021B3A1C[st->index];
    idx = st->index;
    pred = st->pred;
    diff = sample - pred;
    if (diff < 0) {
        code = 4;
        diff = -diff;
    } else {
        code = 0;
    }
    if (diff >= step) {
        code |= 2;
        diff -= step;
    }
    if (diff >= (step >> 1)) {
        code |= 1;
    }
    delta = step >> 2;
    if (code & 2) delta += step;
    if (code & 1) delta += step >> 1;
    if (code & 4) delta = -delta;
    np = pred + delta;
    if (np < -32768) np = -32768;
    if (np > 32767) np = 32767;
    idx += d_021B3A04[code];
    if (idx < 0) idx = 0;
    else if (idx > 88) idx = 88;
    st->pred = (s16)np;
    st->index = idx;
    return code;
}
void func_021AFABC(u8 *dst, s16 *src, u32 n, AdpcmState *st)
{
    u32 i;
    u8 a, b, c;
    u8 c2, c5;
    for (i = 0; i < n / 8; i++) {
        a = Adpcm3EncodeSample(st, *src++) << 5;
        a |= Adpcm3EncodeSample(st, *src++) << 2;
        c2 = Adpcm3EncodeSample(st, *src++);
        *dst++ = a | (c2 >> 1);
        b = Adpcm3EncodeSample(st, *src++) << 4;
        b |= Adpcm3EncodeSample(st, *src++) << 1;
        c5 = Adpcm3EncodeSample(st, *src++);
        *dst++ = b | (c2 << 7) | (c5 >> 2);
        c = Adpcm3EncodeSample(st, *src++) << 3;
        c |= Adpcm3EncodeSample(st, *src++);
        *dst++ = c | (c5 << 6);
    }
}
