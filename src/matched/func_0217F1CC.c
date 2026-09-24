/*
 * function: func_0217F1CC
 * address:  0x0217F1CC
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Saves the word at +4, calls the helper and returns it.
 *
 * symbols:

 */

extern void func_0217EAE0(void);

int func_0217F1CC(int *p)
{
    int v = p[1];

    func_0217EAE0();

    return v;
}

