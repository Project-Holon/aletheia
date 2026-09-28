/*
 * function: func_0215CF98
 * address:  0x0215CF98
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call on the word at +0xa4 of the object.
 *
 * symbols:
 *   func_0215CF14  0x0215CF14  arm
 */

extern void func_0215CF14(int v);

void func_0215CF98(const int *p)
{
    func_0215CF14(p[0x29]);
}

