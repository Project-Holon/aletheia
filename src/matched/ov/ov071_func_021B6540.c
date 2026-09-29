/*
 * function: func_021B6540
 * address:  0x021B6540
 * packet:   pkt_ov071_021B6540
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02021518  0x02021518  thumb
 *   func_0202155C  0x0202155C  thumb
 *   func_02021EE4  0x02021EE4  thumb
 */

void func_021B6540(int *p)
{
    int func_02021518(int);
    void func_0202155C(int, int, int, int);
    void func_02021EE4(int, int);

    *p = func_02021518(0x61);
    func_0202155C(*p, 2, 0x1c0, 0x61);
    func_0202155C(*p, 3, 0x1c0, 0x61);
    func_0202155C(*p, 0, 0x1c0, 0x61);
    func_0202155C(*p, 1, 0x1c0, 0x61);
    func_02021EE4(*p, 1);
}
