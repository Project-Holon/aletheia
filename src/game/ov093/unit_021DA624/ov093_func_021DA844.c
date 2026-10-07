/*
 * function: func_021DA844
 * address: 0x021DA844
 * packet: pkt_ov093_021DA844
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 */
extern int func_021D775C(int);
extern void func_021D7704(int, int);

void func_021DA844(int a, int b, int c)
{
    int k = 4;
    if (c == func_021D775C(k) && func_021D775C(0x16) == 9)
        func_021D7704(0x31, k << 9);
}
