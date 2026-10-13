/*
 * function: AOSS_Strlen
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
 *   AOSS_Strlen   0x021B8364  thumb
 *
 * Length of a NUL-terminated signed-char string.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/AOSS_Strlen.c \
 *       --func AOSS_Strlen --addr 0x021B8364 --region ov016 --cc dsi/1.1p1 --thumb
 */

int AOSS_Strlen(const char *p)
{
    int n = 0;
    while (p[n] != 0)
        n++;
    return n;
}
