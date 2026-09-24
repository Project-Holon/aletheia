/*
 * function: func_021EF738
 * address:  0x021EF738
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Stage row 0x20 at channel 9 then patch with -1.
 */


extern void func_0202CB4C(char *, int, int, int);
extern void func_0202CD64(char *, int, int, int, int);
void func_021EF738(char *p)
{
    func_0202CB4C(p, 9, 0x20, 0);
    func_0202CD64(p, 9, -1, 0, 0xb);
}
