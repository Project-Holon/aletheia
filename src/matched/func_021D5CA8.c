/*
 * function: func_021D5CA8
 * address:  0x021D5CA8
 * packet:   pkt_021D5CA8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D5CA8 0x021D5CA8 arm
 *
 * Tail-call func_021D5C48 with the argument scaled by 0x30 into the table at 0x021DE680 + 0x610.
 * Addresses are Black-image addresses.
 */

extern void func_021D5C48(void *);

void func_021D5CA8(int a)
{
    func_021D5C48((void *)(*(int *)0x021DE680 + 0x610 + a * 0x30));
}
