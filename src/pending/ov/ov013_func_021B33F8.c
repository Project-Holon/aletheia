/*
 * function: func_021B33F8
 * address:  0x021B33F8
 * packet:   pkt_ov013_021B33F8
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * note (2026-10-05, wave P4 lane S4, pengy share, approved for this function):
 *   Semantics recovered from the listing: a 6-tap FIR over the state at
 *   d_021B4C48 (ring index [2],[3] masked 0x7FF, coefficients [5..10], delay line
 *   [11..16]) that filters b[], leaves b[i] = a[i], sums squares into an s64, then
 *   divides by n/2 (DIVCNT mode 1), takes the hardware sqrt, and scales a[] by an
 *   attenuation shift kept in the halfword at state[0] (0 when 3*rms < 2*thr,
 *   4 when thr < rms, else +1 up to 4).
 *   Residue: 472 bytes against 524. The original keeps the s64 sum e at
 *   [sp+8..0xc], the ring index w at [sp], and a dead store of the delay value at
 *   [sp+4] (frame 0x10, no fp); every spelling here keeps e in fp and r4 instead
 *   and spills the coefficient c4 to [sp]. Same code with the same bytes (472) for:
 *   explicit tap statements, a rolled loop (444, wrong), delay chain in a temp,
 *   tap locals d0..d5 with d5 = d4, u64 e, opt_dead_assignments off (with and
 *   without a dead local), a u32 base local for the ring buffer, and an inline
 *   FIR-step helper. All taps up front as locals gives 564. Tried 14 compiles.
 *   Idea left: e, w and the dead word look like memory-resident locals (address
 *   taken by an inline helper with out parameters).
 *
 *
 * note (2026-10-05, wave P4 lane S4b, pengy share):
 *   Now 512 bytes against 524 (was 472). Two source changes found:
 *   (1) the ring write index is read once into a local (v = state[3]) and reused
 *   for the ring store and for state[3] = (v + 1) & 0x7FF; the original keeps it
 *   in r7 across the whole tap chain and never re-reads it. That alone puts e in
 *   [sp] memory (a spill) and removes fp.
 *   (2) the sqrt start is an inline helper CP_SetSqrt32(u32 param) called with
 *   reg_CP_DIV_RESULT_L as the argument, so the result load comes before the
 *   SQRTCNT store and the pool word is 0x040002A0 as in the original. The whole
 *   tail after the loop now matches except for register numbers.
 *   Residue: the original spills three webs (e at sp+8, w=state[2] at sp, the
 *   delay value d4 at sp+4, never reloaded; frame 0x10, no fp, state in ip, mask
 *   in lr, i in r8). Ours spills e plus one coefficient and keeps w in a register
 *   (frame 0xc plus an r3 pad). The original therefore has about three more live
 *   values in the tap chain than ours; none found.
 *   Tried (17 compiles, none better than 512): struct local for e/w/d5 (scalar
 *   replaced, same bytes), inline AddSq(&e) helper (inlined, same bytes), the six
 *   per-function pragmas on the 512 form (opt_lifetimes, opt_propagation,
 *   opt_common_subs, opt_dead_assignments, scheduling, peephole: all >= 508 and
 *   worse), declaration order of v/w (first, last), u32 v/w, pointer locals
 *   c = state + 5 and d = state + 11 (552, worse: pointers stay live).
 *
 * symbols:
 *   d_021B4C48  0x021B4C48  data  a4
 *   d_021B50CC  0x021B50CC  data  a2
 */

typedef short s16;
typedef int s32;
typedef unsigned short u16;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;

#define reg_CP_DIVCNT       (*(volatile u16 *)0x04000280)
#define reg_CP_DIV_NUMER    (*(u64 *)0x04000290)
#define reg_CP_DIV_DENOM    (*(u64 *)0x04000298)
#define reg_CP_DIV_RESULT_L (*(volatile u32 *)0x040002A0)
#define reg_CP_SQRTCNT      (*(volatile u16 *)0x040002B0)
#define reg_CP_SQRT_RESULT  (*(volatile u32 *)0x040002B4)
#define reg_CP_SQRT_PARAM   (*(u32 *)0x040002B8)

static inline void CP_SetSqrt32(u32 param)
{
    reg_CP_SQRTCNT = 0;
    reg_CP_SQRT_PARAM = param;
}

extern s32 d_021B4C48[];
extern s16 d_021B50CC[];

void func_021B33F8(s16 *a, s16 *b, u32 n, u32 thr)
{
    s64 e;
    u32 i;
    u32 rms;
    s32 acc;
    s32 w;
    s32 v;
    s32 r;
    s32 d0, d1, d2, d3, d4, d5;

    e = 0;
    n >>= 1;
    for (i = 0; i < n; i++) {
        v = d_021B4C48[3];
        d_021B50CC[v] = b[i];
        w = d_021B4C48[2];
        d_021B4C48[11] = d_021B50CC[w];
        d4 = d_021B4C48[15];
        d5 = d_021B4C48[16];
        acc = d4 * d_021B4C48[9] + d5 * d_021B4C48[10];
        d5 = d4;
        d_021B4C48[16] = d5;
        d3 = d_021B4C48[14];
        acc += d3 * d_021B4C48[8];
        d_021B4C48[15] = d3;
        d2 = d_021B4C48[13];
        acc += d2 * d_021B4C48[7];
        d_021B4C48[14] = d2;
        d1 = d_021B4C48[12];
        acc += d1 * d_021B4C48[6];
        d_021B4C48[13] = d1;
        d0 = d_021B4C48[11];
        acc += d0 * d_021B4C48[5];
        d_021B4C48[12] = d0;
        if (acc > 0x3FFF8000)
            acc = 0x3FFF8000;
        else if (acc < (s32)0xC0000000)
            acc = (s32)0xC0000000;
        d_021B4C48[3] = (v + 1) & (0x3FFF8000 >> 19);
        d_021B4C48[2] = (w + 1) & (0x3FFF8000 >> 19);
        b[i] = acc >> 15;
        r = b[i];
        b[i] = a[i];
        e += r * r;
    }
    reg_CP_DIVCNT = 1;
    reg_CP_DIV_NUMER = e;
    reg_CP_DIV_DENOM = n;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    CP_SetSqrt32(reg_CP_DIV_RESULT_L);
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    rms = reg_CP_SQRT_RESULT;
    if (rms * 3 < thr * 2) {
        *(s16 *)d_021B4C48 = 0;
        return;
    }
    if (thr < rms)
        *(s16 *)d_021B4C48 = 4;
    if (*(s16 *)d_021B4C48 < 4)
        *(s16 *)d_021B4C48 = *(s16 *)d_021B4C48 + 1;
    for (i = 0; i < n; i++)
        a[i] >>= *(s16 *)d_021B4C48;
}
