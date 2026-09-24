/*
 * function: func_021EF480
 * address:  0x021EF480
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
 * Same probe as func_021EF45C with tag byte 1 compared to 2.
 */


extern void func_0202CF98(int, int, char *, char *);
int func_021EF480(int p)
{
    char buf[4];
    func_0202CF98(p, 8, buf + 1, buf);
    return buf[1] == 0x2 && buf[0] == 6;
}
