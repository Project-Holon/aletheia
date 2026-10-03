/*
 * function: func_021ED588
 * address:  0x021ED588
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ED594  0x021ED594  thumb  ov170
 *
 * Forward with the byte field at +0x16.
 */

extern void func_021ED594(char *p, unsigned i);

void func_021ED588(char *p)
{
    func_021ED594(p, *(unsigned char *)(p + 0x16));
}

