/*
 * function: func_021D5FE8
 * address:  0x021D5FE8
 * packet:   pkt_021D5FE8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D5FE8   0x021D5FE8  arm
 *
 * Write two halfwords through the out pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D5FE8.c \
 *       --func func_021D5FE8 --addr 0x021D5FE8 --region ov016 --cc dsi/1.1p1 --arm
 */

void func_021D5FE8(int a, int b, unsigned short *p)
{
    p[0] = a;
    p[1] = b;
}
