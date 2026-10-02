/*
 * function: func_021D9648
 * address: 0x021D9648
 * packet: pkt_ov093_021D9648
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 */
extern int func_021D775C(int);
extern int func_021D76BC(int, unsigned int);
int func_021D9648(int a, int b, int c)
{
    if (b == func_021D775C(4) && c == func_021D775C(0x1d))
        return func_021D76BC(0x41, 1);
    return 0;
}
