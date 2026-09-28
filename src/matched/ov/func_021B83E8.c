/*
 * function: func_021B83E8
 * address:  0x021B83E8
 * packet:   pkt_021B83E8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B83E8   0x021B83E8  thumb
 *
 * Clear a u32 and two u16 fields of a small record.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021B83E8.c \
 *       --func func_021B83E8 --addr 0x021B83E8 --region ov016 --cc dsi/1.1p1 --thumb
 */

typedef unsigned int u32;
typedef unsigned short u16;

void func_021B83E8(void *rec)
{
    *(u32 *)rec = 0;
    *(u16 *)((char *)rec + 4) = 0;
    *(u16 *)((char *)rec + 6) = 0;
}
