/*
 * function: func_021BD140
 * address:  0x021BD140
 * packet:   pkt_021BD140
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02047970 0x02047970  arm
 *
 * Tail call to the ARM9 function at 0x02047970, forwarding the first argument.
 */

extern void func_02047970(char *);

void func_021BD140(char *p)
{
    func_02047970(p);
}
