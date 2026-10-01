/*
 * function: func_02013DD0
 * address:  0x02013DD0
 * packet:   pkt_02013DD0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02013B10  0x02013B10  thumb
 *   d_0209DFC0     0x0209DFC0  data  a4
 *
 * Unlabelled Thumb leaf inside func_02013D9C's listing extent: a tail call
 * to func_02013B10 with a fixed table and count. Filed as the witness for
 * the ov021 and ov018 callers.
 */

extern const int d_0209DFC0[];
int func_02013B10(int a0, const int *a1, int a2);

int func_02013DD0(int a0)
{
    return func_02013B10(a0, d_0209DFC0, 4);
}
