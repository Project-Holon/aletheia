/*
 * function: func_0217653C
 * address:  0x0217653C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clears the block 0x554 bytes into the module block.
 *
 * symbols:

 */

extern int func_02175F3C(void);
extern void func_0217656C(void *p);

void func_0217653C(void)
{
    func_0217656C((void *)(func_02175F3C() + 0x554));
}

