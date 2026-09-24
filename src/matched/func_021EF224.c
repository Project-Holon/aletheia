/*
 * function: func_021EF224
 * address:  0x021EF224
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EF108  0x021EF108  thumb  ov170
 *
 * Query the 0x021F1174 table with index 4; -1 becomes 0xff,
 *   otherwise the answer plus 0x24.  The -1 arm must be the branch target.
 */


extern int func_021EF108(char *, int, int, int);
int func_021EF224(int a, int b)
{
    int v = func_021EF108((char *)0x021F1174, 4, a, b);
    if (v != -1)
        return v + 0x24;
    return 0xff;
}
