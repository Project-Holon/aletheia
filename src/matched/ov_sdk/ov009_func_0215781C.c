/*
 * function: func_0215781C
 * address:  0x0215781C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The halfword the three-argument call lands on, tested.
 *
 * symbols:
 *   func_02157700  0x02157700  arm  ov009
 */

extern unsigned long func_02157700(unsigned char *s, unsigned long len, unsigned long sum);
extern unsigned int func_02157808(unsigned int x);

int func_0215781C(int a, int b)
{
    return func_02157808((unsigned short)func_02157700((unsigned char *)a, b, 0));
}

