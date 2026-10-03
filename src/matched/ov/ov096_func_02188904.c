/*
 * function: func_02188904
 * address: 0x02188904
 * packet: pkt_ov096_02188904
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02188924 0x02188924 thumb ov096
 */
extern void func_02188924(int, int, int);
int func_02188904(int a, int b)
{
    func_02188924(a, b, 2);
    return *(int *)(b + 0xc4);
}
