/*
 * function: func_021D38DC
 * address:  0x021D38DC
 * packet:   pkt_021D38DC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D38DC 0x021D38DC arm
 *
 * Tail-call func_02090B18 with two views of the block behind 0x021DE660.
 * Addresses are Black-image addresses.
 */

extern void func_02090B18(void *, void *, int);

void func_021D38DC(int a)
{
    int *g = (int *)0x021DE660;
    char *p = (char *)g[1];

    func_02090B18(p + 0x13e0, p + 0x1c00, a);
}
