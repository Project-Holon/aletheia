/*
 * function: func_021DDE74
 * address: 0x021DDE74
 * packet: pkt_ov093_021DDE74
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DDEA4 0x021DDEA4 thumb ov093
 *   func_021D775C 0x021D775C thumb ov093
 * Interface: C7CF4 returns the live r0 payload and receives observed r1.
 */
extern int func_021DDEA4(void *, int, unsigned int);
extern int func_021D775C(int);

int func_021DDE74(int a, void *b, int c, unsigned int d)
{
    if (c == func_021D775C(2) && (unsigned char)func_021D775C(46) <= 1) return func_021DDEA4(b, c, d);
    return 0;
}
