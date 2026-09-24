/*
 * function: func_021B6D74
 * address:  0x021B6D74
 * packet:   pkt_021B6184
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B6D74   0x021B6D74  thumb
 *
 * Store a word at 0x021DC050.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021B6D74.c \
 *       --func func_021B6D74 --addr 0x021B6D74 --region ov016 --cc dsi/1.1p1 --thumb
 */

void func_021B6D74(unsigned int v)
{
    unsigned int *p = (unsigned int *)0x021DC040;
    p[4] = v;
}
