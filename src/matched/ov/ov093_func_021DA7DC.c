/*
 * function: func_021DA7DC
 * address: 0x021DA7DC
 * packet: pkt_ov093_021DA7DC
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

void func_021DA7DC(int a, int b, int c)
{
    if (c == func_021D775C(3)) {
        func_021D76BC(0x28, 6);
        return;
    }
    if (c == func_021D775C(4))
        func_021D76BC(0x27, 6);
}
