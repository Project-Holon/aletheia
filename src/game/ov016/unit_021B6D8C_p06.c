/*
 * file:     unit_021B6D8C_p06.c
 * unit:     yes
 * function: func_021B8230
 * address:  0x021B8230
 * packet:   pkt_021B8230
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8230   0x021B8230  thumb
 *   func_02082D44   0x02082D44  arm  arm9

 *
 * Tail-call func_02082D44 with the first two arguments swapped.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021B8230.c \
 *       --func func_021B8230 --addr 0x021B8230 --region ov016 --cc dsi/1.1p1 --thumb
 */

extern void func_02082D44(unsigned int, unsigned int, unsigned int);

void func_021B8230(unsigned int a, unsigned int b, unsigned int c)
{
    func_02082D44(b, a, c);
}
