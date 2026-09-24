/*
 * function: func_021ED2F4
 * address:  0x021ED2F4
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EC000  0x021EC000  thumb  ov170
 *
 * Loop 8 entries forwarding (i+0x58, 1).
 */


extern void func_021EC000(char *, unsigned, int);
void func_021ED2F4(char *p)
{
    unsigned i;
    for (i = 0; i < 8; i++)
        func_021EC000(p, i + 0x58, 1);
}
