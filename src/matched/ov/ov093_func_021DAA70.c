/*
 * function: func_021DAA70
 * address: 0x021DAA70
 * packet: pkt_ov093_021DAA70
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

void func_021DAA70(int a, int b, int c)
{
    if (c == func_021D775C(4) && func_021D775C(0x16) == 9)
        func_021D7704(0x31, 5 << 10);
}
