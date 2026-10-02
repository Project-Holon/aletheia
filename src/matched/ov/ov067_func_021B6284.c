/*
 * function: func_021B6284
 * address: 0x021B6284
 * packet: pkt_ov067_021B6284
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
extern void func_0204ADA4(unsigned int i);
extern void func_0204A8D4(unsigned int i);
extern void func_0204AFD8(unsigned int i);

void func_021B6284(unsigned int *p)
{
    func_0204ADA4(p[1]);
    func_0204A8D4(p[0]);
    func_0204AFD8(p[2]);
}
