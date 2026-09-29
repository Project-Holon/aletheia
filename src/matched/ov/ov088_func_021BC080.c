/*
 * function: func_021BC080
 * address:  0x021BC080
 * packet:   pkt_ov088_021BC080
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: extent runs long; the follower at 0x021BC0AC is an unlabelled leaf
 * (function_starts seed).
 *
 * symbols:
 *   func_0202208C  0x0202208C  thumb
 */

extern void func_0202208C(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);

int func_021BC080(char *p, int v)
{
    func_0202208C(0, 0, 0, 0, 6, 1, 0xb);
    *(int *)(p + 0x144) = v;
    return 2;
}
