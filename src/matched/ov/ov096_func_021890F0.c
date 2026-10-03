/*
 * function: func_021890F0
 * address: 0x021890F0
 * packet: pkt_ov096_021890F0
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02189100 0x02189100 thumb ov096
 */
extern void func_02189100(int, int, int);
int func_021890F0(int a, int b)
{
    func_02189100(a, b, 3);
    return *(int *)(b + 0xc4);
}
