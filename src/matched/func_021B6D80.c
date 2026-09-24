/*
 * function: func_021B6D80
 * address:  0x021B6D80
 * packet:   pkt_021B6184
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B6D80   0x021B6D80  thumb
 *
 * Read the word at 0x021DC050.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021B6D80.c \
 *       --func func_021B6D80 --addr 0x021B6D80 --region ov016 --cc dsi/1.1p1 --thumb
 */

unsigned int func_021B6D80(void)
{
    unsigned int *p = (unsigned int *)0x021DC040;
    return p[4];
}
