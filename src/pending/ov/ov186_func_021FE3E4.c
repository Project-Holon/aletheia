/*
 * function: func_021FE3E4
 * address: 0x021FE3E4
 * packet: pkt_ov186_021FE3E4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * note: 2026-10-05 (wave P19 lane 5): 26 of 96 bytes off, same size. The only
 *   shape difference: the original loads the shared radius ldrh [r5,#0x10]
 *   between the cos and sin ldrsh (021FE40C); we load it right after ldrh
 *   [r5,#0x12]. Tried this wave, all 26 unless noted: radius first in each
 *   product, radius last in each product, y before x (28), x+=cx before y
 *   (38), index local i=(a>>4)*2, cos/sin/radius locals in original load
 *   order (SIZE 100), radius int local after angle (39), radius u16 local (26),
 *   struct with named fields, const struct pointer, non-const table, and each
 *   of the six per-function pragmas (opt_common_subs off 37, others 26;
 *   scheduling off changes nothing, so the order comes from the front end
 *   and not the scheduler). Idioms read: const-source-pointer-pulls-field-
 *   loads, load-scheduled-above-unrelated-store, data-pair-load-hoisted,
 *   field-read-from-a-table-folds-offset, pool-word-order-list-scheduler-tie.
 *   Twin src/matched/ov/ov186_func_021FE2F8.c (same table, same x/y shape,
 *   radius computed by a division) is EXACT but its radius is a local
 *   computed earlier, so it gives no model for a plain field read.
 *   final push 2026-10-05 G6L8: 15 of 96 bytes off (was 26), same size. Each
 *   field store is written right after its own product (x chain, store
 *   f8, y chain, store f12) with separate sum locals; this puts the radius
 *   ldrh between the two table ldrsh exactly as in the original (bytes 0x00
 *   to 0x2E exact). Residue: our tail shifts x before y and keeps x in r7
 *   (extra push r3/r7 and pop); the original shifts y first and needs no r7.
 *   Tried without effect on the tail: x/y/nx/ny declaration order, unsigned
 *   short angle, index local, __restrict on p or out (15), six pragmas
 *   (opt_propagation, opt_common_subs, opt_dead_assignments off 38 to 42,
 *   others 15), non-const table 27, struct fields 56, field rereads for the
 *   out stores 31, one-statement sums 36 to 56, a local reused for both u16
 *   reads or the radius in y (radius hoisted over the call, 30 to 39).
 *   Matched-assembly search (ldrsh, ldrh, ldrsh, muls, muls) hits only this
 *   function. Idioms read: of-two-equal-temps-the-later-born-one-gets-the-
 *   lower-register, opt-propagation-off-with-named-locals-pins-argument-
 *   constants-against-stack-stores (opt_propagation off made it worse: 54).
 * symbols:
 *   d_020A1B38 0x020A1B38 data a2
 */
extern const short d_020A1B38[];
int func_021FE3E4(char *p, int *out, int step)
{
    int angle, x, y, nx, ny;
    angle = (unsigned short)(*(unsigned short *)(p + 0x12) + 0xFFFF * step / *(int *)(p + 0x14));
    x = (d_020A1B38[(angle >> 4) * 2 + 1] * *(unsigned short *)(p + 0x10)) >> 12;
    nx = x + *(int *)p;
    *(int *)(p + 8) = nx;
    y = (d_020A1B38[(angle >> 4) * 2] * *(unsigned short *)(p + 0x10)) >> 12;
    ny = y + *(int *)(p + 4);
    *(int *)(p + 12) = ny;
    if (out) { out[0] = nx; out[1] = ny; }
    return step == *(int *)(p + 0x14);
}
