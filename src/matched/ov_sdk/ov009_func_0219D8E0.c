/*
 * function: func_0219D8E0
 * address:  0x0219D8E0
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Prepares the two blocks inside the argument.
 *
 * symbols:
 *   func_0219D5B0  0x0219D5B0  arm  ov009
 */

extern void func_0219D5B0(int *p);

void func_0219D8E0(char *p)
{
    func_0219D5B0((int *)(p + 0x14));
    func_0219D5B0((int *)(p + 8));
}

