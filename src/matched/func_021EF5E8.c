/*
 * function: func_021EF5E8
 * address:  0x021EF5E8
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
 * 1 unless the tag's byte 1 is 0x20.
 */


extern void func_0202CF98(int, int, char *, char *);
int func_021EF5E8(int p)
{
    char buf[4];
    func_0202CF98(p, 0, buf + 1, buf);
    return buf[1] != 0x20;
}
