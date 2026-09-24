/*
 * function: func_021EF60C
 * address:  0x021EF60C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * 1 when the tag's byte 1 is 0x15.
 */


extern void func_0202CF98(int, int, char *, char *);
int func_021EF60C(int p)
{
    char buf[4];
    func_0202CF98(p, 0, buf + 1, buf);
    return buf[1] == 0x15;
}
