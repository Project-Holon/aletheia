/*
 * function: ISS_3DS_SYS_StartSource
 * address:  0x0202B920
 * packet:   pkt_0202B920
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled arm9 leaf, filed as a relocation witness for ov021
 * func_021C4D14 (wave A1, lane 13).
 *
 * symbols:
 *   ISS_3DS_SYS_StartSourceImpl  0x0202BA60  thumb
 */

/* All four argument registers are live, so r3 cannot carry a pool tail
 * call: push {r3, lr}; bl; pop {r3, pc}. */
extern void ISS_3DS_SYS_StartSourceImpl(void *m, int i, int a, int b);

void ISS_3DS_SYS_StartSource(void *m, int i, int a, int b)
{
    ISS_3DS_SYS_StartSourceImpl(m, i, a, b);
}
