/*
 * function: func_021DA03C
 * address:  0x021DA03C
 * packet:   pkt_021DA03C
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020221A4  0x020221A4  thumb
 *   func_021DA034  0x021DA034  thumb
 *
 * Addresses are Black-image addresses.
 */

extern int func_020221A4(char *);
extern void func_021DA034(char *, int, int);

void func_021DA03C(char *p)
{
    if (func_020221A4(p) != 0)
        func_021DA034(p, 0, 0xd5);
}
