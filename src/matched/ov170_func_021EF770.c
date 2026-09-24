/*
 * function: func_021EF770
 * address:  0x021EF770
 * packet:   pkt_021EF770
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EF770 0x021EF770 thumb
 *   func_0202CF98 0x0202CF98 thumb
 */

typedef signed char s8;

extern void func_0202CF98(int, int, s8 *, void *);

int func_021EF770(int arg0)
{
    s8 buf[2];
    func_0202CF98(arg0, 9, &buf[1], &buf[0]);
    if (buf[1] == 0x15) {
        return 1;
    }
    return 0;
}
