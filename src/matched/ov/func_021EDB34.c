/*
 * function: func_021EDB34
 * address:  0x021EDB34
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DEB14  0x021DEB14  thumb  ov170
 *   func_021EDB94  0x021EDB94  thumb  ov170
 *
 * Scan channels -1..4 for the one that reports a; on a hit run the
 *   sub-range call with the channel index.  The compared result must live in a
 *   LOCAL, or mwccarm emits `cmp r5,r0` where the image has `cmp r0,r5`.
 */


extern unsigned char func_021DEB14(char *, signed char);
extern void func_021EDB94(char *p, int a, int b);
void func_021EDB34(char *p, int a)
{
    short i;
    for (i = 0; i < 6; i++) {
        unsigned char c = func_021DEB14(p, (signed char)(i - 1));
        if (c != a)
            continue;
        func_021EDB94(p, a, i);
        return;
    }
}
