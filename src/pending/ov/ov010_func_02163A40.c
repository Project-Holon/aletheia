/*
 * function: func_02163A40
 * address:  0x02163A40
 * packet:   pkt_ov010_02163A40
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-05 (wave P13, lane B6, pengy share): 15 of 176 B differ (174 B
 * compiled, 2 B pad). Leaf, no calls. Tests whether two intervals overlap
 * on each axis (a[k]..a[k+2] against b[k]..b[k+2], k = 0 and 1, longer
 * interval first, then either end of the shorter inside it). Residue is
 * only the second axis: the original gives the d1/big0 web r4 and the
 * lo2/sm0 web r3 (d1 temp in r3, asrs into r4); mine swaps r3 and r4.
 * First axis is identical. Tried, none moved it: goto fail vs early
 * return (early return is 4 B bigger), int d with (s16) casts, separate
 * locals for the whole second axis, for d only, for lo/hi only, for
 * big/sm only (23 or 15 B), loads of all four halfwords before the abs
 * (81 B), declaration orders (d last 42 B, d first with big/sm 15 B),
 * inline helper with index k (180 B), && of two helper calls (182 B),
 * ternary abs (loses the double s16 truncation, 158 B), reversed
 * compare forms (!( ) with > and <: 15 B; sm in [big0,big1]: 27 B),
 * second axis as a return of the test (180 B), six per-function pragmas
 * (opt_lifetimes 155 B, the rest 15 B). Idioms read: an-abs-written-as-a
 * -ternary..., two-unsigned-range-booleans..., ldrsh-register-offset...,
 * a-narrowing-cast-loads-wide..., two-long-lived-values-in-each-others-
 * registers. Twin: none (no calls, no matched overlap test).
 */
typedef short s16;
int func_02163A40(s16 *a, s16 *b)
{
    s16 d1, d2, lo1, hi1, lo2, hi2, big0, big1, sm0, sm1;
    lo1 = a[0]; hi1 = a[2]; d1 = hi1 - lo1; if (d1 < 0) { d1 = -d1; }
    lo2 = b[0]; hi2 = b[2]; d2 = hi2 - lo2; if (d2 < 0) { d2 = -d2; }
    if (d1 > d2) { big0 = lo1; big1 = hi1; sm0 = lo2; sm1 = hi2; }
    else { big0 = lo2; big1 = hi2; sm0 = lo1; sm1 = hi1; }
    if (!((big0 <= sm0 && big1 >= sm0) || (big0 <= sm1 && big1 >= sm1))) goto fail;
    lo1 = a[1]; hi1 = a[3]; d1 = hi1 - lo1; if (d1 < 0) { d1 = -d1; }
    lo2 = b[1]; hi2 = b[3]; d2 = hi2 - lo2; if (d2 < 0) { d2 = -d2; }
    if (d1 > d2) { big0 = lo1; big1 = hi1; sm0 = lo2; sm1 = hi2; }
    else { big0 = lo2; big1 = hi2; sm0 = lo1; sm1 = hi1; }
    if (!((big0 <= sm0 && big1 >= sm0) || (big0 <= sm1 && big1 >= sm1))) goto fail;
    return 1;
fail:
    return 0;
}
