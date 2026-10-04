/*
 * function: func_02162A6C
 * address:  0x02162A6C
 * packet:   pkt_ov010_02162A6C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (tail-call thunk, a .word run in the ov010 listing) to
 * func_02162ECC.  Blocker of ov021 func_021AFDAC.
 *
 * symbols:
 *   func_02162ECC  0x02162ECC  thumb  ov010
 */

extern void func_02162ECC(const char *p, int *out);

void func_02162A6C(int a, int b)
{
    func_02162ECC((const char *)a, (int *)b);
}
