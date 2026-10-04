/*
 * function: func_02159494
 * address:  0x02159494
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call that supplies the second argument 0x11.
 *
 * symbols:
 *   func_021593A8  0x021593A8  arm
 */

extern void func_021593A8(char *soc, unsigned char flag);

void func_02159494(int a)
{
    func_021593A8((char *)a, 0x11);
}

