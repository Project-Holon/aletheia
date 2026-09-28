/*
 * function: func_021B6184
 * address:  0x021B6184
 * packet:   pkt_021B6184
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B6184   0x021B6184  thumb
 *
 * Call func_02087BCC with 0, then return 1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021B6184.c \
 *       --func func_021B6184 --addr 0x021B6184 --region ov016 --cc dsi/1.1p1 --thumb
 */

extern void func_02087BCC(unsigned int);

int func_021B6184(void)
{
    func_02087BCC(0);
    return 1;
}
