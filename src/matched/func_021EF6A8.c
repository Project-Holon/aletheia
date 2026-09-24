/*
 * function: func_021EF6A8
 * address:  0x021EF6A8
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
 * Stage rows 0x15/0x18 at channel 7 then patch with -1.
 */


extern void func_0202CB4C(char *, int, int, int);
extern void func_0202CD64(char *, int, int, int, int);
void func_021EF6A8(char *p)
{
    func_0202CB4C(p, 7, 0x15, 0x18);
    func_0202CD64(p, 7, 0, -1, 0x13);
}
