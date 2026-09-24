/*
 * function: func_0216870C
 * address:  0x0216870C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call with the last argument moved to the fourth slot.
 *
 * symbols:
 *   func_02168724  0x02168724  arm  ov009
 */

extern void func_02168724(int a, int b, int c, int d);

void func_0216870C(int a, int b)
{
    func_02168724(a, 0, 0, b);
}

