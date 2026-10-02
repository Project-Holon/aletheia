/*
 * function: func_021DDFDC
 * address: 0x021DDFDC
 * packet: pkt_ov093_021DDFDC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021DE024 0x021DE024 thumb ov093
 * Interface: C7CF4 returns the live r0 payload and receives observed r1.
 */
extern int func_021D775C(int);
extern void func_021DE024(int, void *, int, int);

void func_021DDFDC(int a, void *b, int c, int d)
{
    if (c == func_021D775C(2)) func_021DE024(a, b, c, d);
}
