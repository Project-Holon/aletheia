/*
 * function: func_021F853C
 * address:  0x021F853C
 * packet:   pkt_ov094_021F853C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to func_021FF348 with the handle at 0x190 of the global work block.
 * Unlabelled; filed as a witness for the caller ov093 func_021EA354 (wave B3 lane 17).
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 *   func_021FF348  0x021FF348  thumb  ov094
 */
extern char *d_0220AF20;
extern int func_021FF348(void *, int);

int func_021F853C(int a)
{
    return func_021FF348(*(void **)(d_0220AF20 + 0x190), a);
}
