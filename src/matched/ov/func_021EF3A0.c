/*
 * function: func_021EF3A0
 * address:  0x021EF3A0
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
 * Probe the 8-byte tag; unless the tag byte is 0x18, patch the row
 *   with (0x18 - tag) as a flagged close.
 */


extern void func_0202CF98(int, int, char *, char *);
extern void func_0202CD64(int, int, int, int, int);
void func_021EF3A0(int p)
{
    char buf[4];
    func_0202CF98(p, 8, buf + 1, buf);
    if ((signed char)buf[0] != 0x18)
        func_0202CD64(p, 8, 0, 1, (unsigned char)(0x18 - buf[0]));
}
