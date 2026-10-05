/*
 * function: func_0202E80C
 * address:  0x0202E80C
 * packet:   pkt_0202E80C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     2026-10-05 wave P19 lane 6: tiny unlabelled leaf filed as the
 *           witness for the call in ov010 func_0216EB98 (moves word 0 of the
 *           block into word 2 and clears word 0).
 * symbols:
 */
typedef unsigned int u32;

void func_0202E80C(u32 *p)
{
    p[2] = p[0];
    p[0] = 0;
}
