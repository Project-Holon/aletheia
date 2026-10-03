/*
 * function: func_021ECB60
 * address:  0x021ECB60
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EC060  0x021EC060  thumb  ov170
 *
 * Forward the byte at the pooled table offset.  The callee takes three
 * arguments, so the forwarded byte is argument 1 and the passing flag
 * stays in r2 untouched; that is what forces the sum into r3.
 */

extern void func_021EC060(char *p, unsigned i, int b);

void func_021ECB60(char *p, int i, int f)
{
    func_021EC060(p, *(unsigned char *)(p + i + 0x3DD2), f);
}
