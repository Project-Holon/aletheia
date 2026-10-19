/*
 * function: MY_MD5Init
 * address:  0x021BBB98
 * packet:   pkt_021BBB98
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MY_MD5Init   0x021BBB98  thumb
 *
 * MD5 initial state into the first six words of the context.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MY_MD5Init.c \
 *       --func MY_MD5Init --addr 0x021BBB98 --region ov016 --cc dsi/1.1p1 --thumb
 */

void MY_MD5Init(unsigned int *p)
{
    p[5] = 0;
    p[4] = 0;
    p[0] = 0x67452301;
    p[1] = 0xefcdab89;
    p[2] = 0x98badcfe;
    p[3] = 0x10325476;
}
