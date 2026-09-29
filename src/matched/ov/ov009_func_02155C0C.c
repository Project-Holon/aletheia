/*
 * function: func_02155C0C
 * address:  0x02155C0C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Stores slot 6 when the argument is zero and slot 0xe otherwise.
 *
 * symbols:
 *   func_02155374  0x02155374  thumb  ov009
 */

extern void func_02155374(int v);

void func_02155C0C(int a)
{
    if (a == 0) {
        func_02155374(6);
        return;
    }

    func_02155374(0xe);
}

