/*
 * function: func_02176554
 * address:  0x02176554
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Prepares the block 0x554 bytes into the module block.
 *
 * symbols:

 */

extern int func_02175F3C(void);
extern int func_02176580(const int *p);

int func_02176554(void)
{
    return func_02176580((const int *)(func_02175F3C() + 0x554));
}

