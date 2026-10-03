/*
 * function: func_021888AC
 * address: 0x021888AC
 * packet: pkt_ov096_021888AC
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021888BC 0x021888BC thumb ov096
 */
extern void func_021888BC(int, int, int);
int func_021888AC(int a, int b)
{
    func_021888BC(a, b, 3);
    return *(int *)((unsigned int)b + 0xc4);
}
