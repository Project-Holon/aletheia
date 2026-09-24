/*
 * function: func_0217601C
 * address:  0x0217601C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clears the block 0x50 bytes into the module block.
 *
 * symbols:

 */

extern char *func_02175F3C(void);
extern void func_02082BCC(void *p, int v, int n);

void func_0217601C(void)
{
    func_02082BCC(func_02175F3C() + 0x50, 0, 0x504);
}

