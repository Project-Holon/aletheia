/*
 * function: func_02189150
 * address: 0x02189150
 * packet: pkt_ov096_02189150
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02189170 0x02189170 thumb ov096
 */
extern void func_02189170(int, int, int);
int func_02189150(int a, int b)
{
    func_02189170(a, b, 6);
    return *(int *)(b + 0xc4);
}
