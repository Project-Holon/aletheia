/*
 * function: func_021B796C
 * address:  0x021B796C
 * packet:   pkt_021B796C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B796C   0x021B796C  thumb
 *
 * Return 1 when bit 4 of the argument is set, else 0.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021B796C.c \
 *       --func func_021B796C --addr 0x021B796C --region ov016 --cc dsi/1.1p1 --thumb
 */

int func_021B796C(unsigned int v)
{
    int r = 0;
    if (v & 0x10)
        r = 1;
    return r;
}
