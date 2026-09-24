/*
 * function: func_021C1D24
 * address:  0x021C1D24
 * packet:   pkt_021C1D0C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C1920 0x021C1920  thumb  ov208
 *
 * Region-qualified name: src/matched/func_021C1D24.c is ov217's function at the
 * same load address; this is ov208's.
 *
 * Thin forwarder: hands its first three arguments straight through to
 * func_021C1920 with a literal fourth argument of 4.
 */

extern void func_021C1920(void *, int, int, int);

void func_021C1D24(void *a, int b, int c)
{
    func_021C1920(a, b, c, 4);
}
