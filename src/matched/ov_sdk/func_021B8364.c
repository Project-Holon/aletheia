/*
 * function: func_021B8364
 * address:  0x021B8364
 * packet:   pkt_021B82C8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8364   0x021B8364  thumb
 *
 * Length of a NUL-terminated signed-char string.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021B8364.c \
 *       --func func_021B8364 --addr 0x021B8364 --region ov016 --cc dsi/1.1p1 --thumb
 */

int func_021B8364(const char *p)
{
    int n = 0;
    while (p[n] != 0)
        n++;
    return n;
}
