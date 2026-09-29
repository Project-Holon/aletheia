/*
 * function: func_02162A64
 * address:  0x02162A64
 * packet:   pkt_ov010_02162A64
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (tail-call thunk, a .word run in the ov010 listing) to
 * func_02162CE8.  Blocker of ov061 func_021F388C.
 *
 * symbols:
 *   func_02162CE8  0x02162CE8  thumb  ov010
 */

typedef struct {
    int a;
    int b;
    int c;
} V3;

extern void func_02162CE8(const void *p, V3 *out);

void func_02162A64(const void *p, V3 *out)
{
    func_02162CE8(p, out);
}
