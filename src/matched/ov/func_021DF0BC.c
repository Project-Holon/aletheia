/*
 * function: func_021DF0BC
 * address:  0x021DF0BC
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DF040  0x021DF040  thumb  ov170
 *   func_021ED6E4  0x021ED6E4  thumb  ov170
 *
 * Reset, clear the state, mark the 0x16 field.
 */



extern void func_021DF040(unsigned char *);
extern void func_021ED6E4(unsigned char *, int);
void func_021DF0BC(unsigned char *p)
{
    func_021DF040(p);
    func_021ED6E4(p, 0);
    p[0x16] = 0xff;
}
