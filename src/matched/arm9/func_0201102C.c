/*
 * function: GPOWER_ApplyShopPrice
 * address:  0x0201102C
 * packet:   pkt_0201102C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_02146208      0x02146208  data
 *   g_02146228      0x02146228  data
 *   _u32_div_f      0x0209C2B0  arm
 *
 * Same shape as GPOWER_ApplyHatchRate, mode byte +0x18, scale +0xa.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_ApplyShopPrice.c \
 *       --func GPOWER_ApplyShopPrice --addr 0x0201102C --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 g_02146208[];
extern u8 g_02146228[];

u32 GPOWER_ApplyShopPrice(u32 v)
{
    if (g_02146208[0x18] != 0x30)
        v = *(u16 *)(g_02146228 + 0xa) * v / 100;
    return v;
}
