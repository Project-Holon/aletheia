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
 * symbols:
 *   d_020A1B38 0x020A1B38 data a2
 */
extern const short d_020A1B38[];
int func_021FE3E4(char *p, int *out, int step)
{
    int angle, x, y;
    angle = (unsigned short)(*(unsigned short *)(p + 0x12) + 0xFFFF * step / *(int *)(p + 0x14));
    x = (d_020A1B38[(angle >> 4) * 2 + 1] * *(unsigned short *)(p + 0x10)) >> 12;
    y = (d_020A1B38[(angle >> 4) * 2] * *(unsigned short *)(p + 0x10)) >> 12;
    x += *(int *)p;
    y += *(int *)(p + 4);
    *(int *)(p + 8) = x;
    *(int *)(p + 12) = y;
    if (out) { out[0] = x; out[1] = y; }
    return step == *(int *)(p + 0x14);
}
