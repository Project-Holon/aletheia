/*
 * function: func_0216D3A8
 * address:  0x0216D3A8
 * packet:   pkt_ov010_0216D3A8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (in a .word run): callback thunk that forwards its
 * second argument to func_0216D38C. Filed as the witness that
 * func_0216DF64's pointer to it needs.
 *
 * symbols:
 *   func_0216D38C  0x0216D38C  thumb  ov010
 */

typedef unsigned int u32;

extern void func_0216D38C(u32 a);

void func_0216D3A8(u32 a, u32 b)
{
    func_0216D38C(b);
}
