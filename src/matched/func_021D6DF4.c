/*
 * function: func_021D6DF4
 * address:  0x021D6DF4
 * packet:   pkt_021D6DF4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D6DF4   0x021D6DF4  arm
 *
 * Tail-call func_021D6DC4 with the argument advanced by 8.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D6DF4.c \
 *       --func func_021D6DF4 --addr 0x021D6DF4 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021D6DC4(void *);

void func_021D6DF4(char *p)
{
    func_021D6DC4(p + 8);
}
