/*
 * function: ascii2hex
 * address:  0x021CFEA0
 * packet:   pkt_021CF440
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   ascii2hex   0x021CFEA0  arm
 *
 * Value of one ASCII hex digit.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ascii2hex.c \
 *       --func ascii2hex --addr 0x021CFEA0 --region ov016 --cc dsi/1.1p1 --arm
 */

int ascii2hex(unsigned int c)
{
    if (c <= 0x39)
        return c - 0x30;
    if (c <= 0x46)
        return c - 0x37;
    return c - 0x57;
}
