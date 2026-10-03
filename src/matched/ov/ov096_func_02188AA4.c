/*
 * function: func_02188AA4
 * address: 0x02188AA4
 * packet: pkt_ov096_02188AA4
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02188AB4 0x02188AB4 thumb ov096
 */
extern void func_02188AB4(int, int, int);
int func_02188AA4(int a, int b)
{
    func_02188AB4(a, b, 5);
    return *(int *)(b + 0xc4);
}
