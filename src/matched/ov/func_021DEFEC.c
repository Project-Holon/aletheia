/*
 * function: func_021DEFEC
 * address:  0x021DEFEC
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DEF98  0x021DEF98  thumb  ov170
 *
 * Forward with the byte field at +0x14.
 */

extern void func_021DEF98(char *, int, int);

void func_021DEFEC(char *p, int b)
{
    func_021DEF98(p, *(unsigned char *)(p + 0x14), b);
}

