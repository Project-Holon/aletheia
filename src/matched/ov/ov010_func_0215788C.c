/*
 * function: func_0215788C
 * address:  0x0215788C
 * packet:   pkt_ov010_0215788C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call thunk hidden in a .word run; witness for the
 * function pointer taken in func_021578A0.
 *
 * symbols:
 *   func_021576C4  0x021576C4  thumb  ov010
 *   func_02157870  0x02157870  thumb  ov010
 */

extern void func_021576C4(void *, void (*)(void), int);
extern void func_02157870(void);

void func_0215788C(void *p)
{
    func_021576C4(p, func_02157870, 0x1DD);
}
