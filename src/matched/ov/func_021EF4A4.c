/*
 * function: func_021EF4A4
 * address:  0x021EF4A4
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
 * Probe the 8-byte tag at the top of the frame; 1 when its first
 *   byte is 6.
 */


extern void func_0202CF98(int, int, char *, char *);
int func_021EF4A4(int p)
{
    char buf[4];
    func_0202CF98(p, 8, buf + 1, buf);
    return buf[0] == 6;
}
