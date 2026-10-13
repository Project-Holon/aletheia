/*
 * function: GPOWER_ApplyPrizeMoney
 * address:  0x0201119C
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
 * Same shape as func_02010FF4, mode byte +0x1d, scale +0x14.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_ApplyPrizeMoney.c \
 *       --func GPOWER_ApplyPrizeMoney --addr 0x0201119C --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 g_02146208[];
extern u8 g_02146228[];

u32 GPOWER_ApplyPrizeMoney(u32 v)
{
    if (g_02146208[0x1d] != 0x30)
        v = *(u16 *)(g_02146228 + 0x14) * v / 100;
    return v;
}
