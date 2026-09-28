/*
 * function: func_0215DE38
 * address:  0x0215DE38
 * packet:   pkt_0215DE38
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Forwards three of its four incoming argument registers to a callee whose
 * first parameter is the constant 4. The callee takes four arguments, so a
 * tail call is impossible (bx would spend an argument register on the
 * target), which is why the image keeps a frame and emits a direct bl.
 * The listing extent is two bytes long because of the trailing alignment
 * padding.
 *
 * symbols:
 *   func_021FC644  0x021FC644  thumb  ov132
 */

extern void func_021FC644(int, int, int, int);

void func_0215DE38(int a, int b, int c, int d)
{
    func_021FC644(4, b, c, d);
}
