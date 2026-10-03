/*
 * function: func_021887C4
 * address: 0x021887C4
 * packet: pkt_ov096_021887C4
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021887F4 0x021887F4 thumb ov096
 */
extern void func_021887F4(int, int, int);
int func_021887C4(int a, int b)
{
    func_021887F4(a, b, 1);
    return *(int *)((unsigned int)b + 0xc4);
}
