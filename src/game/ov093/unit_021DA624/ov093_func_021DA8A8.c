/*
 * function: func_021DA8A8
 * address: 0x021DA8A8
 * packet: pkt_ov093_021DA8A8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte alignment padding.
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 */
extern int func_021D775C(int);
extern int func_021D76BC(int, unsigned int);

int func_021DA8A8(int a, int b, int c)
{
    if (b == func_021D775C(4) && b != func_021D775C(3) && c == func_021D775C(0x16))
        return func_021D76BC(0x40, 1);
    return 0;
}
