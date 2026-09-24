/*
 * function: func_0219A034
 * address:  0x0219A034
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Marks the record spent and tail calls on its second word.
 *
 * symbols:
 *   func_02199FB4  0x02199FB4  arm  ov009
 */

extern void func_02199FB4(int v);

void func_0219A034(int *p)
{
    if (p[0] == -1) {
        p[6] = -1;
    }

    func_02199FB4(p[1]);
}

