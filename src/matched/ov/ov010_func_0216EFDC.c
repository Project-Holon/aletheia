/*
 * function: func_0216EFDC
 * address:  0x0216EFDC
 * packet:   pkt_ov010_0216EFDC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     2026-10-05 wave P19 lane 6: tiny unlabelled tail-call leaf filed as
 *           the witness for the calls in ov010 func_0216EB98. Reads the info
 *           block at w[2] and tail-calls func_0216EFA8(info[0x8c / 4], info[0]).
 *
 * symbols:
 *   func_0216EFA8  0x0216EFA8  thumb  ov010
 */
extern int func_0216EFA8(int a, int b);

int func_0216EFDC(int *w)
{
    int *q = (int *)w[2];
    return func_0216EFA8(q[0x8c / 4], q[0]);
}
