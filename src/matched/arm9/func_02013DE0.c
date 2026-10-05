/*
 * function: func_02013DE0
 * address:  0x02013DE0
 * packet:   pkt_02013DE0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02013B10  0x02013B10  thumb
 *   d_0209DFEC     0x0209DFEC  data  a4
 *
 * Unlabelled Thumb leaf after func_02013DD0: a tail call
 * to func_02013B10 with a fixed table and count. Filed as the witness for
 * the ov020 caller func_021862A8 (wave D4 lane 12).
 */

extern const int d_0209DFEC[];
int func_02013B10(int a0, const int *a1, int a2);

int func_02013DE0(int a0)
{
    return func_02013B10(a0, d_0209DFEC, 9);
}
