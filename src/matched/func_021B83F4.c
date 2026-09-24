/*
 * function: func_021B83F4
 * address:  0x021B83F4
 * packet:   pkt_021B83E8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B83F4   0x021B83F4  thumb
 *
 * Store a u32 and a constant u16 into a small record, return 1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021B83F4.c \
 *       --func func_021B83F4 --addr 0x021B83F4 --region ov016 --cc dsi/1.1p1 --thumb
 */

typedef unsigned int u32;
typedef unsigned short u16;

int func_021B83F4(int v, void *rec)
{
    *(u32 *)rec = v;
    *(u16 *)((char *)rec + 4) = 1;
    return 1;
}
