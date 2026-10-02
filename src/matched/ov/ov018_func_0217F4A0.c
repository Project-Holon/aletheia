/*
 * function: func_0217F4A0
 * address: 0x0217F4A0
 * packet: pkt_ov018_0217F4A0
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0217F434 0x0217F434 thumb ov018
 *   func_0217F470 0x0217F470 thumb ov018
 */
extern void func_0217F434(void **);
extern void func_0217F470(void **, void *, void *, unsigned int, int, int);
void func_0217F4A0(void **p, unsigned int index, int a, int b)
{
    func_0217F434(p);
    func_0217F470(p, p[3], p[7], index, a, b);
}
