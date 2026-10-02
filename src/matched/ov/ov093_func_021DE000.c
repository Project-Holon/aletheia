/*
 * function: func_021DE000
 * address: 0x021DE000
 * packet: pkt_ov093_021DE000
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021DDFDC 0x021DDFDC thumb ov093
 * Interface: C7CF4 returns the live r0 payload and receives observed r1.
 */
extern int func_021D775C(int);
extern void func_021DDFDC(int, void *, int, int);

void func_021DE000(int a, void *b, int c, int d)
{
    if (func_021D775C(12) != 6) func_021DDFDC(a, b, c, d);
}
