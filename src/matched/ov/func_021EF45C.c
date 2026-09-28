/*
 * function: func_021EF45C
 * address:  0x021EF45C
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
 * Read the 8-byte tag at the top of the frame; 1 when byte 1 is
 *   0x15 and byte 0 is 6.
 */


extern void func_0202CF98(int, int, char *, char *);
int func_021EF45C(int p)
{
    char buf[4];
    func_0202CF98(p, 8, buf + 1, buf);
    return buf[1] == 0x15 && buf[0] == 6;
}
