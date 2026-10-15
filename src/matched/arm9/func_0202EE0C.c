/*
 * function: COMM_HISTORY_ScaleSpan
 * address:  0x0202EE0C
 * packet:   pkt_0202EE0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A scaled-span helper: the span (d - c - e) is raised eight bits, scaled by
 * the rate b, divided by the total a and shifted back down; the quotient
 * joins c and half of e.
 *
 * The divide is the UNSIGNED runtime entry at 0x0209C2B0 (which
 * layout/runtime_arm9.txt names `_div_by_zero_check`, but the code there is
 * the unsigned divide entry itself; `signed / signed` emits 0x0209C0A4
 * instead).  Declared here under the front end's own name, `_u32_div_f`.
 *
 * Two spellings are load-bearing, both found by tools/permuter.py
 * (mutations `temp` then `commute(+)`, hill, budget 800):
 *   - the quotient must be bound to its own local.  Written inline, the
 *     quotient stays live in r0 and the re-read of `e` is scheduled into r1
 *     BEFORE the shift, which is the four-instruction residue the earlier
 *     note recorded (docs/notes/pkt_0202EE0C.c.txt).
 *   - the sum must associate as `(c + tmp) + (e >> 1)`.  With
 *     `(tmp + c) + (e >> 1)` the two `adds` land on the other operand order.
 * Together they put the quotient's high half in r2 and re-read `e` into r0,
 * which is exactly the original's tail.
 *
 * symbols:
 *   _u32_div_f  0x0209C2B0  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/COMM_HISTORY_ScaleSpan.c \
 *       --func COMM_HISTORY_ScaleSpan --addr 0x0202EE0C --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern u32 _u32_div_f(u32 n, u32 d);

u32 COMM_HISTORY_ScaleSpan(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    u32 t = ((d - c) - e) << 8;
    u32 tmp = _u32_div_f(t * b, a) >> 8;

    return (c + tmp) + (e >> 1);
}
