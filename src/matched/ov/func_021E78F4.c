/*
 * function: func_021E78F4
 * address:  0x021E78F4
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EBC58  0x021EBC58  thumb  ov170
 *
 * Push the 0x16 field through the 0x18 selector; return 75.
 */



extern void func_021EBC58(char *, int, int, int);
int func_021E78F4(char *p)
{
    func_021EBC58(p, (unsigned char)p[0x16], 1, 0x18);
    return 0x4b;
}
