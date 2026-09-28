/*
 * function: func_02155C70
 * address:  0x02155C70
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears the eight bytes at +0x784 of the block the module pointer holds.
 *
 * symbols:
 *   g_021A8264  0x021A8264  data
 */

extern char *g_021A8264;
extern void func_02082BCC(void *p, int v, int n);

void func_02155C70(void)
{
    func_02082BCC(g_021A8264 + 0x784, 0, 8);
}

