/*
 * function: func_021EF534
 * address:  0x021EF534
 * packet:   pkt_ov170_021EF534
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0202CF98 0x0202CF98 thumb
 *   func_0202CD64 0x0202CD64 thumb
 */

extern void func_0202CF98(int, int, signed char *, signed char *);
extern void func_0202CD64(int mgr, unsigned idx, signed char dx, signed char dy, unsigned char frames);

void func_021EF534(int mgr)
{
    signed char buf[2];
    unsigned short i = 0;
    func_0202CF98(mgr, 0, &buf[1], &buf[0]);
    if (buf[1] == 0x15)
        return;
    for (; i < 6; i++)
        func_0202CD64(mgr, i, -1, 0, buf[1] - 0x15);
}
